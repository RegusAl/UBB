#include <QApplication>
#include <QPushButton>

#include "repository.h"
#include "service.h"
#include "GUI.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Repository repository{"/home/albert/Documents/UBB/Semestrul 2/Programare orientata obiect/Pregatire_Sesiune/Produse/input.txt"};
    Service service{repository};
    GUI gui{service};
    gui.run();
    return QApplication::exec();
}
