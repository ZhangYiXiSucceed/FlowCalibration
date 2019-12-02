#ifndef FCPARAMETER_H
#define FCPARAMETER_H

#include <QWidget>

namespace Ui {
class FCParameter;
}

class FCParameter : public QWidget
{
    Q_OBJECT

public:
    explicit FCParameter(QWidget *parent = 0);
    ~FCParameter();
    void InitUI();
    void InitConnect();
private slots:
    void Read();
    void Write();
    void RecLinearCalPara(QVector<float>);
    void WriteCalibrationPara(QString);
    void CopySpeedData();
    void CopyParaData();
    void NullDriftCalibration();
    void RecCalibrationInfo();
signals:
    void ShowMessage(QString,uint16_t);
    void ReadLinearCalPara();
    void WriteLinearCalPara(QVector<float>);
    void SendNullDriftCalibrationSignal(QString);
private:
    Ui::FCParameter *ui;

    QVector<float> LinearCalPara;

    QPixmap ImageFileOK=tr(":/Image/OK.png");
    QPixmap ImageFileCancel=tr(":/Image/Cancel.png");
    QPixmap ImageFileRead=tr(":/Image/Read.png");
    QPixmap ImageFileWrite=tr(":/Image/Write.png");
    QPixmap ImageFileSave=tr(":/Image/SavePara.png");
    QPixmap ImageFileLoad=tr(":/Image/LoadPara.png");
    QPixmap ImageFileChangeAddress=tr(":/Image/Plus.png");
    QPixmap ImageFileNullCalibration=tr(":/Image/Reset.png");
};

#endif // FCPARAMETER_H
