#ifndef FCMAINWINDOW_H
#define FCMAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextCodec>


#include <FCOperationFlowmeter.h>
#include <FCParameter.h>
#include <FCRecordEvent.h>
#include <qcustomplot.h>


namespace Ui {
class FCMainWindow;
}

class FCMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FCMainWindow(QWidget *parent = 0);
    ~FCMainWindow();
    void InitUI();
    void InitConnect();
private slots:
    void ShowSystemMessage(QString,uint16_t);
    void ShowParameter(QString,QString);
    void ShowNextParameter(QString,QString);
    void ShowLastParameter(QString,QString);
private:
    Ui::FCMainWindow *ui;

    QTabWidget *MyTabWidget;

    FCOperationFlowmeter *MyFCOperationFlowmeter = nullptr;
    FCParameter    *MyFCParameter                = nullptr;
    FCRecordEvent  *MyFCRecordEvent              = nullptr;

    QLabel *BradRate;
    QLabel *ComPort;

    QLabel *NextBradRate;
    QLabel *NextComPort;

    QLabel *LastBradRate;
    QLabel *LastComPort;

    QString TextMessage;
};

#endif // FCMAINWINDOW_H
