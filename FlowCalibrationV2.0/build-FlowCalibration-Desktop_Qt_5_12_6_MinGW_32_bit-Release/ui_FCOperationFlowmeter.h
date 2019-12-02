/********************************************************************************
** Form generated from reading UI file 'FCOperationFlowmeter.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FCOPERATIONFLOWMETER_H
#define UI_FCOPERATIONFLOWMETER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_FCOperationFlowmeter
{
public:
    QGroupBox *groupBox;
    QCustomPlot *MyCustomPlot;
    QGroupBox *groupBox_2;
    QToolButton *tbnConnect;
    QToolButton *tbnMeasure;
    QToolButton *tbnReset;
    QToolButton *tbnOpen;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *lb15;
    QLineEdit *leDutyCycle;
    QLabel *lb14;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer_2;
    QWidget *layoutWidget_2;
    QGridLayout *gridLayout_28;
    QLabel *lb16;
    QLineEdit *leCalculateFlow;
    QLabel *lb17;
    QSpacerItem *verticalSpacer_53;
    QSpacerItem *verticalSpacer_54;
    QWidget *layoutWidget_3;
    QGridLayout *gridLayout_2;
    QSpacerItem *verticalSpacer_4;
    QLabel *lb19;
    QLineEdit *leScaleDisplay;
    QLabel *lb18;
    QSpacerItem *verticalSpacer_3;
    QWidget *layoutWidget_4;
    QGridLayout *gridLayout_3;
    QLabel *lb13;
    QLineEdit *leCalibrationTime;
    QLabel *lb12;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *tbnClearWave;
    QToolButton *tbnFlowSpeedCalibration;
    QWidget *layoutWidget_7;
    QGridLayout *gridLayout_27;
    QSpacerItem *verticalSpacer_51;
    QSpacerItem *verticalSpacer_52;
    QLabel *lb11;
    QLabel *lb10;
    QLineEdit *leFlowSpeed;
    QComboBox *comboBoxComPort;
    QCheckBox *cbInvert;
    QGroupBox *groupBox_3;
    QGroupBox *groupBox_6;
    QWidget *layoutWidget_15;
    QGridLayout *gridLayout_33;
    QSpacerItem *horizontalSpacer_33;
    QLineEdit *leFlowDisplay_2;
    QSpacerItem *verticalSpacer_67;
    QLabel *lb2;
    QSpacerItem *verticalSpacer_66;
    QWidget *layoutWidget_14;
    QGridLayout *gridLayout_32;
    QLabel *lb5;
    QSpacerItem *horizontalSpacer_32;
    QSpacerItem *verticalSpacer_64;
    QLineEdit *leFlowDisplay_5;
    QSpacerItem *verticalSpacer_65;
    QWidget *layoutWidget_17;
    QGridLayout *gridLayout_35;
    QSpacerItem *horizontalSpacer_35;
    QSpacerItem *verticalSpacer_70;
    QLineEdit *leFlowDisplay_8;
    QLabel *lb8;
    QSpacerItem *verticalSpacer_71;
    QGroupBox *groupBox_8;
    QWidget *layoutWidget_27;
    QGridLayout *gridLayout_45;
    QLabel *lb4;
    QSpacerItem *verticalSpacer_90;
    QSpacerItem *horizontalSpacer_45;
    QSpacerItem *verticalSpacer_91;
    QLineEdit *leFlowDisplay_4;
    QWidget *layoutWidget_28;
    QGridLayout *gridLayout_46;
    QLabel *lb1;
    QLineEdit *leFlowDisplay_1;
    QSpacerItem *verticalSpacer_92;
    QSpacerItem *verticalSpacer_93;
    QSpacerItem *horizontalSpacer_46;
    QWidget *layoutWidget_29;
    QGridLayout *gridLayout_47;
    QLineEdit *leFlowDisplay_7;
    QSpacerItem *verticalSpacer_94;
    QSpacerItem *verticalSpacer_95;
    QSpacerItem *horizontalSpacer_47;
    QLabel *lb7;
    QGroupBox *groupBox_7;
    QWidget *layoutWidget_6;
    QGridLayout *gridLayout_19;
    QSpacerItem *verticalSpacer_15;
    QLineEdit *leFlowDisplay_6;
    QSpacerItem *horizontalSpacer_24;
    QLabel *lb6;
    QSpacerItem *verticalSpacer_12;
    QRadioButton *rbConstant2;
    QWidget *layoutWidget_8;
    QGridLayout *gridLayout_21;
    QSpacerItem *horizontalSpacer_26;
    QSpacerItem *verticalSpacer_16;
    QLabel *lb9;
    QSpacerItem *verticalSpacer_41;
    QLineEdit *leFlowDisplay_9;
    QRadioButton *rbConstant3;
    QWidget *layoutWidget_9;
    QGridLayout *gridLayout_22;
    QLabel *lb3;
    QSpacerItem *horizontalSpacer_27;
    QSpacerItem *verticalSpacer_42;
    QSpacerItem *verticalSpacer_9;
    QLineEdit *leFlowDisplay_3;
    QRadioButton *rbConstant1;
    QWidget *layoutWidget_5;
    QGridLayout *gridLayout_30;
    QSpacerItem *verticalSpacer_60;
    QToolButton *tbnWriteConst;
    QToolButton *tbnCalculateConst;
    QSpacerItem *verticalSpacer_61;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *FCOperationFlowmeter)
    {
        if (FCOperationFlowmeter->objectName().isEmpty())
            FCOperationFlowmeter->setObjectName(QString::fromUtf8("FCOperationFlowmeter"));
        FCOperationFlowmeter->resize(1333, 685);
        groupBox = new QGroupBox(FCOperationFlowmeter);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 781, 651));
        MyCustomPlot = new QCustomPlot(groupBox);
        MyCustomPlot->setObjectName(QString::fromUtf8("MyCustomPlot"));
        MyCustomPlot->setGeometry(QRect(10, 20, 761, 611));
        groupBox_2 = new QGroupBox(FCOperationFlowmeter);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(810, 10, 511, 371));
        tbnConnect = new QToolButton(groupBox_2);
        tbnConnect->setObjectName(QString::fromUtf8("tbnConnect"));
        tbnConnect->setGeometry(QRect(20, 20, 141, 41));
        tbnMeasure = new QToolButton(groupBox_2);
        tbnMeasure->setObjectName(QString::fromUtf8("tbnMeasure"));
        tbnMeasure->setGeometry(QRect(190, 20, 141, 41));
        tbnReset = new QToolButton(groupBox_2);
        tbnReset->setObjectName(QString::fromUtf8("tbnReset"));
        tbnReset->setGeometry(QRect(20, 80, 141, 41));
        tbnOpen = new QToolButton(groupBox_2);
        tbnOpen->setObjectName(QString::fromUtf8("tbnOpen"));
        tbnOpen->setGeometry(QRect(360, 20, 141, 41));
        layoutWidget = new QWidget(groupBox_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(270, 200, 231, 41));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lb15 = new QLabel(layoutWidget);
        lb15->setObjectName(QString::fromUtf8("lb15"));

        gridLayout->addWidget(lb15, 1, 3, 1, 1);

        leDutyCycle = new QLineEdit(layoutWidget);
        leDutyCycle->setObjectName(QString::fromUtf8("leDutyCycle"));

        gridLayout->addWidget(leDutyCycle, 1, 2, 1, 1);

        lb14 = new QLabel(layoutWidget);
        lb14->setObjectName(QString::fromUtf8("lb14"));

        gridLayout->addWidget(lb14, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 1, 1, 1);

        layoutWidget_2 = new QWidget(groupBox_2);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 260, 321, 41));
        gridLayout_28 = new QGridLayout(layoutWidget_2);
        gridLayout_28->setObjectName(QString::fromUtf8("gridLayout_28"));
        gridLayout_28->setContentsMargins(0, 0, 0, 0);
        lb16 = new QLabel(layoutWidget_2);
        lb16->setObjectName(QString::fromUtf8("lb16"));

        gridLayout_28->addWidget(lb16, 1, 0, 1, 1);

        leCalculateFlow = new QLineEdit(layoutWidget_2);
        leCalculateFlow->setObjectName(QString::fromUtf8("leCalculateFlow"));

        gridLayout_28->addWidget(leCalculateFlow, 1, 1, 1, 1);

        lb17 = new QLabel(layoutWidget_2);
        lb17->setObjectName(QString::fromUtf8("lb17"));

        gridLayout_28->addWidget(lb17, 1, 2, 1, 1);

        verticalSpacer_53 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_28->addItem(verticalSpacer_53, 0, 1, 1, 1);

        verticalSpacer_54 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_28->addItem(verticalSpacer_54, 2, 1, 1, 1);

        layoutWidget_3 = new QWidget(groupBox_2);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(20, 320, 291, 41));
        gridLayout_2 = new QGridLayout(layoutWidget_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_4, 2, 1, 1, 1);

        lb19 = new QLabel(layoutWidget_3);
        lb19->setObjectName(QString::fromUtf8("lb19"));

        gridLayout_2->addWidget(lb19, 1, 2, 1, 1);

        leScaleDisplay = new QLineEdit(layoutWidget_3);
        leScaleDisplay->setObjectName(QString::fromUtf8("leScaleDisplay"));

        gridLayout_2->addWidget(leScaleDisplay, 1, 1, 1, 1);

        lb18 = new QLabel(layoutWidget_3);
        lb18->setObjectName(QString::fromUtf8("lb18"));

        gridLayout_2->addWidget(lb18, 1, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 0, 1, 1, 1);

        layoutWidget_4 = new QWidget(groupBox_2);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(20, 200, 231, 41));
        gridLayout_3 = new QGridLayout(layoutWidget_4);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        lb13 = new QLabel(layoutWidget_4);
        lb13->setObjectName(QString::fromUtf8("lb13"));

        gridLayout_3->addWidget(lb13, 1, 3, 1, 1);

        leCalibrationTime = new QLineEdit(layoutWidget_4);
        leCalibrationTime->setObjectName(QString::fromUtf8("leCalibrationTime"));

        gridLayout_3->addWidget(leCalibrationTime, 1, 2, 1, 1);

        lb12 = new QLabel(layoutWidget_4);
        lb12->setObjectName(QString::fromUtf8("lb12"));

        gridLayout_3->addWidget(lb12, 1, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_5, 0, 2, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_6, 2, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 1, 1, 1, 1);

        tbnClearWave = new QToolButton(groupBox_2);
        tbnClearWave->setObjectName(QString::fromUtf8("tbnClearWave"));
        tbnClearWave->setGeometry(QRect(190, 80, 141, 41));
        tbnFlowSpeedCalibration = new QToolButton(groupBox_2);
        tbnFlowSpeedCalibration->setObjectName(QString::fromUtf8("tbnFlowSpeedCalibration"));
        tbnFlowSpeedCalibration->setGeometry(QRect(370, 140, 131, 41));
        layoutWidget_7 = new QWidget(groupBox_2);
        layoutWidget_7->setObjectName(QString::fromUtf8("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(20, 140, 331, 41));
        gridLayout_27 = new QGridLayout(layoutWidget_7);
        gridLayout_27->setObjectName(QString::fromUtf8("gridLayout_27"));
        gridLayout_27->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_51 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_27->addItem(verticalSpacer_51, 0, 1, 1, 1);

        verticalSpacer_52 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_27->addItem(verticalSpacer_52, 2, 1, 1, 1);

        lb11 = new QLabel(layoutWidget_7);
        lb11->setObjectName(QString::fromUtf8("lb11"));

        gridLayout_27->addWidget(lb11, 1, 2, 1, 1);

        lb10 = new QLabel(layoutWidget_7);
        lb10->setObjectName(QString::fromUtf8("lb10"));

        gridLayout_27->addWidget(lb10, 1, 0, 1, 1);

        leFlowSpeed = new QLineEdit(layoutWidget_7);
        leFlowSpeed->setObjectName(QString::fromUtf8("leFlowSpeed"));

        gridLayout_27->addWidget(leFlowSpeed, 1, 1, 1, 1);

        comboBoxComPort = new QComboBox(groupBox_2);
        comboBoxComPort->setObjectName(QString::fromUtf8("comboBoxComPort"));
        comboBoxComPort->setGeometry(QRect(360, 80, 141, 41));
        cbInvert = new QCheckBox(groupBox_2);
        cbInvert->setObjectName(QString::fromUtf8("cbInvert"));
        cbInvert->setGeometry(QRect(360, 80, 141, 41));
        groupBox_3 = new QGroupBox(FCOperationFlowmeter);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(810, 390, 511, 271));
        groupBox_6 = new QGroupBox(groupBox_3);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(170, 30, 151, 171));
        layoutWidget_15 = new QWidget(groupBox_6);
        layoutWidget_15->setObjectName(QString::fromUtf8("layoutWidget_15"));
        layoutWidget_15->setGeometry(QRect(10, 21, 131, 41));
        gridLayout_33 = new QGridLayout(layoutWidget_15);
        gridLayout_33->setObjectName(QString::fromUtf8("gridLayout_33"));
        gridLayout_33->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_33 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_33->addItem(horizontalSpacer_33, 2, 0, 1, 1);

        leFlowDisplay_2 = new QLineEdit(layoutWidget_15);
        leFlowDisplay_2->setObjectName(QString::fromUtf8("leFlowDisplay_2"));

        gridLayout_33->addWidget(leFlowDisplay_2, 2, 2, 1, 1);

        verticalSpacer_67 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_33->addItem(verticalSpacer_67, 1, 2, 1, 1);

        lb2 = new QLabel(layoutWidget_15);
        lb2->setObjectName(QString::fromUtf8("lb2"));

        gridLayout_33->addWidget(lb2, 2, 1, 1, 1);

        verticalSpacer_66 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_33->addItem(verticalSpacer_66, 3, 2, 1, 1);

        layoutWidget_14 = new QWidget(groupBox_6);
        layoutWidget_14->setObjectName(QString::fromUtf8("layoutWidget_14"));
        layoutWidget_14->setGeometry(QRect(10, 70, 131, 41));
        gridLayout_32 = new QGridLayout(layoutWidget_14);
        gridLayout_32->setObjectName(QString::fromUtf8("gridLayout_32"));
        gridLayout_32->setContentsMargins(0, 0, 0, 0);
        lb5 = new QLabel(layoutWidget_14);
        lb5->setObjectName(QString::fromUtf8("lb5"));

        gridLayout_32->addWidget(lb5, 1, 1, 1, 1);

        horizontalSpacer_32 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_32->addItem(horizontalSpacer_32, 1, 0, 1, 1);

        verticalSpacer_64 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_32->addItem(verticalSpacer_64, 0, 2, 1, 1);

        leFlowDisplay_5 = new QLineEdit(layoutWidget_14);
        leFlowDisplay_5->setObjectName(QString::fromUtf8("leFlowDisplay_5"));

        gridLayout_32->addWidget(leFlowDisplay_5, 1, 2, 1, 1);

        verticalSpacer_65 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_32->addItem(verticalSpacer_65, 2, 2, 1, 1);

        layoutWidget_17 = new QWidget(groupBox_6);
        layoutWidget_17->setObjectName(QString::fromUtf8("layoutWidget_17"));
        layoutWidget_17->setGeometry(QRect(10, 121, 131, 41));
        gridLayout_35 = new QGridLayout(layoutWidget_17);
        gridLayout_35->setObjectName(QString::fromUtf8("gridLayout_35"));
        gridLayout_35->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_35 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_35->addItem(horizontalSpacer_35, 1, 0, 1, 1);

        verticalSpacer_70 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_35->addItem(verticalSpacer_70, 0, 2, 1, 1);

        leFlowDisplay_8 = new QLineEdit(layoutWidget_17);
        leFlowDisplay_8->setObjectName(QString::fromUtf8("leFlowDisplay_8"));

        gridLayout_35->addWidget(leFlowDisplay_8, 1, 2, 1, 1);

        lb8 = new QLabel(layoutWidget_17);
        lb8->setObjectName(QString::fromUtf8("lb8"));

        gridLayout_35->addWidget(lb8, 1, 1, 1, 1);

        verticalSpacer_71 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_35->addItem(verticalSpacer_71, 2, 2, 1, 1);

        groupBox_8 = new QGroupBox(groupBox_3);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(10, 30, 151, 171));
        layoutWidget_27 = new QWidget(groupBox_8);
        layoutWidget_27->setObjectName(QString::fromUtf8("layoutWidget_27"));
        layoutWidget_27->setGeometry(QRect(10, 69, 131, 41));
        gridLayout_45 = new QGridLayout(layoutWidget_27);
        gridLayout_45->setObjectName(QString::fromUtf8("gridLayout_45"));
        gridLayout_45->setContentsMargins(0, 0, 0, 0);
        lb4 = new QLabel(layoutWidget_27);
        lb4->setObjectName(QString::fromUtf8("lb4"));

        gridLayout_45->addWidget(lb4, 1, 1, 1, 1);

        verticalSpacer_90 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_45->addItem(verticalSpacer_90, 0, 2, 1, 1);

        horizontalSpacer_45 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_45->addItem(horizontalSpacer_45, 1, 0, 1, 1);

        verticalSpacer_91 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_45->addItem(verticalSpacer_91, 2, 2, 1, 1);

        leFlowDisplay_4 = new QLineEdit(layoutWidget_27);
        leFlowDisplay_4->setObjectName(QString::fromUtf8("leFlowDisplay_4"));

        gridLayout_45->addWidget(leFlowDisplay_4, 1, 2, 1, 1);

        layoutWidget_28 = new QWidget(groupBox_8);
        layoutWidget_28->setObjectName(QString::fromUtf8("layoutWidget_28"));
        layoutWidget_28->setGeometry(QRect(10, 20, 131, 41));
        gridLayout_46 = new QGridLayout(layoutWidget_28);
        gridLayout_46->setObjectName(QString::fromUtf8("gridLayout_46"));
        gridLayout_46->setContentsMargins(0, 0, 0, 0);
        lb1 = new QLabel(layoutWidget_28);
        lb1->setObjectName(QString::fromUtf8("lb1"));

        gridLayout_46->addWidget(lb1, 2, 1, 1, 1);

        leFlowDisplay_1 = new QLineEdit(layoutWidget_28);
        leFlowDisplay_1->setObjectName(QString::fromUtf8("leFlowDisplay_1"));

        gridLayout_46->addWidget(leFlowDisplay_1, 2, 2, 1, 1);

        verticalSpacer_92 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_46->addItem(verticalSpacer_92, 1, 2, 1, 1);

        verticalSpacer_93 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_46->addItem(verticalSpacer_93, 3, 2, 1, 1);

        horizontalSpacer_46 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_46->addItem(horizontalSpacer_46, 2, 0, 1, 1);

        layoutWidget_29 = new QWidget(groupBox_8);
        layoutWidget_29->setObjectName(QString::fromUtf8("layoutWidget_29"));
        layoutWidget_29->setGeometry(QRect(10, 120, 131, 41));
        gridLayout_47 = new QGridLayout(layoutWidget_29);
        gridLayout_47->setObjectName(QString::fromUtf8("gridLayout_47"));
        gridLayout_47->setContentsMargins(0, 0, 0, 0);
        leFlowDisplay_7 = new QLineEdit(layoutWidget_29);
        leFlowDisplay_7->setObjectName(QString::fromUtf8("leFlowDisplay_7"));

        gridLayout_47->addWidget(leFlowDisplay_7, 1, 2, 1, 1);

        verticalSpacer_94 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_47->addItem(verticalSpacer_94, 0, 2, 1, 1);

        verticalSpacer_95 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_47->addItem(verticalSpacer_95, 2, 2, 1, 1);

        horizontalSpacer_47 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_47->addItem(horizontalSpacer_47, 1, 0, 1, 1);

        lb7 = new QLabel(layoutWidget_29);
        lb7->setObjectName(QString::fromUtf8("lb7"));

        gridLayout_47->addWidget(lb7, 1, 1, 1, 1);

        groupBox_7 = new QGroupBox(groupBox_3);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(330, 30, 171, 171));
        layoutWidget_6 = new QWidget(groupBox_7);
        layoutWidget_6->setObjectName(QString::fromUtf8("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(10, 69, 151, 41));
        gridLayout_19 = new QGridLayout(layoutWidget_6);
        gridLayout_19->setObjectName(QString::fromUtf8("gridLayout_19"));
        gridLayout_19->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_15 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_19->addItem(verticalSpacer_15, 2, 2, 1, 1);

        leFlowDisplay_6 = new QLineEdit(layoutWidget_6);
        leFlowDisplay_6->setObjectName(QString::fromUtf8("leFlowDisplay_6"));

        gridLayout_19->addWidget(leFlowDisplay_6, 1, 2, 1, 1);

        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_19->addItem(horizontalSpacer_24, 1, 0, 1, 1);

        lb6 = new QLabel(layoutWidget_6);
        lb6->setObjectName(QString::fromUtf8("lb6"));

        gridLayout_19->addWidget(lb6, 1, 1, 1, 1);

        verticalSpacer_12 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_19->addItem(verticalSpacer_12, 0, 2, 1, 1);

        rbConstant2 = new QRadioButton(layoutWidget_6);
        rbConstant2->setObjectName(QString::fromUtf8("rbConstant2"));

        gridLayout_19->addWidget(rbConstant2, 1, 3, 1, 1);

        layoutWidget_8 = new QWidget(groupBox_7);
        layoutWidget_8->setObjectName(QString::fromUtf8("layoutWidget_8"));
        layoutWidget_8->setGeometry(QRect(10, 120, 151, 41));
        gridLayout_21 = new QGridLayout(layoutWidget_8);
        gridLayout_21->setObjectName(QString::fromUtf8("gridLayout_21"));
        gridLayout_21->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_26 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_21->addItem(horizontalSpacer_26, 1, 0, 1, 1);

        verticalSpacer_16 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_21->addItem(verticalSpacer_16, 0, 2, 1, 1);

        lb9 = new QLabel(layoutWidget_8);
        lb9->setObjectName(QString::fromUtf8("lb9"));

        gridLayout_21->addWidget(lb9, 1, 1, 1, 1);

        verticalSpacer_41 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_21->addItem(verticalSpacer_41, 2, 2, 1, 1);

        leFlowDisplay_9 = new QLineEdit(layoutWidget_8);
        leFlowDisplay_9->setObjectName(QString::fromUtf8("leFlowDisplay_9"));

        gridLayout_21->addWidget(leFlowDisplay_9, 1, 2, 1, 1);

        rbConstant3 = new QRadioButton(layoutWidget_8);
        rbConstant3->setObjectName(QString::fromUtf8("rbConstant3"));

        gridLayout_21->addWidget(rbConstant3, 1, 3, 1, 1);

        layoutWidget_9 = new QWidget(groupBox_7);
        layoutWidget_9->setObjectName(QString::fromUtf8("layoutWidget_9"));
        layoutWidget_9->setGeometry(QRect(10, 20, 151, 41));
        gridLayout_22 = new QGridLayout(layoutWidget_9);
        gridLayout_22->setObjectName(QString::fromUtf8("gridLayout_22"));
        gridLayout_22->setContentsMargins(0, 0, 0, 0);
        lb3 = new QLabel(layoutWidget_9);
        lb3->setObjectName(QString::fromUtf8("lb3"));

        gridLayout_22->addWidget(lb3, 2, 1, 1, 1);

        horizontalSpacer_27 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_22->addItem(horizontalSpacer_27, 2, 0, 1, 1);

        verticalSpacer_42 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_22->addItem(verticalSpacer_42, 1, 2, 1, 1);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_22->addItem(verticalSpacer_9, 3, 2, 1, 1);

        leFlowDisplay_3 = new QLineEdit(layoutWidget_9);
        leFlowDisplay_3->setObjectName(QString::fromUtf8("leFlowDisplay_3"));

        gridLayout_22->addWidget(leFlowDisplay_3, 2, 2, 1, 1);

        rbConstant1 = new QRadioButton(layoutWidget_9);
        rbConstant1->setObjectName(QString::fromUtf8("rbConstant1"));

        gridLayout_22->addWidget(rbConstant1, 2, 3, 1, 1);

        layoutWidget_5 = new QWidget(groupBox_3);
        layoutWidget_5->setObjectName(QString::fromUtf8("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(70, 220, 351, 41));
        gridLayout_30 = new QGridLayout(layoutWidget_5);
        gridLayout_30->setObjectName(QString::fromUtf8("gridLayout_30"));
        gridLayout_30->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_60 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_30->addItem(verticalSpacer_60, 2, 0, 1, 1);

        tbnWriteConst = new QToolButton(layoutWidget_5);
        tbnWriteConst->setObjectName(QString::fromUtf8("tbnWriteConst"));

        gridLayout_30->addWidget(tbnWriteConst, 1, 2, 1, 1);

        tbnCalculateConst = new QToolButton(layoutWidget_5);
        tbnCalculateConst->setObjectName(QString::fromUtf8("tbnCalculateConst"));

        gridLayout_30->addWidget(tbnCalculateConst, 1, 0, 1, 1);

        verticalSpacer_61 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_30->addItem(verticalSpacer_61, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_30->addItem(horizontalSpacer, 1, 1, 1, 1);


        retranslateUi(FCOperationFlowmeter);

        QMetaObject::connectSlotsByName(FCOperationFlowmeter);
    } // setupUi

    void retranslateUi(QWidget *FCOperationFlowmeter)
    {
        FCOperationFlowmeter->setWindowTitle(QApplication::translate("FCOperationFlowmeter", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("FCOperationFlowmeter", "\346\233\262\347\272\277\347\273\230\345\210\266", nullptr));
        groupBox_2->setTitle(QApplication::translate("FCOperationFlowmeter", "\346\240\207\345\256\232\350\256\276\345\244\207\346\223\215\344\275\234", nullptr));
        tbnConnect->setText(QApplication::translate("FCOperationFlowmeter", "\350\277\236\346\216\245\350\256\276\345\244\207", nullptr));
        tbnMeasure->setText(QApplication::translate("FCOperationFlowmeter", "\346\240\207\345\256\232\350\256\276\345\244\207", nullptr));
        tbnReset->setText(QApplication::translate("FCOperationFlowmeter", "\350\256\276\345\244\207\346\270\205\351\233\266", nullptr));
        tbnOpen->setText(QApplication::translate("FCOperationFlowmeter", "\351\207\212\346\224\276\346\266\262\344\275\223", nullptr));
        lb15->setText(QApplication::translate("FCOperationFlowmeter", "%", nullptr));
        leDutyCycle->setText(QString());
        lb14->setText(QApplication::translate("FCOperationFlowmeter", "\345\215\240\347\251\272\346\257\224\357\274\232", nullptr));
        lb16->setText(QApplication::translate("FCOperationFlowmeter", "\350\256\241\347\256\227\346\265\201\351\200\237\357\274\232", nullptr));
        leCalculateFlow->setText(QString());
        lb17->setText(QApplication::translate("FCOperationFlowmeter", "ml/min", nullptr));
        lb19->setText(QApplication::translate("FCOperationFlowmeter", "g", nullptr));
        lb18->setText(QApplication::translate("FCOperationFlowmeter", "\345\244\251\345\271\263\350\257\273\346\225\260\357\274\232", nullptr));
        lb13->setText(QApplication::translate("FCOperationFlowmeter", "s", nullptr));
        leCalibrationTime->setText(QString());
        lb12->setText(QApplication::translate("FCOperationFlowmeter", "\346\240\207\345\256\232\347\224\250\346\227\266\357\274\232", nullptr));
        tbnClearWave->setText(QApplication::translate("FCOperationFlowmeter", "\346\270\205\347\251\272\346\233\262\347\272\277", nullptr));
        tbnFlowSpeedCalibration->setText(QApplication::translate("FCOperationFlowmeter", "\350\207\252\345\212\250\346\240\207\345\256\232", nullptr));
        lb11->setText(QApplication::translate("FCOperationFlowmeter", "ml/min", nullptr));
        lb10->setText(QApplication::translate("FCOperationFlowmeter", "\346\265\201\351\200\237\350\256\276\345\256\232\357\274\232", nullptr));
        cbInvert->setText(QApplication::translate("FCOperationFlowmeter", "\345\244\251\345\271\263\345\217\215\345\220\221", nullptr));
        groupBox_3->setTitle(QApplication::translate("FCOperationFlowmeter", "\346\265\201\351\207\217\350\256\241\346\223\215\344\275\234", nullptr));
        groupBox_6->setTitle(QApplication::translate("FCOperationFlowmeter", "\347\236\254\346\227\266\346\265\201\351\200\237 ml/min", nullptr));
        leFlowDisplay_2->setText(QString());
        lb2->setText(QApplication::translate("FCOperationFlowmeter", "1", nullptr));
        lb5->setText(QApplication::translate("FCOperationFlowmeter", "2", nullptr));
        leFlowDisplay_5->setText(QString());
        leFlowDisplay_8->setText(QString());
        lb8->setText(QApplication::translate("FCOperationFlowmeter", "3", nullptr));
        groupBox_8->setTitle(QApplication::translate("FCOperationFlowmeter", "\347\264\257\347\247\257\346\265\201\351\207\217  /ml", nullptr));
        lb4->setText(QApplication::translate("FCOperationFlowmeter", "2", nullptr));
        leFlowDisplay_4->setText(QString());
        lb1->setText(QApplication::translate("FCOperationFlowmeter", "1", nullptr));
        leFlowDisplay_1->setText(QString());
        leFlowDisplay_7->setText(QString());
        lb7->setText(QApplication::translate("FCOperationFlowmeter", "3", nullptr));
        groupBox_7->setTitle(QApplication::translate("FCOperationFlowmeter", "\346\240\207\345\256\232\345\270\270\346\225\260 C", nullptr));
        leFlowDisplay_6->setText(QString());
        lb6->setText(QApplication::translate("FCOperationFlowmeter", "2", nullptr));
        rbConstant2->setText(QString());
        lb9->setText(QApplication::translate("FCOperationFlowmeter", "3", nullptr));
        leFlowDisplay_9->setText(QString());
        rbConstant3->setText(QString());
        lb3->setText(QApplication::translate("FCOperationFlowmeter", "1", nullptr));
        leFlowDisplay_3->setText(QString());
        rbConstant1->setText(QString());
        tbnWriteConst->setText(QApplication::translate("FCOperationFlowmeter", "\345\206\231\345\205\245C\345\270\270\346\225\260", nullptr));
        tbnCalculateConst->setText(QApplication::translate("FCOperationFlowmeter", "\350\256\241\347\256\227C\345\270\270\346\225\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FCOperationFlowmeter: public Ui_FCOperationFlowmeter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FCOPERATIONFLOWMETER_H
