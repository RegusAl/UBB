//#include "Lab_10.h"
#include <QtWidgets/QApplication>
#include "OfertaStoreGUI.h"
#include "CosCRUDGUI.h"
#include "Teste.h"
#include "CosReadOnlyGUI.h"

#include <stdlib.h>
//#include <crtdbg.h>
#include <iostream>
using std::cout;
using std::endl;


#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/qlistwidget.h>
#include <QtWidgets/qtablewidget.h>
#include <QtWidgets/qmessagebox.h>
#include <qlist.h>
#include "StoreGUIModele.h"
#include <string>
#include <list>

#include <QTreeView>
//#include <QDirModel>
#include <QListView>
#include <QStringListModel>
#include <QVBoxLayout>
#include <QComboBox>
#include <qdebug.h>

int ROWS = 10000;
int COLS = 100;



int main(int argc, char* argv[])
{
	OfertaRepoFile rep{ "oferte.txt" };
	Validator val;
	OfertaStore ctr{ rep , val};
	QApplication a(argc, argv);
	StoreGUIModele gui{ ctr };
	gui.show();
	return a.exec();

}

