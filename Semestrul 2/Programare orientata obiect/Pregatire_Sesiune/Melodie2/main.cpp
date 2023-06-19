#include <QApplication>
#include <QPushButton>

#include "teste.h"
#include "repository.h"
#include "service.h"
#include "GUI.h"

int main(int argc, char *argv[]) {
    test_repo();
    test_service();
    QApplication a(argc, argv);
    Repository repo{"/home/albert/Documents/UBB/Semestrul 2/Programare orientata obiect/Pregatire_Sesiune/Melodie2/input.txt"};
    Service service{repo};
    GUI gui{service};
    gui.show();
    return QApplication::exec();
}
