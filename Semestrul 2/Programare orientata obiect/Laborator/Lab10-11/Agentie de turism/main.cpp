#include <QtWidgets/QApplication>
#include <QLabel>
#include "consola.h"
#include "OfertaRepo.h"
#include "AgentieService.h"
#include "Validator.h"
#include "teste.h"
#include "OfertaStoreGUI.h"


int main(int argc, char *argv[]) {
    test_all();
    QApplication a(argc, argv);
    string fileName = "/home/albert/Documents/UBB/Semestrul 2/Programare orientata obiect/Laborator/Lab10-11/Agentie de turism/oferte.txt";
    OfertaRepoFile repo{fileName};
    // RepoLab repolab;
    // repolab.setProbabilitate(1); // probabilitate [0, 1]
    // OfertaRepo repo;
    Validator valid;
    CosOferte cos;
    AgentieService service{repo, valid, cos};
    OfertaStoreGUI gui {service};
//    Consola ui{service};
//    ui.run();
    gui.show();
    return a.exec();
}
