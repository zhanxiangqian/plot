#include "mainWindow.h"

DemoWindow::DemoWindow() : QMainWindow(NULL)
{
	ui.setupUi(this);
	m_centralWidget = new QtGnuplotWindow(1);
	setCentralWidget(m_centralWidget);
	m_settingsWidget = new SettingsWidget();
	connect(ui.actionOpen, &QAction::triggered, this, &DemoWindow::onOpen);
}

DemoWindow::~DemoWindow()
{
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
