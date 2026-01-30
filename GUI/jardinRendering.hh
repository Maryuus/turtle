#ifndef JARDINRENDERING_HH
#define JARDINRENDERING_HH

#include <string>

// Structure simple pour gérer des coordonnées précises
struct PointF {
    float x;
    float y;
};

class JardinRendering {
public:
    virtual ~JardinRendering() {};

    virtual void construction(std::string nom) = 0;
    virtual int nombreTortues() = 0;

    // ON UTILISE MAINTENANT PointF (float) ET NON QPoint (int)
    virtual PointF position(int id) = 0;
    virtual float orientation(int id) = 0;

    virtual void changePosition(int id, float x, float y) = 0;
    virtual void changeOrientation(int id, float angle) = 0;
    virtual void changeCouleur(int id, int r, int g, int b) = 0;

    virtual void dessinerLigne(float x1, float y1, float x2, float y2) = 0;
    virtual void changerCouleur(int r, int g, int b) = 0;

    virtual bool estMur(int x, int y) = 0;
    virtual bool estVide(int x, int y) = 0;
};

#endif
