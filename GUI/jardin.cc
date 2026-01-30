#include "jardin.hh"
#include "jardinHandler.hh"
#include <iostream>
#include <fstream>
#include <cmath>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QPainter>
#include <QDir>

const int TILE_SIZE = 40;

Jardin::Jardin(const std::string & titre, QWidget *parent)
: QWidget(parent), m_couleurCrayon(Qt::yellow), m_largeur(20), m_hauteur(15)
{
    setWindowTitle(QString::fromStdString(titre.empty() ? "Tortue - Projet" : titre));
    m_handler = new JardinHandler(this);

    // Chargement Images
    m_imgMur.load("GUI/IMG/mur.jpg");
    // On a renommé vide.jpg en .bak pour avoir le gris clair, mais on laisse le code générique
    if(QFile::exists("GUI/IMG/vide.jpg")) m_imgVide.load("GUI/IMG/vide.jpg");
    m_imgTortue.load("GUI/IMG/tortue.png");

    if(!m_imgMur.isNull()) m_imgMur = m_imgMur.scaled(TILE_SIZE, TILE_SIZE);
    if(!m_imgVide.isNull()) m_imgVide = m_imgVide.scaled(TILE_SIZE, TILE_SIZE);
    if(!m_imgTortue.isNull()) m_imgTortue = m_imgTortue.scaled(TILE_SIZE, TILE_SIZE, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    resize(m_largeur * TILE_SIZE, m_hauteur * TILE_SIZE);
    m_grille.resize(m_hauteur, std::vector<TypeCase>(m_largeur, TypeCase::VIDE));

    // Tortue par défaut
    TortueInfo t; t.x=0; t.y=0; t.angle=-90; t.couleur=Qt::red; t.visible=true;
    m_tortues.push_back(t);

    m_calqueDessin = QPixmap(size());
    m_calqueDessin.fill(Qt::transparent);
}

JardinHandler* Jardin::getHandler() { return m_handler; }

// --- LECTURE DU FICHIER JARDIN ---
void Jardin::construction(std::string nom) {
    std::cout << "[Jardin] Lecture du fichier : " << nom << std::endl;
    std::ifstream file(nom);
    if (!file.is_open()) {
        std::cerr << "Impossible d'ouvrir " << nom << std::endl;
        return;
    }

    // 1. Lire les dimensions
    file >> m_largeur >> m_hauteur;

    // "Manger" le retour à la ligne après les dimensions
    std::string dummy;
    std::getline(file, dummy);

    // Reset de la grille
    m_grille.clear();
    m_grille.resize(m_hauteur, std::vector<TypeCase>(m_largeur, TypeCase::VIDE));
    m_tortues.clear();

    // 2. Lecture LIGNE par LIGNE
    for(int y = 0; y < m_hauteur; ++y) {
        std::string ligne;
        std::getline(file, ligne);

        for(int x = 0; x < m_largeur; ++x) {
            char c = (x < (int)ligne.size()) ? ligne[x] : ' ';

            if (c == 'M' || c == '*') {
                m_grille[y][x] = TypeCase::MUR;
            } else if (c == 'T') {
                m_grille[y][x] = TypeCase::VIDE;
                // Création d'une tortue trouvée sur la carte
                TortueInfo t;
                t.x = x; t.y = y; t.angle = -90;
                t.couleur = Qt::red;
                t.visible = true;
                m_tortues.push_back(t);
            } else {
                m_grille[y][x] = TypeCase::VIDE;
            }
        }
    }

    // Tortue de secours si aucune n'est trouvée
    if (m_tortues.empty()) {
        TortueInfo t; t.x=0; t.y=0; t.angle=-90; t.couleur=Qt::red; t.visible=true;
        m_tortues.push_back(t);
    }

    // Redimensionnement graphique
    resize(m_largeur * TILE_SIZE, m_hauteur * TILE_SIZE);

    // Reset du calque de dessin
    m_calqueDessin = QPixmap(size());
    m_calqueDessin.fill(Qt::transparent);

    update();
}

int Jardin::nombreTortues() { return m_tortues.size(); }
PointF Jardin::position(int id) {
    if(id < 0 || id >= (int)m_tortues.size()) return {0.0f, 0.0f};
    return {m_tortues[id].x, m_tortues[id].y};
}
float Jardin::orientation(int id) {
    if(id < 0 || id >= (int)m_tortues.size()) return 0.0f;
    return m_tortues[id].angle;
}
void Jardin::changePosition(int id, float x, float y) {
    if(id < 0 || id >= (int)m_tortues.size()) return;
    float oldX = m_tortues[id].x; float oldY = m_tortues[id].y;
    m_tortues[id].x = x; m_tortues[id].y = y;
    dessinerLigne(oldX, oldY, x, y);
    update();
}
void Jardin::changeOrientation(int id, float angle) {
    if(id < 0 || id >= (int)m_tortues.size()) return;
    m_tortues[id].angle = angle;
    update();
}
void Jardin::changeCouleur(int id, int r, int g, int b) {
    if(id < 0 || id >= (int)m_tortues.size()) return;
    m_tortues[id].couleur = QColor(r,g,b);
}
bool Jardin::estMur(int x, int y) {
    if (x < 0 || x >= m_largeur || y < 0 || y >= m_hauteur) return true;
    return m_grille[y][x] == TypeCase::MUR;
}
bool Jardin::estVide(int x, int y) { return !estMur(x, y); }
void Jardin::changerCouleur(int r, int g, int b) { m_couleurCrayon = QColor(r, g, b); }

void Jardin::dessinerLigne(float x1, float y1, float x2, float y2) {
    QPainter painter(&m_calqueDessin);
    QPen pen;
    pen.setColor(m_couleurCrayon);
    pen.setWidth(3);
    painter.setPen(pen);
    painter.setRenderHint(QPainter::Antialiasing);

    float center = TILE_SIZE / 2.0f;
    painter.drawLine(x1 * TILE_SIZE + center, y1 * TILE_SIZE + center,
                     x2 * TILE_SIZE + center, y2 * TILE_SIZE + center);
}

void Jardin::resizeEvent(QResizeEvent *event) {
    if (m_calqueDessin.size() != event->size()) {
        QPixmap newBuffer(event->size());
        newBuffer.fill(Qt::transparent);
        QPainter p(&newBuffer);
        p.drawPixmap(0, 0, m_calqueDessin);
        m_calqueDessin = newBuffer;
    }
    QWidget::resizeEvent(event);
}

void Jardin::paintEvent(QPaintEvent *) {
    QPainter painter(this);

    // 1. DESSIN DU FOND (Grille)
    for(int y=0; y<m_hauteur; ++y) {
        for(int x=0; x<m_largeur; ++x) {
            QRect rect(x*TILE_SIZE, y*TILE_SIZE, TILE_SIZE, TILE_SIZE);

            if (m_grille[y][x] == TypeCase::MUR) {
                if (!m_imgMur.isNull()) painter.drawPixmap(rect, m_imgMur);
                else painter.fillRect(rect, QColor(80, 80, 80));
            } else {
                if (!m_imgVide.isNull()) painter.drawPixmap(rect, m_imgVide);
                else painter.fillRect(rect, QColor(220, 220, 220));
            }
            // Grille légère
            painter.setPen(QColor(180, 180, 180));
            painter.drawRect(rect);
        }
    }

    // 2. DESSIN DES TRAITS
    painter.drawPixmap(0, 0, m_calqueDessin);

    // 3. DESSIN DES TORTUES
    float center = TILE_SIZE / 2.0f;
    for(const auto & t : m_tortues) {
        painter.save();
        painter.translate(t.x * TILE_SIZE + center, t.y * TILE_SIZE + center);
        painter.rotate(t.angle + 90);

        if (!m_imgTortue.isNull()) {
            painter.drawPixmap(-center, -center, m_imgTortue);
        } else {
            // Fallback visuel
            painter.setBrush(t.couleur);
            painter.setPen(Qt::black);
            painter.drawEllipse(-12, -12, 24, 24);
            painter.drawLine(0, 0, 0, -20);
        }
        painter.restore();
    }
}

// --- AJOUT DE LA FONCTION MANQUANTE ---
void Jardin::nouvelleTortue() {
    TortueInfo t;
    t.x = 0.0f;       // Commence à gauche (0,0)
    t.y = 0.0f;
    t.angle = -90.0f; // Regarde vers le haut
    t.couleur = Qt::red;
    t.visible = true;

    m_tortues.push_back(t);
    update(); // Rafraichissement
}
