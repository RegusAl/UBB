#include <QApplication>
#include <QPushButton>

#include "teste.h"

#include "GUI.h"

int main(int argc, char *argv[]) {
    test_repository();
    test_service();
    QApplication a(argc, argv);
//    QPushButton button("Hello world!", nullptr);
//    button.resize(200, 100);
//    button.show();
    Repository repository{"/home/albert/Documents/UBB/Semestrul 2/Programare orientata obiect/SESIUNE_PRACTIC/taskFile.txt"};
    Service service{repository};
    GUI gui{service};
    gui.show();
    return QApplication::exec();
}
