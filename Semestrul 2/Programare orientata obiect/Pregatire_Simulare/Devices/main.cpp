#include <QtWidgets/QApplication>
#include <QLabel>
#include "qdebug.h"

#include "repository.h"
#include "service.h"
#include "GUI.h"

int main(int argc, char ** argv) {
    QApplication a(argc, argv);

    Repository repo{"/home/albert/Documents/UBB/Semestrul 2/Programare orientata obiect/Pregatire_Simulare/Devices/deviceuri.txt"};
    Service service{repo};
    GUI gui{service};
    gui.show();
    QApplication::exec();
}