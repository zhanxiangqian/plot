#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include "QtGnuplotWindow.h"
#include "ui_mainWindow.h"
#include "settingsWidget.h"

class DemoWindow : public QMainWindow
{
	Q_OBJECT
public:
	DemoWindow();
	~DemoWindow();
	void testPlot();
private slots:
	void onOpen();
	void onPlotAction();
private:
	Ui::MainWindow ui;
	QtGnuplotWindow* m_centralWidget;
	SettingsWidget*  m_settingsWidget;
};



#endif
