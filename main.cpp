#include <QtCore>
#include <QtGui>
#include <QWidget>
#include "mainWindow.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	DemoWindow* mainWindow = new DemoWindow();

	//QtGnuplotWindow* mainWindow = new QtGnuplotWindow(1);

	mainWindow->show();
	//mainWindow->testPlot();
	app.exec();
	return 0;
}
