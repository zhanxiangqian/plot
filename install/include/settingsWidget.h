#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QWidget>
#include <QString>
#include <QByteArray>
#include <QThread>
#include "ui_settingsWidget.h"
#include "export.h"

class QtGnuplotWidget;
class PLOTVIEW_EXPORT SettingsWidget : public QWidget
{
	Q_OBJECT
public:
	SettingsWidget(QWidget* parent = NULL);
	void setPlotWidget(QtGnuplotWidget* target);
Q_SIGNALS:
	void plotAction();
private slots:
void onOpen();
void onPlot();
void onPlotDone();
void onLineTypeChanged(const QString& type);
void onXAxisChanged(const QString& type);
void onYAxisChanged(const QString& type);
void reset();
private:
	Ui::Form ui;
	QString m_lineType;
	QString m_xAxisName;
	QString m_yAxisName;
	QByteArray m_commands;
	QString m_fileName;
	QtGnuplotWidget* m_target;
	bool m_plotDone;
};

/*class WorkerThread : public QThread
{
	Q_OBJECT
		void run() override;
signals:
	void resultReady(const QString &s);
};*/

#endif // !SETTINGSDIALOG_H
