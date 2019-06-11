#include "QTcpServerDemo.h"
#include <QtWidgets/QApplication>
#include "DMMServer.h"
#include "DMMThread.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QTcpServerDemo w;
	w.show();

	DMMThread dm(&w);
	dm.start();

	return a.exec();
}
