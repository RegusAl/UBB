#include <QApplication>
#include <QPushButton>
#include "teste.h"
#include "repo.h"
#include "service.h"
#include "GUI.h"

int main(int argc, char *argv[]) {
    test_domain();
    test_repo();
    test_service();
    QApplication a(argc, argv);
    Repo repo{"/home/albert/Documents/UBB/Semestrul 2/Programare orientata obiect/Pregatire_Sesiune/Melodie1/input.txt"};
    Service service{repo};
    GUI gui{service};
    gui.show();
    return QApplication::exec();
}
