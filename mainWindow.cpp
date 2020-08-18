#include "mainWindow.h"
#include "QtGnuplotWidget.h"
#include <QDebug>

DemoWindow::DemoWindow() : QMainWindow(NULL)
{
	ui.setupUi(this);
	m_centralWidget = new QtGnuplotWindow(1);
	setCentralWidget(m_centralWidget);
	m_settingsWidget = new SettingsWidget();
	m_settingsWidget->setPlotWidget(m_centralWidget->m_widget);
	connect(ui.actionOpen, &QAction::triggered, this, &DemoWindow::onOpen);
	connect(m_settingsWidget, &SettingsWidget::plotAction, this, &DemoWindow::onPlotAction);
	
}

void DemoWindow::testPlot()
{
	m_centralWidget->testPlot();
}

DemoWindow::~DemoWindow()
{
}

void DemoWindow::onPlotAction()
{
	//m_centralWidget->m_widget->activateWindow();
	//m_centralWidget->m_widget->raise();
	//m_centralWidget->m_widget->rePlot();
	//connect(m_centralWidget->m_widget, &QtGnuplotWidget::plotDone, this, &DemoWindow::onPlotAction);
}

void DemoWindow::onOpen()
{
	QtGnuplotInstance* pGn = QtGnuplotInstance::getInstance("");

	if (!pGn->widget())
	{
		pGn->setWidget(m_centralWidget->m_widget);
	}
	m_settingsWidget->show();

}
