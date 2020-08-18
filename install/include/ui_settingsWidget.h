/********************************************************************************
** Form generated from reading UI file 'settingsWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWIDGET_H
#define UI_SETTINGSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonOpen;
    QLineEdit *lineEditFileName;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label_2;
    QComboBox *xAxis;
    QLabel *label_3;
    QComboBox *yAxis;
    QLabel *label;
    QComboBox *lineType;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonPlot;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(340, 233);
        verticalLayout = new QVBoxLayout(Form);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButtonOpen = new QPushButton(Form);
        pushButtonOpen->setObjectName(QStringLiteral("pushButtonOpen"));

        horizontalLayout_2->addWidget(pushButtonOpen);

        lineEditFileName = new QLineEdit(Form);
        lineEditFileName->setObjectName(QStringLiteral("lineEditFileName"));

        horizontalLayout_2->addWidget(lineEditFileName);


        verticalLayout->addLayout(horizontalLayout_2);

        groupBox = new QGroupBox(Form);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        xAxis = new QComboBox(groupBox);
        xAxis->setObjectName(QStringLiteral("xAxis"));

        formLayout->setWidget(0, QFormLayout::FieldRole, xAxis);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        yAxis = new QComboBox(groupBox);
        yAxis->setObjectName(QStringLiteral("yAxis"));

        formLayout->setWidget(1, QFormLayout::FieldRole, yAxis);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label);

        lineType = new QComboBox(groupBox);
        lineType->setObjectName(QStringLiteral("lineType"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineType);


        verticalLayout->addWidget(groupBox);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButtonPlot = new QPushButton(Form);
        pushButtonPlot->setObjectName(QStringLiteral("pushButtonPlot"));

        horizontalLayout_3->addWidget(pushButtonPlot);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", Q_NULLPTR));
        pushButtonOpen->setText(QApplication::translate("Form", "Open", Q_NULLPTR));
#ifndef QT_NO_STATUSTIP
        lineEditFileName->setStatusTip(QApplication::translate("Form", "only cteas suppor", Q_NULLPTR));
#endif // QT_NO_STATUSTIP
        groupBox->setTitle(QApplication::translate("Form", "Settings", Q_NULLPTR));
        label_2->setText(QApplication::translate("Form", "X_Axis:", Q_NULLPTR));
        label_3->setText(QApplication::translate("Form", "Y_Axis:", Q_NULLPTR));
        label->setText(QApplication::translate("Form", "LineType:", Q_NULLPTR));
        pushButtonPlot->setText(QApplication::translate("Form", "Plot", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWIDGET_H
