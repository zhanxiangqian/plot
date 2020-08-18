#include "settingsWidget.h"
#include "QtGnuplotInstance.h"
#include "QtGnuplotWidget.h"
#include <QFileDialog>
#include <QByteArray>
#include <QMutex>
//QStringList g_Commands;
//QMutex	    g_Mutex;

SettingsWidget::SettingsWidget(QWidget* parent) : QWidget(parent)
{
	ui.setupUi(this);
	connect(ui.pushButtonOpen, &QPushButton::clicked, this, &SettingsWidget::onOpen);
	connect(ui.pushButtonPlot, &QPushButton::clicked, this, &SettingsWidget::onPlot);
	connect(ui.xAxis, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(onXAxisChanged(const QString&)));
	connect(ui.yAxis, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(onYAxisChanged(const QString&)));
	connect(ui.lineType, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(onLineTypeChanged(const QString&)));
}

void SettingsWidget::reset()
{

}


void SettingsWidget::onOpen()
{
	QString fileName = QFileDialog::getOpenFileName(this,
		tr("Open Image"), QDir::currentPath(), tr("Image Files (*.csv)"));
	m_fileName = fileName;
	ui.lineEditFileName->setText(m_fileName);
	QFile file(fileName);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;

	while (!file.atEnd()) {
		QByteArray line = file.readLine();
		QString firstLine(line);//only one line
		QStringList names = firstLine.split(",");
		ui.xAxis->clear();
		ui.xAxis->addItems(names);
		ui.yAxis->clear();
		ui.yAxis->addItems(names);
		ui.lineType->clear();
		ui.lineType->addItems(QStringList() << "lines" << "points");
		file.close();
		break;
	}
	m_plotDone = false;
}

void SettingsWidget::setPlotWidget(QtGnuplotWidget* target)
{
	m_target = target;
	connect(m_target, &QtGnuplotWidget::plotDone, this, &SettingsWidget::onPlotDone);
}


void SettingsWidget::onPlot()
{
	//m_plotDone = false;
	QtGnuplotInstance& gp = (*QtGnuplotInstance::getInstance(""));
	QString plotCommand;
	plotCommand += "set datafile separator \",\"\n";
	//QString plotCommand;
	plotCommand += QString("plot \"%1\" using \"%2\":\"%3\" with %4\n").arg(m_fileName).arg(m_xAxisName).arg(m_yAxisName).arg(m_lineType);
	gp << plotCommand.toLocal8Bit();
	Q_EMIT plotAction();
}

void SettingsWidget::onPlotDone()
{
	if (!m_plotDone)
	{
		//m_target->activateWindow();
		//m_target->raise();
		//m_target->resize(m_target->size());
		m_plotDone = true;
		//qDebug() << "plotDone";
	}
}


void SettingsWidget::onLineTypeChanged(const QString& type)
{
	m_lineType = type;
}


void SettingsWidget::onXAxisChanged(const QString& xAxis)
{
	m_xAxisName = xAxis;
}

void SettingsWidget::onYAxisChanged(const QString& yAxis)
{
	m_yAxisName = yAxis;
}

/*void WorkerThread::run()  
{
	while (1)
	{
		if (g_Commands.count())
		{
			QtGnuplotInstance& gp = (*QtGnuplotInstance::getInstance(""));
			g_Mutex.lock();
			gp << g_Commands.takeAt(0);
			g_Mutex.unlock();
		}
	}
	QString result;
	emit resultReady(result);
}
*/