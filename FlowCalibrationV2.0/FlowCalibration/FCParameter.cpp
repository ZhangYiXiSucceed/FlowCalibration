#include "FCParameter.h"
#include "ui_FCParameter.h"

FCParameter::FCParameter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FCParameter)
{
    ui->setupUi(this);
    InitUI();
    InitConnect();
}

FCParameter::~FCParameter()
{
    delete ui;
}
void FCParameter::InitUI()
{
    QFont Ft("Microsoft YaHei");
    Ft.setPointSize(12);


    ui->tbnOK->setFont(Ft);
    ui->tbnOK->setAutoRaise(true);
    ui->tbnOK->setIcon(ImageFileOK);
    ui->tbnOK->setIconSize(ImageFileOK.size());
    ui->tbnOK->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    ui->tbnCancel->setFont(Ft);
    ui->tbnCancel->setAutoRaise(true);
    ui->tbnCancel->setIcon(ImageFileCancel);
    ui->tbnCancel->setIconSize(ImageFileCancel.size());
    ui->tbnCancel->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    ui->tbnRead->setFont(Ft);
    ui->tbnRead->setAutoRaise(true);
    ui->tbnRead->setIcon(ImageFileRead);
    ui->tbnRead->setIconSize(ImageFileRead.size());
    ui->tbnRead->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    ui->tbnWrite->setFont(Ft);
    ui->tbnWrite->setAutoRaise(true);
    ui->tbnWrite->setIcon(ImageFileWrite);
    ui->tbnWrite->setIconSize(ImageFileWrite.size());
    ui->tbnWrite->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    ui->tbnSave->setFont(Ft);
    ui->tbnSave->setAutoRaise(true);
    ui->tbnSave->setIcon(ImageFileSave);
    ui->tbnSave->setIconSize(ImageFileSave.size());
    ui->tbnSave->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    ui->tbnLoad->setFont(Ft);
    ui->tbnLoad->setAutoRaise(true);
    ui->tbnLoad->setIcon(ImageFileLoad);
    ui->tbnLoad->setIconSize(ImageFileLoad.size());
    ui->tbnLoad->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    ui->tbnLoad->setFont(Ft);
    ui->tbnLoad->setAutoRaise(true);
    ui->tbnLoad->setIcon(ImageFileLoad);
    ui->tbnLoad->setIconSize(ImageFileLoad.size());
    ui->tbnLoad->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    ui->tbnChangeAddress->setFont(Ft);
    ui->tbnChangeAddress->setAutoRaise(true);
    ui->tbnChangeAddress->setIcon(ImageFileChangeAddress);
    ui->tbnChangeAddress->setIconSize(ImageFileChangeAddress.size());
    ui->tbnChangeAddress->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    ui->tbnNullDriftCalibration->setFont(Ft);
    ui->tbnNullDriftCalibration->setAutoRaise(true);
    ui->tbnNullDriftCalibration->setIcon(ImageFileNullCalibration);
    ui->tbnNullDriftCalibration->setIconSize(ImageFileNullCalibration.size());
    ui->tbnNullDriftCalibration->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    ui->le1->setFont(Ft);
    ui->le2->setFont(Ft);
    ui->le3->setFont(Ft);
    ui->le4->setFont(Ft);
    ui->le5->setFont(Ft);
    ui->le6->setFont(Ft);
    ui->le7->setFont(Ft);
    ui->le8->setFont(Ft);
    ui->le9->setFont(Ft);
    ui->le10->setFont(Ft);
    ui->le11->setFont(Ft);
    ui->le12->setFont(Ft);
    ui->le13->setFont(Ft);
    ui->le14->setFont(Ft);
    ui->le15->setFont(Ft);
    ui->le16->setFont(Ft);
    ui->le17->setFont(Ft);
    ui->le18->setFont(Ft);
    ui->le19->setFont(Ft);

    ui->le1_2->setFont(Ft);
    ui->le2_2->setFont(Ft);
    ui->le3_2->setFont(Ft);
    ui->le4_2->setFont(Ft);
    ui->le5_2->setFont(Ft);
    ui->le6_2->setFont(Ft);
    ui->le7_2->setFont(Ft);
    ui->le8_2->setFont(Ft);
    ui->le9_2->setFont(Ft);
    ui->le10_2->setFont(Ft);
    ui->le11_2->setFont(Ft);
    ui->le12_2->setFont(Ft);
    ui->le13_2->setFont(Ft);
    ui->le14_2->setFont(Ft);
    ui->le15_2->setFont(Ft);
    ui->le16_2->setFont(Ft);
    ui->le17_2->setFont(Ft);
    ui->le18_2->setFont(Ft);
    ui->le19_2->setFont(Ft);

    ui->leRange->setFont(Ft);
    ui->cbCopyParaData->setFont(Ft);
    ui->cbCopySpeedData->setFont(Ft);

    ui->tbnCancel->setVisible(false);
    ui->tbnOK->setVisible(false);

    ui->le19->setText(tr("0"));
    ui->le19_2->setText(tr("0.7"));

    ui->le1_2->setText(tr("1"));
    ui->le2_2->setText(tr("1"));
    ui->le3_2->setText(tr("1"));
    ui->le4_2->setText(tr("1"));
    ui->le5_2->setText(tr("1"));
    ui->le6_2->setText(tr("1"));

    ui->le7_2->setText(tr("1"));
    ui->le8_2->setText(tr("1"));
    ui->le9_2->setText(tr("1"));
    ui->le10_2->setText(tr("1"));
    ui->le11_2->setText(tr("1"));
    ui->le12_2->setText(tr("1"));

    ui->le13_2->setText(tr("1"));
    ui->le14_2->setText(tr("1"));
    ui->le15_2->setText(tr("1"));

    ui->le16_2->setText(tr("1"));
    ui->le17_2->setText(tr("1"));
    ui->le18_2->setText(tr("1"));

    ui->leNullDriftTime->setFont(Ft);
    ui->leDeviceAddress->setFont(Ft);
    ui->leStopQuality->setFont(Ft);
    ui->leStopTime->setFont(Ft);

    ui->le19->setVisible(false);
    ui->le19_2->setVisible(false);
    ui->label_25->setVisible(false);
    ui->label_40->setVisible(false);
}
void FCParameter::InitConnect()
{
    connect(ui->tbnNullDriftCalibration,SIGNAL(clicked(bool)),this,SLOT(NullDriftCalibration()));
    connect(ui->tbnRead,SIGNAL(clicked(bool)),this,SLOT(Read()));
    connect(ui->tbnWrite,SIGNAL(clicked(bool)),this,SLOT(Write()));
    connect(ui->leRange,SIGNAL(textEdited()),this,SLOT(WriteCalibrationPara()));
}
void FCParameter::Read()
{
    emit ReadLinearCalPara();
}

void FCParameter::Write()
{
    //流速段
    LinearCalPara.push_back(ui->le13->text().toFloat());
    LinearCalPara.push_back(ui->le14->text().toFloat());
    LinearCalPara.push_back(ui->le15->text().toFloat());

    LinearCalPara.push_back(ui->le1->text().toFloat());
    LinearCalPara.push_back(ui->le2->text().toFloat());
    LinearCalPara.push_back(ui->le3->text().toFloat());
    LinearCalPara.push_back(ui->le4->text().toFloat());
    LinearCalPara.push_back(ui->le5->text().toFloat());
    LinearCalPara.push_back(ui->le6->text().toFloat());

    LinearCalPara.push_back(ui->le19->text().toFloat());

    LinearCalPara.push_back(ui->le12->text().toFloat());
    LinearCalPara.push_back(ui->le11->text().toFloat());
    LinearCalPara.push_back(ui->le10->text().toFloat());
    LinearCalPara.push_back(ui->le9->text().toFloat());
    LinearCalPara.push_back(ui->le8->text().toFloat());
    LinearCalPara.push_back(ui->le7->text().toFloat());

    LinearCalPara.push_back(ui->le18->text().toFloat());
    LinearCalPara.push_back(ui->le17->text().toFloat());
    LinearCalPara.push_back(ui->le16->text().toFloat());

    //系数段
    LinearCalPara.push_back(ui->le13_2->text().toFloat());
    LinearCalPara.push_back(ui->le14_2->text().toFloat());
    LinearCalPara.push_back(ui->le15_2->text().toFloat());

    LinearCalPara.push_back(ui->le1_2->text().toFloat());
    LinearCalPara.push_back(ui->le2_2->text().toFloat());
    LinearCalPara.push_back(ui->le3_2->text().toFloat());
    LinearCalPara.push_back(ui->le4_2->text().toFloat());
    LinearCalPara.push_back(ui->le5_2->text().toFloat());
    LinearCalPara.push_back(ui->le6_2->text().toFloat());

    LinearCalPara.push_back(ui->le19_2->text().toFloat());

    LinearCalPara.push_back(ui->le12_2->text().toFloat());
    LinearCalPara.push_back(ui->le11_2->text().toFloat());
    LinearCalPara.push_back(ui->le10_2->text().toFloat());
    LinearCalPara.push_back(ui->le9_2->text().toFloat());

    LinearCalPara.push_back(ui->le8_2->text().toFloat());
    LinearCalPara.push_back(ui->le7_2->text().toFloat());

    LinearCalPara.push_back(ui->le18_2->text().toFloat());
    LinearCalPara.push_back(ui->le17_2->text().toFloat());
    LinearCalPara.push_back(ui->le16_2->text().toFloat());

    emit WriteLinearCalPara(LinearCalPara);

}
void FCParameter::RecLinearCalPara(QVector<float> TempPara)
{
    LinearCalPara=TempPara;
    //流速段
    ui->le1->setText(QString::number(LinearCalPara[3]));
    ui->le2->setText(QString::number(LinearCalPara[4]));
    ui->le3->setText(QString::number(LinearCalPara[5]));
    ui->le4->setText(QString::number(LinearCalPara[6]));
    ui->le5->setText(QString::number(LinearCalPara[7]));
    ui->le6->setText(QString::number(LinearCalPara[8]));

    ui->le7->setText(QString::number(LinearCalPara[15]));
    ui->le8->setText(QString::number(LinearCalPara[14]));
    ui->le9->setText(QString::number(LinearCalPara[13]));
    ui->le10->setText(QString::number(LinearCalPara[12]));
    ui->le11->setText(QString::number(LinearCalPara[11]));
    ui->le12->setText(QString::number(LinearCalPara[10]));

    ui->le13->setText(QString::number(LinearCalPara[0]));
    ui->le14->setText(QString::number(LinearCalPara[1]));
    ui->le15->setText(QString::number(LinearCalPara[2]));

    ui->le16->setText(QString::number(LinearCalPara[18]));
    ui->le17->setText(QString::number(LinearCalPara[17]));
    ui->le18->setText(QString::number(LinearCalPara[16]));

    ui->le19->setText(QString::number(LinearCalPara[9]));

    //系数段
    ui->le1_2->setText(QString::number(LinearCalPara[22]));
    ui->le2_2->setText(QString::number(LinearCalPara[23]));
    ui->le3_2->setText(QString::number(LinearCalPara[24]));
    ui->le4_2->setText(QString::number(LinearCalPara[25]));
    ui->le5_2->setText(QString::number(LinearCalPara[26]));
    ui->le6_2->setText(QString::number(LinearCalPara[27]));

    ui->le7_2->setText(QString::number(LinearCalPara[34]));
    ui->le8_2->setText(QString::number(LinearCalPara[33]));
    ui->le9_2->setText(QString::number(LinearCalPara[32]));
    ui->le10_2->setText(QString::number(LinearCalPara[31]));
    ui->le11_2->setText(QString::number(LinearCalPara[30]));
    ui->le12_2->setText(QString::number(LinearCalPara[29]));

    ui->le13_2->setText(QString::number(LinearCalPara[19]));
    ui->le14_2->setText(QString::number(LinearCalPara[20]));
    ui->le15_2->setText(QString::number(LinearCalPara[21]));

    ui->le16_2->setText(QString::number(LinearCalPara[37]));
    ui->le17_2->setText(QString::number(LinearCalPara[36]));
    ui->le18_2->setText(QString::number(LinearCalPara[35]));

    ui->le19_2->setText(QString::number(LinearCalPara[28]));

    LinearCalPara.clear();

}
void FCParameter::WriteCalibrationPara(QString RangePara)
{
    int range_para=RangePara.toInt();

    ui->le1->setText(QString::number(range_para));
    ui->le2->setText(QString::number(range_para*0.8));
    ui->le3->setText(QString::number(range_para*0.6));
    ui->le4->setText(QString::number(range_para*0.4));
    ui->le5->setText(QString::number(range_para*0.2));
    ui->le6->setText(QString::number(range_para*0.1));

    ui->le13->setText(QString::number(range_para*3));
    ui->le14->setText(QString::number(range_para*2));
    ui->le15->setText(QString::number(range_para*1.5));
    CopySpeedData();
}
void FCParameter::CopySpeedData()
{
    if(ui->cbCopySpeedData->isChecked())
    {
        ui->le7->setText(tr("-")+ui->le1->text());
        ui->le8->setText(tr("-")+ui->le2->text());
        ui->le9->setText(tr("-")+ui->le3->text());
        ui->le10->setText(tr("-")+ui->le4->text());
        ui->le11->setText(tr("-")+ui->le5->text());
        ui->le12->setText(tr("-")+ui->le6->text());

        ui->le16->setText(tr("-")+ui->le13->text());
        ui->le17->setText(tr("-")+ui->le14->text());
        ui->le18->setText(tr("-")+ui->le15->text());
    }
    else
    {
        ui->le7->setText(tr("0"));
        ui->le8->setText(tr("0"));
        ui->le9->setText(tr("0"));
        ui->le10->setText(tr("0"));
        ui->le11->setText(tr("0"));
        ui->le12->setText(tr("0"));

        ui->le16->setText(tr("0"));
        ui->le17->setText(tr("0"));
        ui->le18->setText(tr("0"));
    }
}
void FCParameter::CopyParaData()
{
    if(ui->cbCopyParaData->isChecked())
    {
        ui->le7_2->setText(ui->le1_2->text());
        ui->le8_2->setText(ui->le2_2->text());
        ui->le9_2->setText(ui->le3_2->text());
        ui->le10_2->setText(ui->le4_2->text());
        ui->le11_2->setText(ui->le5_2->text());
        ui->le12_2->setText(ui->le6_2->text());

        ui->le16_2->setText(ui->le13_2->text());
        ui->le17_2->setText(ui->le14_2->text());
        ui->le18_2->setText(ui->le15_2->text());
    }
    else
    {
        ui->le7_2->setText(tr("1"));
        ui->le8_2->setText(tr("1"));
        ui->le9_2->setText(tr("1"));
        ui->le10_2->setText(tr("1"));
        ui->le11_2->setText(tr("1"));
        ui->le12_2->setText(tr("1"));

        ui->le16_2->setText(tr("1"));
        ui->le17_2->setText(tr("1"));
        ui->le18_2->setText(tr("1"));
    }
}
void FCParameter::NullDriftCalibration()
{
    emit SendNullDriftCalibrationSignal(ui->leNullDriftTime->text());
    ui->tbnNullDriftCalibration->setEnabled(false);
    ui->leNullDriftTime->setEnabled(false);
}
void FCParameter::RecCalibrationInfo()
{
    ui->tbnNullDriftCalibration->setEnabled(true);
    ui->leNullDriftTime->setEnabled(true);
}
