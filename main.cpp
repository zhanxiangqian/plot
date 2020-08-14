#include <QtCore>
#include <QtGui>
#include <QWidget>
#include "mainWindow.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	DemoWindow* mainWindow = new DemoWindow();
	mainWindow->show();
	app.exec();
	return 0;
}
