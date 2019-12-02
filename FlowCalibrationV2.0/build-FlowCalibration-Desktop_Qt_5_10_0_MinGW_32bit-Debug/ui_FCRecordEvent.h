/********************************************************************************
** Form generated from reading UI file 'FCRecordEvent.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FCRECORDEVENT_H
#define UI_FCRECORDEVENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FCRecordEvent
{
public:

    void setupUi(QWidget *FCRecordEvent)
    {
        if (FCRecordEvent->objectName().isEmpty())
            FCRecordEvent->setObjectName(QStringLiteral("FCRecordEvent"));
        FCRecordEvent->resize(400, 300);

        retranslateUi(FCRecordEvent);

        QMetaObject::connectSlotsByName(FCRecordEvent);
    } // setupUi

    void retranslateUi(QWidget *FCRecordEvent)
    {
        FCRecordEvent->setWindowTitle(QApplication::translate("FCRecordEvent", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FCRecordEvent: public Ui_FCRecordEvent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FCRECORDEVENT_H
