#include <QApplication>
#include <QPushButton>

#include "repository.h"
#include "service.h"
#include "GUI.h"
#include "teste.h"

int main(int argc, char *argv[]) {
    test_repository();
    test_service();
    QApplication a(argc, argv);
    Repository repository{"/home/albert/Documents/UBB/Semestrul 2/Programare orientata obiect/Pregatire_Sesiune/App/input.txt"};
    Service service{repository};
    GUI gui{service};
    gui.show();
    return QApplication::exec();
}
