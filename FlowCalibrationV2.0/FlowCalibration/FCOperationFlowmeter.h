#ifndef FCOPERATIONFLOWMETER_H
#define FCOPERATIONFLOWMETER_H

#include <QWidget>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QPixmap>
#include <QTimer>
#include <QVector>

#define  PIDTime   2
#define  Debug     0
#define  ConnectMaxTimes  5
#define  Minute      60
#define  SampleTime  500
#define  DeviceAddr  0x04


namespace Ui {
class FCOperationFlowmeter;
}

class FCOperationFlowmeter : public QWidget
{
    Q_OBJECT

public:
    explicit FCOperationFlowmeter(QWidget *parent = 0);
    ~FCOperationFlowmeter();
     void InitUI();
     void InitConnect();
     void Refresh();

     void WriteBytes(QByteArray);
     void NextWriteBytes(QByteArray);
     void LastWriteBytes(QByteArray);

     void RunCommand(QByteArray);
     void RunNextCommand(QByteArray);
     void RunLastCommand(QByteArray);
     void UpdateResponse();
     void SetDutyCyeleAddValue(int);
     quint16 CRC16Check(QByteArray RecFrameData,quint8 FrameLength);
signals:
    void ShowMessage(QString,uint16_t);
    void ShowParameter(QString,QString);
    void ShowNextParameter(QString,QString);
    void ShowLastParameter(QString,QString);

    void FindNextComport();
    void FindLastComport();
    void SendLinearCalPara(QVector<float>);

    void SendCalibrationOK();
private slots:
    void ConnectComport();
    void ConnectNextComport();
    void ConnectLastComport();

    void ReadRecData();
    void ReadNextRecData();
    void ReadLastRecData();

    void TimerUpdate();
    void ShowCalibrationTime();

    void DutyCycleUp();
    void DutyCycleDown();

    void Switch();
    void Measure();
    void ClearWaves();
    void Reset();

    void FlowSpeedCalibration();
    void CalculateConst();
    void WriteConst();

    void NullDriftCalibration(QString);

    void RecReadSignal();
    void RecWriteSignal(QVector<float>);
private:
    Ui::FCOperationFlowmeter *ui;

    QSerialPort     *MySerialPort     = nullptr;
    QSerialPort     *MyNextSerialPort = nullptr;
    QSerialPort     *MyLastSerialPort = nullptr;

    QTimer           *MyTimer         = nullptr;
    QTimer           *ShowTimer       = nullptr;

    QVector<float> LinearCalPara;

    quint8 ConnectTimes;
    bool ConnectFlag;
    quint8 ConnectNextTimes;
    bool ConnectNextFlag;
    quint8 ConnectLastTimes;
    bool ConnectLastFlag;

    bool MeasureFlag;
    bool FirstMeasureFlag;

    quint32 WaveNum;
    double LastQuality;
    double SumQuality;

    double CurrentFlowSpeed;
    double SetFlowSpeed;
    quint8 SetAdjustTime;

    bool FlowSpeedFlag;
    bool FlowStopFlag;
    bool FlowCalibrationFlag;

    QString  CalibrationTime;
    bool CalibrationTimeFlag;
    bool SwitchFlag;
    bool AutoStopFlag;

    QPixmap ImageFileOpen=tr(":/Image/Open.png");
    QPixmap ImageFileClose=tr(":/Image/Close.png");
    QPixmap ImageFileStart=tr(":/Image/Stop.png");
    QPixmap ImageFileStop=tr(":/Image/Start.png");
    QPixmap ImageFileConnectOpen=tr(":/Image/ConnectOpen.png");
    QPixmap ImageFileConnectClose=tr(":/Image/ConnectClose.png");
    QPixmap ImageFileClearWaves=tr(":/Image/ClearWaves.png");
    QPixmap ImageFileReset=tr(":/Image/Reset.png");
    QPixmap ImageFileCalibration=tr(":/Image/Calibration.png");
    QPixmap ImageFileWrite=tr(":/Image/Write.png");
    QPixmap ImageFileCalibrationStop=tr(":/Image/CalibrationStop.png");
};

#endif // FCOPERATIONFLOWMETER_H
