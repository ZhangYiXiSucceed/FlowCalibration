/********************************************************************************
** Form generated from reading UI file 'FCMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FCMAINWINDOW_H
#define UI_FCMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FCMainWindow
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FCMainWindow)
    {
        if (FCMainWindow->objectName().isEmpty())
            FCMainWindow->setObjectName(QStringLiteral("FCMainWindow"));
        FCMainWindow->resize(1358, 757);
        centralWidget = new QWidget(FCMainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        FCMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(FCMainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1358, 26));
        FCMainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(FCMainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        FCMainWindow->setStatusBar(statusBar);

        retranslateUi(FCMainWindow);

        QMetaObject::connectSlotsByName(FCMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *FCMainWindow)
    {
        FCMainWindow->setWindowTitle(QApplication::translate("FCMainWindow", "FCMainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FCMainWindow: public Ui_FCMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FCMAINWINDOW_H
