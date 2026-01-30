#include <QApplication>
#include <QTimer>
#include <iostream>
#include <fstream>

#include "driver.hh"
#include "jardinHandler.hh"
#include "GUI/jardin.hh"
#include "scanner.hh"
#include "parser.hh"

struct Context {
    std::string filename;
    JardinHandler* handler;
};

void lancerAnalyse(Context* ctx) {
    std::cout << "--- DÉBUT DU DESSIN ---" << std::endl;
    Driver driver(ctx->handler);
    std::ifstream fichier(ctx->filename);
    if (!fichier.is_open()) {
        std::cerr << "Impossible d'ouvrir le fichier !" << std::endl;
        return;
    }
    Scanner scanner(fichier, std::cout);
    yy::Parser parser(scanner, driver);
    parser.parse();
    std::cout << "--- DESSIN TERMINÉ ---" << std::endl;
    delete ctx;
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    if (argc < 2) {
        std::cerr << "Usage: ./tortue <fichier_script>" << std::endl;
        return 1;
    }
    Jardin * window = new Jardin("");
    window->resize(800, 600);
    window->show();
    Context* ctx = new Context;
    ctx->filename = argv[1];
    ctx->handler = window->getHandler();
    QTimer::singleShot(200, [ctx](){ lancerAnalyse(ctx); });
    return app.exec();
}
