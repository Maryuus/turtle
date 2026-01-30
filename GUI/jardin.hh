#ifndef JARDIN_HH
#define JARDIN_HH

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <vector>
#include <string>
#include "jardinRendering.hh"

class JardinHandler;

struct TortueInfo {
    float x, y; // Position en coordonnées logiques (cases)
    float angle;
    QColor couleur;
    bool visible;
};

// Type de case pour la grille
enum class TypeCase { VIDE, MUR };

class Jardin : public QWidget, public JardinRendering {
    Q_OBJECT

public:
    explicit Jardin(const std::string & titre, QWidget *parent = nullptr);
    ~Jardin() {}

    // --- Implémentation JardinRendering ---
    void construction(std::string nom) override;
    int nombreTortues() override;

    // --- LIGNE AJOUTÉE ICI ---
    void nouvelleTortue() override;
    // -------------------------

    PointF position(int id) override;
    float orientation(int id) override;
    void changePosition(int id, float x, float y) override;
    void changeOrientation(int id, float angle) override;
    void changeCouleur(int id, int r, int g, int b) override;

    void dessinerLigne(float x1, float y1, float x2, float y2) override;
    void changerCouleur(int r, int g, int b) override;

    bool estMur(int x, int y) override;
    bool estVide(int x, int y) override;

    JardinHandler* getHandler();

protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    QPixmap m_calqueDessin;
    QPixmap m_imgMur;
    QPixmap m_imgVide;
    QPixmap m_imgTortue;

    JardinHandler* m_handler;
    QColor m_couleurCrayon;

    int m_largeur;
    int m_hauteur;
    std::vector<std::vector<TypeCase>> m_grille;
    std::vector<TortueInfo> m_tortues;
};

#endif
