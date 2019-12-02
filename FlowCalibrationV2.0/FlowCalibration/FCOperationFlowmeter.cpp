#include "FCOperationFlowmeter.h"
#include "ui_FCOperationFlowmeter.h"

FCOperationFlowmeter::FCOperationFlowmeter(QWidget *parent) :
    QWidget(parent),
    MySerialPort(new QSerialPort),
    MyTimer(new QTimer(this)),
    ShowTimer(new QTimer(this)),
    MyNextSerialPort(new QSerialPort),
    MyLastSerialPort(new QSerialPort),
    ui(new Ui::FCOperationFlowmeter)
{
    ui->setupUi(this);
    InitUI();
    InitConnect();
}

FCOperationFlowmeter::~FCOperationFlowmeter()
{
    delete ui;
}

void FCOperationFlowmeter::InitUI()
{
    #ifdef Developer
       ui->comboBoxComPort->setVisible(true);
    #else
      ui->comboBoxComPort->setVisible(false);
//      ui->tbnPlus->setVisible(false);
//      ui->tbnSubtract->setVisible(false);
//      ui->tbnAddress->setVisible(false);
//      ui->tbnFlowSpeedCalibration->setEnabled(false);
//      ui->leFlowSpeed->setEnabled(false);
//      ui->tbnFlowSpeedCalibration->setVisible(false);
//      ui->leFlowSpeed->setVisible(false);
//      ui->lbC->setVisible(false);
//      ui->label_13->setVisible(false);
    #endif

      QFont Ft("Microsoft YaHei");
      Ft.setPointSize(12);

      ui->MyCustomPlot->addGraph();
      ui->MyCustomPlot->graph(0)->setName(tr("累积流量 ml"));
      ui->MyCustomPlot->graph(0)->setPen(QPen(Qt::blue));

      ui->MyCustomPlot->addGraph();
      ui->MyCustomPlot->graph(1)->setName(tr("流速 ml/min"));
      ui->MyCustomPlot->graph(1)->setPen(QPen(Qt::red));

      ui->MyCustomPlot->addGraph();
      ui->MyCustomPlot->graph(2)->setName(tr("天平累积质量 g"));
      ui->MyCustomPlot->graph(2)->setPen(QPen(Qt::green));

      ui->MyCustomPlot->addGraph();
      ui->MyCustomPlot->graph(3)->setName(tr("计算流速 ml/min"));
      ui->MyCustomPlot->graph(3)->setPen(QPen(Qt::black));

      ui->MyCustomPlot->xAxis->setLabel(tr("X----采样点序列"));
      ui->MyCustomPlot->yAxis->setLabel(tr("Y----天平质量/g"));
      ui->MyCustomPlot->rescaleAxes(true);
      ui->MyCustomPlot->legend->setVisible(true);
      ui->MyCustomPlot->legend->setFont(QFont("Helvetica", 9));
      ui->MyCustomPlot->axisRect()->insetLayout()->setInsetAlignment(0,Qt::AlignTop|Qt::AlignLeft);
      //ui->MyCustomPlot->legend->addElement();
      ui->MyCustomPlot->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom|QCP::iSelectLegend|QCP::iSelectPlottables|QCP::iSelectAxes);

      ui->leCalculateFlow->setFont(Ft);
      ui->leDutyCycle->setFont(Ft);
      ui->leCalibrationTime->setFont(Ft);
      ui->leScaleDisplay->setFont(Ft);
      ui->leFlowSpeed->setFont(Ft);

      ui->leFlowDisplay_1->setFont(Ft);
      ui->leFlowDisplay_2->setFont(Ft);
      ui->leFlowDisplay_3->setFont(Ft);
      ui->leFlowDisplay_4->setFont(Ft);
      ui->leFlowDisplay_5->setFont(Ft);
      ui->leFlowDisplay_6->setFont(Ft);
      ui->leFlowDisplay_7->setFont(Ft);
      ui->leFlowDisplay_8->setFont(Ft);
      ui->leFlowDisplay_9->setFont(Ft);

      ui->lb1->setFont(Ft);
      ui->lb2->setFont(Ft);
      ui->lb3->setFont(Ft);
      ui->lb4->setFont(Ft);
      ui->lb5->setFont(Ft);
      ui->lb6->setFont(Ft);
      ui->lb7->setFont(Ft);
      ui->lb8->setFont(Ft);
      ui->lb9->setFont(Ft);
      ui->lb10->setFont(Ft);
      ui->lb11->setFont(Ft);
      ui->lb12->setFont(Ft);
      ui->lb13->setFont(Ft);
      ui->lb14->setFont(Ft);
      ui->lb15->setFont(Ft);
      ui->lb16->setFont(Ft);
      ui->lb17->setFont(Ft);
      ui->lb18->setFont(Ft);
      ui->lb19->setFont(Ft);


      ui->tbnConnect->setFont(Ft);
      ui->tbnConnect->setAutoRaise(true);
      ui->tbnConnect->setIcon(ImageFileConnectClose);
      ui->tbnConnect->setIconSize(ImageFileConnectClose.size());
      ui->tbnConnect->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

      ui->tbnOpen->setFont(Ft);
      ui->tbnOpen->setAutoRaise(true);
      ui->tbnOpen->setIcon(ImageFileClose);
      ui->tbnOpen->setIconSize(ImageFileClose.size());
      ui->tbnOpen->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

      ui->tbnClearWave->setFont(Ft);
      ui->tbnClearWave->setAutoRaise(true);
      ui->tbnClearWave->setIcon(ImageFileClearWaves);
      ui->tbnClearWave->setIconSize(ImageFileClearWaves.size());
      ui->tbnClearWave->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

      ui->tbnReset->setFont(Ft);
      ui->tbnReset->setAutoRaise(true);
      ui->tbnReset->setIcon(ImageFileReset);
      ui->tbnReset->setIconSize(ImageFileReset.size());
      ui->tbnReset->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

      ui->tbnFlowSpeedCalibration->setFont(Ft);
      ui->tbnFlowSpeedCalibration->setAutoRaise(true);
      ui->tbnFlowSpeedCalibration->setIcon(ImageFileCalibration);
      ui->tbnFlowSpeedCalibration->setIconSize(ImageFileCalibration.size());
      ui->tbnFlowSpeedCalibration->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

      ui->tbnMeasure->setFont(Ft);
      ui->tbnMeasure->setAutoRaise(true);
      ui->tbnMeasure->setIcon(ImageFileStart);
      ui->tbnMeasure->setIconSize(ImageFileStart.size());
      ui->tbnMeasure->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

      ui->tbnCalculateConst->setFont(Ft);
      ui->tbnCalculateConst->setAutoRaise(true);
      ui->tbnCalculateConst->setIcon(ImageFileCalibration);
      ui->tbnCalculateConst->setIconSize(ImageFileCalibration.size());
      ui->tbnCalculateConst->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

      ui->tbnWriteConst->setFont(Ft);
      ui->tbnWriteConst->setAutoRaise(true);
      ui->tbnWriteConst->setIcon(ImageFileWrite);
      ui->tbnWriteConst->setIconSize(ImageFileWrite.size());
      ui->tbnWriteConst->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

      ui->cbInvert->setFont(Ft);


      MeasureFlag=false;
      FirstMeasureFlag=false;

      ConnectTimes=0;
      ConnectNextTimes=0;
      ConnectLastTimes=0;

      ConnectFlag=false;
      ConnectNextFlag=false;
      ConnectLastFlag=false;

      WaveNum=0;
      LastQuality=0;
      SumQuality=0;

      CurrentFlowSpeed = 0;
      SetFlowSpeed = 0;
      FlowSpeedFlag = false;
      FlowStopFlag = false;
      FlowCalibrationFlag=false;
      SetAdjustTime = 0;

      CalibrationTimeFlag=false;
      SwitchFlag=false;
      AutoStopFlag=false;

      CalibrationTime="0";
      ui->leCalibrationTime->setText(CalibrationTime);
      QPalette pe;
      pe.setColor(QPalette::WindowText,Qt::red);
      ui->leCalibrationTime->setPalette(pe);
      Refresh();

}
/***********************************************************************************************************
 函数名：InitConnect()
 函数功能：控件信号和槽函数的连接
 函数参数：无
 函数返回值：无
************************************************************************************************************/
void FCOperationFlowmeter::InitConnect()
{
    connect(ui->tbnConnect,SIGNAL(clicked(bool)),this,SLOT(ConnectComport()));

    connect(MyTimer,SIGNAL(timeout()),this,SLOT(TimerUpdate()));
    connect(ShowTimer,SIGNAL(timeout()),this,SLOT(ShowCalibrationTime()));

    connect(MySerialPort,SIGNAL(readyRead()),this,SLOT(ReadRecData()));
    connect(MyNextSerialPort,SIGNAL(readyRead()),this,SLOT(ReadNextRecData()));
    connect(MyLastSerialPort,SIGNAL(readyRead()),this,SLOT(ReadLastRecData()));

    connect(this,SIGNAL(FindNextComport()),this,SLOT(ConnectNextComport()));
    connect(this,SIGNAL(FindLastComport()),this,SLOT(ConnectLastComport()));

    connect(ui->tbnOpen,SIGNAL(clicked(bool)),this,SLOT(Switch()));

    connect(ui->tbnMeasure,SIGNAL(clicked(bool)),this,SLOT(Measure()));
    connect(ui->tbnClearWave,SIGNAL(clicked(bool)),this,SLOT(ClearWaves()));
    connect(ui->tbnReset,SIGNAL(clicked(bool)),this,SLOT(Reset()));

    connect(ui->tbnFlowSpeedCalibration,SIGNAL(clicked(bool)),this,SLOT(FlowSpeedCalibration()));
    connect(ui->tbnCalculateConst,SIGNAL(clicked(bool)),this,SLOT(CalculateConst()));
    connect(ui->tbnWriteConst,SIGNAL(clicked(bool)),this,SLOT(WriteConst()));
}
/***********************************************************************************************************
 函数名：Refresh()
 函数功能：端口的刷新
 函数参数：无
 函数返回值：无
************************************************************************************************************/
void FCOperationFlowmeter::Refresh()
{
    QList <QSerialPortInfo> InfoList = QSerialPortInfo::availablePorts();
    ui->comboBoxComPort->clear();
    if(InfoList.isEmpty())
        ShowMessage(tr("未找到可用的端口"),1500);
    else
    {
        foreach(QSerialPortInfo Info,InfoList)
            ui->comboBoxComPort->addItem(Info.portName() + ' ' + Info.description());
    }
}
/***********************************************************************************************************
 函数名：ConnectComport()
 函数功能：485端口的搜索，会自动进行端口的刷新，连续搜索三次无果够自动退出，并提示用户端口找不到
 函数参数：无
 函数返回值：无
 注意事项：多端口打开一定要注意，控件文本的修改一定是最后的Com口修改，否则影响端口的查找。
************************************************************************************************************/
void FCOperationFlowmeter::ConnectComport()
{
    QString PortName;
    static uint8_t PortCount=0;
    if(ConnectTimes<=ConnectMaxTimes)
    {
        if(ui->tbnConnect->text()==tr("连接设备"))
        {
            if(PortCount>=ui->comboBoxComPort->count())     //所有端口都判断，而且总共轮询ConnectMaxTimes次
            {
                 PortCount=0;
                 Refresh();
                 ConnectTimes++;
            }
            ui->comboBoxComPort->setCurrentIndex(PortCount);
            PortName=ui->comboBoxComPort->currentText().split(' ').first();
            if(MySerialPort->isOpen())                   //判断该串口总线是否被占用，并不是Com端口是否被占用
            {
                MySerialPort->close();
                ShowMessage(MySerialPort->portName()+"(天平)"+tr("端口已关闭"),1000);
                ShowParameter(tr("无"),tr("无"));
                return;
            }
            else
            {
                MySerialPort->setPortName(PortName);
                PortCount++;
                if(MySerialPort->open(QIODevice::ReadWrite))   //判断Com口是否打开
                {
                     //ShowMessage(PortName+tr("端口状态:")+QString::number(MySerialPort->isOpen())+tr(" ")+tr("SerialPort Open Successfully!"),3000);
                     MySerialPort->setBaudRate(9600);
                     MySerialPort->setDataBits(QSerialPort::Data8);
                     MySerialPort->setParity(QSerialPort::NoParity);
                     MySerialPort->setStopBits(QSerialPort::OneStop);
                     MySerialPort->setFlowControl(QSerialPort::NoFlowControl);
                     QByteArray Indentifier;
                     Indentifier.resize(2);
                     Indentifier[0]=0x1B;
                     Indentifier[1]=0x70;
                     WriteBytes(Indentifier);
                     MyTimer->start(300);
                     ConnectFlag=true;
                }
                else                            //如果打开，则直接返回。
                {
                    ShowMessage(PortName+"(天平)"+tr("打开失败，端口可能被占用！")+tr("串口状态:")+QString::number(MySerialPort->isOpen()),2000);
                    return;
                }
            }
        }
        else
        {

            MySerialPort->close();
            //ui->tbnConnect->setText(tr("连接"));
            //ui->tbnConnect->setIcon(ImageFileConnectClose);
            PortCount=0;
            ShowMessage(MySerialPort->portName()+"(天平)"+tr("已断开"),1500);
            ShowParameter(tr("无"),tr("无"));
            emit FindNextComport();
        }
    }
    else
    {
        MyTimer->stop();
        ConnectFlag=0;
        ConnectTimes=0;
        ShowMessage(tr("PC端口未响应，请检查设备是否插入！"),1000);
    }
}
/***********************************************************************************************************
 函数名：ConnectNextComport()
 函数功能：USART-TTL端口的搜索，会自动进行端口的刷新，连续搜索三次无果够自动退出，并提示用户端口找不到
          波特率9600，每次发数据总会有返回值，不管指令是否合法，所以
 函数参数：无
 函数返回值：无
************************************************************************************************************/
void FCOperationFlowmeter::ConnectNextComport()
{
    QString PortName;
    static uint8_t NextPortCount=0;
    if(ConnectNextTimes<=ConnectMaxTimes)
    {
        if(ui->tbnConnect->text()==tr("连接设备"))
        {
            if(NextPortCount>=ui->comboBoxComPort->count())
            {
                 NextPortCount=0;
                 Refresh();
                 ConnectNextTimes++;
            }
            ui->comboBoxComPort->setCurrentIndex(NextPortCount);
            PortName=ui->comboBoxComPort->currentText().split(' ').first();
            if(MyNextSerialPort->isOpen())
            {
                MyNextSerialPort->close();
                  ShowMessage(MyNextSerialPort->portName()+"(PWM)"+tr("端口已关闭"),1000);
                  ShowNextParameter(tr("无"),tr("无"));
                return;
            }
            else
            {
                MyNextSerialPort->setPortName(PortName);
                NextPortCount++;
                if(MyNextSerialPort->open(QIODevice::ReadWrite))
                {
                     //ShowMessage(PortName+tr("端口状态:")+QString::number(MySerialPort->isOpen())+tr(" ")+tr("SerialPort Open Successfully!"),3000);
                     MyNextSerialPort->setBaudRate(9600);
                     MyNextSerialPort->setDataBits(QSerialPort::Data8);
                     MyNextSerialPort->setParity(QSerialPort::NoParity);
                     MyNextSerialPort->setStopBits(QSerialPort::OneStop);
                     MyNextSerialPort->setFlowControl(QSerialPort::NoFlowControl);
                     QByteArray Indentifier;
                     Indentifier.resize(4);
                     Indentifier[0]=0x44;
                     Indentifier[1]=0x30;
                     Indentifier[2]=0x30;
                     Indentifier[3]=0x30;
                     NextWriteBytes(Indentifier);
                     MyTimer->start(300);
                     ConnectNextFlag=true;
                }
                else
                {
                    ShowMessage(PortName+"(PWM)"+tr("打开失败，端口可能被占用！")+tr("串口状态:")+QString::number(MyNextSerialPort->isOpen()),2000);
                    return;
                }
            }
        }
        else
        {

            MyNextSerialPort->close();
            //ui->tbnConnect->setText(tr("连接"));
            //ui->tbnConnect->setIcon(ImageFileConnectClose);
            NextPortCount=0;
            ShowMessage(MyNextSerialPort->portName()+"(PWM)"+tr("已断开"),1500);
            ShowNextParameter(tr("无"),tr("无"));
            emit FindLastComport();

        }
    }
    else
    {
        MyTimer->stop();
        ConnectNextFlag=false;
        ConnectNextTimes=0;
        ShowMessage(tr("PC端口未响应，请检查设备是否插入！"),1000);
    }
}
/***********************************************************************************************************
 函数名：ConnectLastComport()
 函数功能：RS485流量计端口的搜索，会自动进行端口的刷新，连续搜索三次无果够自动退出，并提示用户端口找不到
 函数参数：无
 函数返回值：无
************************************************************************************************************/
void FCOperationFlowmeter::ConnectLastComport()
{
    QString PortName;
    static uint8_t LastPortCount=0;
    if(ConnectLastTimes<=ConnectMaxTimes)
    {
        if(ui->tbnConnect->text()==tr("连接设备"))
        {
            if(LastPortCount>=ui->comboBoxComPort->count())
            {
                 LastPortCount=0;
                 Refresh();
                 ConnectLastTimes++;
            }
            ui->comboBoxComPort->setCurrentIndex(LastPortCount);
            PortName=ui->comboBoxComPort->currentText().split(' ').first();
            if(MyLastSerialPort->isOpen())
            {
                  MyLastSerialPort->close();
                  ShowMessage(MyLastSerialPort->portName()+"(流量计)"+tr("端口已关闭"),1000);
                  ShowLastParameter(tr("无"),tr("无"));
                return;
            }
            else
            {
                MyLastSerialPort->setPortName(PortName);
                LastPortCount++;
                MyTimer->start(300);
                ConnectLastFlag=true;
                if(MyLastSerialPort->open(QIODevice::ReadWrite))
                {
                     //ShowMessage(PortName+tr("端口状态:")+QString::number(MySerialPort->isOpen())+tr(" ")+tr("SerialPort Open Successfully!"),3000);
                     MyLastSerialPort->setBaudRate(115200);
                     MyLastSerialPort->setDataBits(QSerialPort::Data8);
                     MyLastSerialPort->setParity(QSerialPort::NoParity);
                     MyLastSerialPort->setStopBits(QSerialPort::OneStop);
                     MyLastSerialPort->setFlowControl(QSerialPort::NoFlowControl);
                     QByteArray Indentifier;
                     Indentifier.resize(4);

                     Indentifier[0]=DeviceAddr;
                     Indentifier[1]=0x06;

                     Indentifier[2]=0x00;
                     Indentifier[3]=0xE8;

                     Indentifier[4]=0x00;
                     Indentifier[5]=0x01;

                     quint16 CRC16Value = CRC16Check(Indentifier,8);

                     Indentifier[6]=CRC16Value%256;
                     Indentifier[7]=CRC16Value/256;
                     LastWriteBytes(Indentifier);
                }
                else
                {
                    ShowMessage(PortName+"(流量计)"+tr("打开失败，端口可能被占用！")+tr("串口状态:")+QString::number(MyLastSerialPort->isOpen()),2000);
                    return;
                }
            }
        }
        else
        {

            MyLastSerialPort->close();
            ui->tbnConnect->setText(tr("连接设备"));
            ui->tbnConnect->setIcon(ImageFileConnectClose);
            LastPortCount=0;
            ShowMessage(MyLastSerialPort->portName()+"(流量计)"+tr("已断开"),1500);
            ShowLastParameter(tr("无"),tr("无"));
        }
    }
    else
    {
        MyTimer->stop();
        ConnectLastFlag=false;
        ConnectLastTimes=0;
        ShowMessage(tr("PC端口未响应，请检查设备是否插入！"),1000);
    }
}
/***********************************************************************************************************
 函数名：WriteBytes(QByteArray Data)
 函数功能：485端口数据的写入
 函数参数：QByteArray Data，写入数据
 函数返回值：无
************************************************************************************************************/
void FCOperationFlowmeter::WriteBytes(QByteArray Data)
{
    if(MySerialPort->isOpen())
    {
        MySerialPort->write(Data);
    }
    else
    {
        ShowMessage(ui->comboBoxComPort->currentText().split(' ').first()+tr("端口未打开，不能发送数据！"),2000);
    }
}
/***********************************************************************************************************
 函数名：NextWriteBytes(QByteArray Data)
 函数功能：USART-TTL端口数据的写入
 函数参数：QByteArray Data，写入数据
 函数返回值：无
************************************************************************************************************/
void FCOperationFlowmeter::NextWriteBytes(QByteArray Data)
{
    if(MyNextSerialPort->isOpen())
    {
        MyNextSerialPort->write(Data);
    }
    else
    {
        ShowMessage(ui->comboBoxComPort->currentText().split(' ').first()+tr("端口未打开，不能发送数据！"),2000);
    }
}
/***********************************************************************************************************
 函数名：LastWriteBytes(QByteArray Data)
 函数功能：RS485流量计端口数据的写入
 函数参数：QByteArray Data，写入数据
 函数返回值：无
************************************************************************************************************/
void FCOperationFlowmeter::LastWriteBytes(QByteArray Data)
{
    if(MyLastSerialPort->isOpen())
    {
        MyLastSerialPort->write(Data);
    }
    else
    {
        ShowMessage(ui->comboBoxComPort->currentText().split(' ').first()+tr("端口未打开，不能发送数据！"),1000);
    }
}

/***********************************************************************************************************
 函数名：ReadRecData（）
 函数功能：读485端口的数据
 函数参数：无
 函数返回值：无
************************************************************************************************************/
void FCOperationFlowmeter::ReadRecData()
{
    while(MySerialPort->waitForReadyRead(10));
    QByteArray RecData=MySerialPort->readAll();  //读取接收数据
    RunCommand(RecData);
}
/***********************************************************************************************************
 函数名：ReadNextRecData（）
 函数功能：读USART-TTL端口的数据
 函数参数：无
 函数返回值：无
************************************************************************************************************/
void FCOperationFlowmeter::ReadNextRecData()
{
    while(MyNextSerialPort->waitForReadyRead(10));
    QByteArray RecData=MyNextSerialPort->readAll();  //读取接收数据
    RunNextCommand(RecData);
}
/***********************************************************************************************************
 函数名：ReadNextRecData（）
 函数功能：读USART-TTL端口的数据
 函数参数：无
 函数返回值：无
************************************************************************************************************/
void FCOperationFlowmeter::ReadLastRecData()
{
    while(MyLastSerialPort->waitForReadyRead(10));
    QByteArray RecData=MyLastSerialPort->readAll();  //读取接收数据
    RunLastCommand(RecData);
}
/***********************************************************************************************************
 函数名：TimerUpdate()
 函数功能：定时器更新函数，负责端口的自动搜索和天平示数的读取
 函数参数：QByteArray Data，写入数据
 函数返回值：无
************************************************************************************************************/
void FCOperationFlowmeter::TimerUpdate()
{
    if(ConnectFlag)
    {
        ShowMessage(ui->comboBoxComPort->currentText().split(' ').first()+tr("端口未响应!"),1000);
        MySerialPort->close();
        emit ui->tbnConnect->click();
    }
    if(ConnectNextFlag)
    {
        ShowMessage(ui->comboBoxComPort->currentText().split(' ').first()+tr("端口未响应!"),1000);
        MyNextSerialPort->close();
        emit FindNextComport();
    }
    if(ConnectLastFlag)
    {
        ShowMessage(ui->comboBoxComPort->currentText().split(' ').first()+tr("端口未响应!"),1000);
        MyLastSerialPort->close();
        emit FindLastComport();
    }
    if(MeasureFlag)
    {
        static bool ChangeFlag=false;

        if(ChangeFlag)
        {
            QByteArray Indentifier;
            Indentifier.resize(2);
            Indentifier[0]=0x1B;
            Indentifier[1]=0x70;
            WriteBytes(Indentifier);
        }
        else
        {
            QByteArray Indentifier;

            Indentifier[0]=DeviceAddr;
            Indentifier[1]=0x03;

            Indentifier[2]=0x00;
            Indentifier[3]=0x97;

            Indentifier[4]=0x00;
            Indentifier[5]=0x0E;

            quint16 CRCValue = CRC16Check(Indentifier,8);

            Indentifier[6]=CRCValue%256;
            Indentifier[7]=CRCValue/256;

            LastWriteBytes(Indentifier);
        }
        ChangeFlag=!ChangeFlag;

        if(FlowStopFlag)
        {
            static quint16 StopCount=0;

            if(StopCount==4)
            {

                MeasureFlag=false;
                MyTimer->stop();
                FlowStopFlag=false;
                StopCount=0;
                ShowTimer->stop();
                CalibrationTimeFlag=false;
                AutoStopFlag=false;
                //Sleep(1);
                CalculateConst();
            }
            else
                StopCount++;
        }
    }
}
void FCOperationFlowmeter::ShowCalibrationTime()
{
    if(CalibrationTimeFlag)
    {
        int Sec = CalibrationTime.toInt();
        Sec++;
        CalibrationTime = QString("%1").arg(Sec);
        ui->leCalibrationTime->setText(CalibrationTime);
    }
}

/***********************************************************************************************************
 函数名：RunCommand()
 函数功能：处理485端口数据，包括天平、485控制器以及流量计协议（暂时未加入）
 函数参数：QByteArray Data，处理数据
 函数返回值：无
************************************************************************************************************/
void FCOperationFlowmeter::RunCommand(QByteArray RecData)
{
    switch (RecData[0]) {
    case 0x20:
    {
       if(ConnectFlag)
       {
           qDebug()<<"连接成功！";
           MyTimer->stop();
           ShowMessage(ui->comboBoxComPort->currentText().split(' ').first()+tr("端口打开成功！"),5000);
           ShowParameter(ui->comboBoxComPort->currentText().split(' ').first()+"(天平)",tr("9600"));
           //ui->tbnConnect->setText(tr("断开"));
           //ui->tbnConnect->setIcon(ImageFileConnectOpen);
           ConnectFlag=false;
           ConnectTimes=0;
           //Refresh();
           emit FindNextComport();
       }
       else
       {
           double Quality=0;

           if(RecData[3]!=0x20)
           {
               Quality+=(RecData[3]-0x30)*1000;
           }
           if(RecData[4]!=0x20)
           {
               Quality+=(RecData[4]-0x30)*100;
           }
           if(RecData[5]!=0x20)
           {
               Quality+=(RecData[5]-0x30)*10;
           }
           if(RecData[6]!=0x20)
           {
               Quality+=(RecData[6]-0x30);
           }
           if(RecData[8]!=0x20)
           {
               Quality+=(double)(RecData[8]-0x30)/10.0;
           }

           //WaveNum+=1;
           CurrentFlowSpeed=(Quality-LastQuality)*Minute;
           if(ui->cbInvert->isChecked())
           {
             ui->MyCustomPlot->graph(2)->addData(WaveNum,Quality*-1);
             ui->MyCustomPlot->graph(3)->addData(WaveNum,CurrentFlowSpeed*-1);
           }
           else
           {
              ui->MyCustomPlot->graph(2)->addData(WaveNum,Quality);
              ui->MyCustomPlot->graph(3)->addData(WaveNum,CurrentFlowSpeed);

           }
           ui->leScaleDisplay->setText(QString::number(Quality));
           ui->leCalculateFlow->setText(QString::number(CurrentFlowSpeed));

           ui->MyCustomPlot->replot();
           ui->MyCustomPlot->rescaleAxes(true);
           if(MeasureFlag==true)
           WaveNum+=1;
           int Sec=CalibrationTime.toInt();
           if(((Sec>120)||(Quality>2000))&&(AutoStopFlag==false))
           {
                Measure();
                AutoStopFlag=true;
           }

           if(FlowSpeedFlag)
           {
               if(SetAdjustTime==PIDTime)
               {
                   SetAdjustTime=0;
                   SetFlowSpeed=ui->leFlowSpeed->text().toDouble();
                   if((SetFlowSpeed-CurrentFlowSpeed)>180)
                   {
                       SetDutyCyeleAddValue(6);
                   }
                   else if(((SetFlowSpeed-CurrentFlowSpeed)>150)&((SetFlowSpeed-CurrentFlowSpeed)<180))
                   {
                       SetDutyCyeleAddValue(5);
                   }
                   else if(((SetFlowSpeed-CurrentFlowSpeed)>120)&((SetFlowSpeed-CurrentFlowSpeed)<150))
                   {
                       SetDutyCyeleAddValue(4);
                   }
                   else if(((SetFlowSpeed-CurrentFlowSpeed)>90)&((SetFlowSpeed-CurrentFlowSpeed)<120))
                   {
                       SetDutyCyeleAddValue(3);
                   }
                   else if(((SetFlowSpeed-CurrentFlowSpeed)>60)&((SetFlowSpeed-CurrentFlowSpeed)<90))
                   {
                       SetDutyCyeleAddValue(2);
                   }
                   else if(((SetFlowSpeed-CurrentFlowSpeed)>30)&((SetFlowSpeed-CurrentFlowSpeed)<60))
                   {
                       SetDutyCyeleAddValue(1);
                   }
                   else if(((SetFlowSpeed-CurrentFlowSpeed)>-60)&((SetFlowSpeed-CurrentFlowSpeed)<-30))
                   {
                      SetDutyCyeleAddValue(-1);
                   }
                   else if(((SetFlowSpeed-CurrentFlowSpeed)>-90)&((SetFlowSpeed-CurrentFlowSpeed)<-60))
                   {
                      SetDutyCyeleAddValue(-2);
                   }
                   else if(((SetFlowSpeed-CurrentFlowSpeed)>-120)&((SetFlowSpeed-CurrentFlowSpeed)<-90))
                   {
                      SetDutyCyeleAddValue(-3);
                   }
                   else if(((SetFlowSpeed-CurrentFlowSpeed)>-150)&((SetFlowSpeed-CurrentFlowSpeed)<-120))
                   {
                      SetDutyCyeleAddValue(-4);
                   }
                   else if(((SetFlowSpeed-CurrentFlowSpeed)>-180)&((SetFlowSpeed-CurrentFlowSpeed)<-150))
                   {
                      SetDutyCyeleAddValue(-5);
                   }
                   else if(((SetFlowSpeed-CurrentFlowSpeed)<-180))
                   {
                      SetDutyCyeleAddValue(-6);
                   }
                   else
                   {

                   }
               }
               else
               {
                   SetAdjustTime++;
               }
           }
           if(!FirstMeasureFlag)
           {
               FirstMeasureFlag=false;
               SumQuality+=(Quality-LastQuality);
//               ui->leSumQuality->setText(QString::number(SumQuality));
           }
           LastQuality=Quality;
       }
    }
        break;
    case 0x2D:
    {
        if(ConnectFlag)
        {
            qDebug()<<"连接成功！";
            MyTimer->stop();
            ShowMessage(ui->comboBoxComPort->currentText().split(' ').first()+tr("端口打开成功！"),5000);
            ShowParameter(ui->comboBoxComPort->currentText().split(' ').first()+"(天平)",tr("9600"));
            //ui->tbnConnect->setText(tr("断开"));
            //ui->tbnConnect->setIcon(ImageFileConnectOpen);
            ConnectFlag=false;
            ConnectTimes=0;
            emit FindNextComport();
        }
        else
        {
            double Quality=0;

            if(RecData[3]!=0x20)
            {
                Quality+=(RecData[3]-0x30)*1000;
            }
            if(RecData[4]!=0x20)
            {
                Quality+=(RecData[4]-0x30)*100;
            }
            if(RecData[5]!=0x20)
            {
                Quality+=(RecData[5]-0x30)*10;
            }
            if(RecData[6]!=0x20)
            {
                Quality+=(RecData[6]-0x30);
            }
            if(RecData[8]!=0x20)
            {
                Quality+=(double)(RecData[8]-0x30)/10.0;
            }
            Quality=Quality*(-1);
            ui->leScaleDisplay->setText(QString::number(Quality));
            ui->MyCustomPlot->graph(2)->addData(WaveNum,Quality);
            ui->MyCustomPlot->replot();
            ui->MyCustomPlot->rescaleAxes(true);
            //WaveNum+=1;

            CurrentFlowSpeed=(Quality-LastQuality)*Minute;
            ui->leCalculateFlow->setText(QString::number(CurrentFlowSpeed));
            ui->MyCustomPlot->graph(3)->addData(WaveNum,CurrentFlowSpeed);
            ui->MyCustomPlot->replot();

            //ui->leCalculateFlow->setText(QString::number((Quality-LastQuality)*Minute));
            //ui->MyCustomPlot->graph(3)->addData(WaveNum,(Quality-LastQuality)*Minute);
            //ui->MyCustomPlot->replot();

            if(MeasureFlag==true)
            WaveNum+=1;

            int Sec=CalibrationTime.toInt();
            if(((Sec>120)||(Quality>2000))&&(AutoStopFlag==false))
            {
                 Measure();
                 AutoStopFlag=true;
            }
            if(FlowSpeedFlag)
            {
                if(SetAdjustTime==PIDTime)
                {
                    SetAdjustTime=0;
                    SetFlowSpeed=ui->leFlowSpeed->text().toDouble();
                    if((SetFlowSpeed-CurrentFlowSpeed)>180)
                    {
                        SetDutyCyeleAddValue(7);
                    }
                    else if(((SetFlowSpeed-CurrentFlowSpeed)>120)&((SetFlowSpeed-CurrentFlowSpeed)<180))
                    {
                        SetDutyCyeleAddValue(5);
                    }
                    else if(((SetFlowSpeed-CurrentFlowSpeed)>60)&((SetFlowSpeed-CurrentFlowSpeed)<120))
                    {
                        SetDutyCyeleAddValue(3);
                    }
                    else if(((SetFlowSpeed-CurrentFlowSpeed)>-120)&((SetFlowSpeed-CurrentFlowSpeed)<-60))
                    {
                       SetDutyCyeleAddValue(-3);
                    }
                    else if(((SetFlowSpeed-CurrentFlowSpeed)>-180)&((SetFlowSpeed-CurrentFlowSpeed)<-120))
                    {
                       SetDutyCyeleAddValue(-5);
                    }
                    else if(((SetFlowSpeed-CurrentFlowSpeed)<-180))
                    {
                       SetDutyCyeleAddValue(-7);
                    }
                    else
                    {
                       SetDutyCyeleAddValue(0);
                    }
                }
                else
                {
                    SetAdjustTime++;
                }
            }

            if(!FirstMeasureFlag)
            {
                FirstMeasureFlag=false;
                SumQuality+=(Quality-LastQuality);
//                ui->leSumQuality->setText(QString::number(SumQuality));
            }
            LastQuality=Quality;
        }
    }
        break;
    case 0x22:
    {
         if(RecData[2]==0x11)
         {
             ShowMessage(tr("放水成功"),1000);
         }
         else if(RecData[2]==0x12)
         {
             ShowMessage(tr("放水停止"),1000);
         }
    }
        break;
    default:
        {

        }
        break;
    }
}
/***********************************************************************************************************
 函数名：RunNextCommand()
 函数功能：处理USART--TTL端口数据，负责水泵电机的转速控制
 函数参数：QByteArray Data，处理数据
 函数返回值：无
************************************************************************************************************/
void FCOperationFlowmeter::RunNextCommand(QByteArray RecData)
{
    switch (RecData[0])
    {
    case 0x44:
    {
        if(ConnectNextFlag==true)
        {
            qDebug()<<"连接成功！";
            MyTimer->stop();
            ShowMessage(ui->comboBoxComPort->currentText().split(' ').first()+tr("端口打开成功！"),5000);
            ShowNextParameter(ui->comboBoxComPort->currentText().split(' ').first()+"(PWM)",tr("9600"));
            //ui->tbnConnect->setText(tr("断开"));
            //ui->tbnConnect->setIcon(ImageFileConnectOpen);
            ConnectNextFlag=false;
            ConnectNextTimes=0;
            //Refresh();
            //DutyCycleDown();
            emit FindLastComport();
        }
        else
        {
            ShowMessage(tr("参数设置成功"),1000);
        }
    }
        break;
    default:
        break;
    }
}
/***********************************************************************************************************
 函数名：RunNextCommand()
 函数功能：处理USART--TTL端口数据，负责水泵电机的转速控制
 函数参数：QByteArray Data，处理数据
 函数返回值：无
************************************************************************************************************/
void FCOperationFlowmeter::RunLastCommand(QByteArray RecData)
{
    switch (RecData[0])
    {
        case DeviceAddr:
        {
            if(ConnectLastFlag==true)
            {
                qDebug()<<"连接成功！";
                MyTimer->stop();
                ShowMessage(ui->comboBoxComPort->currentText().split(' ').first()+tr("端口打开成功！"),5000);
                ShowLastParameter(ui->comboBoxComPort->currentText().split(' ').first()+"(流量计)",tr("115200"));
                ui->tbnConnect->setText(tr("断开"));
                ui->tbnConnect->setIcon(ImageFileConnectOpen);
                ConnectLastFlag=false;
                ConnectLastTimes=0;
                //DutyCycleDown();
            }
            else
            {
                 //ShowMessage(tr("参数设置成功"),1000);
                  switch(RecData[1])
                  {
                        case 0x03:
                      {
                         quint16 ByteNum = RecData[2];

                         #if Debug
                            qDebug() << ByteNum;
                         #endif
                         if(ByteNum==28)
                         {
                             quint16 CRCValue = CRC16Check(RecData,33);
                             quint8 CRCHigh = RecData[32];
                             quint8 CRCLow = RecData[31];

                              if((CRCHigh*256+CRCLow)==CRCValue)
                              {
                                  quint8 TempStr[4];
                                  TempStr[0]= RecData[4];
                                  TempStr[1]= RecData[3];
                                  TempStr[2]= RecData[6];
                                  TempStr[3]= RecData[5];
                                  float FlowSum=0;
                                  memcpy(&FlowSum,TempStr,4);

                                  if(fabs(FlowSum)>0.0001)
                                  {
                                       if(MeasureFlag==true)
                                       {
                                           ui->leFlowDisplay_1->setText(QString::number(FlowSum));
                                           ui->MyCustomPlot->graph(0)->addData(WaveNum,FlowSum);
                                       }

                                  }
                                  //ui->MyCustomPlot->replot();
                                  //ui->MyCustomPlot->rescaleAxes(true);
                                  TempStr[0]= RecData[28];
                                  TempStr[1]= RecData[27];
                                  TempStr[2]= RecData[30];
                                  TempStr[3]= RecData[29];
                                  float FlowSpeed=0;
                                  memcpy(&FlowSpeed,TempStr,4);
                                  //if(fabs(FlowSpeed)>0.01)
                                  {
                                      if(MeasureFlag==true)
                                      {
                                          ui->leFlowDisplay_2->setText(QString::number(FlowSpeed));
                                          ui->MyCustomPlot->graph(1)->addData(WaveNum,FlowSpeed);
                                      }

                                      if(FlowCalibrationFlag)
                                      {
                                          if(SetAdjustTime==PIDTime)
                                          {
                                              SetAdjustTime=0;
                                              SetFlowSpeed=ui->leFlowSpeed->text().toDouble();

                                              CurrentFlowSpeed=FlowSpeed;

                                              if((SetFlowSpeed-CurrentFlowSpeed)>300)
                                              {
                                                  SetDutyCyeleAddValue(10);
                                              }
                                              else if(((SetFlowSpeed-CurrentFlowSpeed)>180)&&((SetFlowSpeed-CurrentFlowSpeed)<300))
                                              {
                                                  SetDutyCyeleAddValue(6);
                                              }
                                              else if(((SetFlowSpeed-CurrentFlowSpeed)>150)&((SetFlowSpeed-CurrentFlowSpeed)<180))
                                              {
                                                  SetDutyCyeleAddValue(5);
                                              }
                                              else if(((SetFlowSpeed-CurrentFlowSpeed)>120)&((SetFlowSpeed-CurrentFlowSpeed)<150))
                                              {
                                                  SetDutyCyeleAddValue(4);
                                              }
                                              else if(((SetFlowSpeed-CurrentFlowSpeed)>90)&((SetFlowSpeed-CurrentFlowSpeed)<120))
                                              {
                                                  SetDutyCyeleAddValue(3);
                                              }
                                              else if(((SetFlowSpeed-CurrentFlowSpeed)>60)&((SetFlowSpeed-CurrentFlowSpeed)<90))
                                              {
                                                  SetDutyCyeleAddValue(2);
                                              }
                                              else if(((SetFlowSpeed-CurrentFlowSpeed)>30)&((SetFlowSpeed-CurrentFlowSpeed)<60))
                                              {
                                                  SetDutyCyeleAddValue(1);
                                              }
                                              else if(((SetFlowSpeed-CurrentFlowSpeed)>-90)&((SetFlowSpeed-CurrentFlowSpeed)<-60))
                                              {
                                                 SetDutyCyeleAddValue(-1);
                                              }
                                              else if(((SetFlowSpeed-CurrentFlowSpeed)>-120)&((SetFlowSpeed-CurrentFlowSpeed)<-90))
                                              {
                                                 SetDutyCyeleAddValue(-2);
                                              }
                                              else if(((SetFlowSpeed-CurrentFlowSpeed)>-150)&((SetFlowSpeed-CurrentFlowSpeed)<-120))
                                              {
                                                 SetDutyCyeleAddValue(-3);
                                              }
                                              else if(((SetFlowSpeed-CurrentFlowSpeed)>-180)&((SetFlowSpeed-CurrentFlowSpeed)<-150))
                                              {
                                                 SetDutyCyeleAddValue(-4);
                                              }
                                              else if(((SetFlowSpeed-CurrentFlowSpeed)>-300)&&((SetFlowSpeed-CurrentFlowSpeed)<-180))
                                              {
                                                  SetDutyCyeleAddValue(-5);
                                              }
                                              else if(((SetFlowSpeed-CurrentFlowSpeed)<-300))
                                              {
                                                 SetDutyCyeleAddValue(-10);
                                              }
                                              else
                                              {

                                              }
                                          }
                                          else
                                          {
                                              SetAdjustTime++;
                                          }
                                      }
                                  }

                              }
                              else
                              {
                                  //if(MeasureFlag)
                                  //ShowMessage(tr("流量计数据校验错误!"),1000);
                              }
                         }
                         else if(ByteNum==4)
                         {
                             quint16 CRCValue = CRC16Check(RecData,9);
                             quint8 CRCHigh = RecData[8];
                             quint8 CRCLow = RecData[7];

                             if((CRCHigh*256+CRCLow)==CRCValue)
                             {
                                 ShowMessage(tr("常数C值读取成功"),1000);
                                 quint8 TempStr[4];
                                 TempStr[0]= RecData[4];
                                 TempStr[1]= RecData[3];
                                 TempStr[2]= RecData[6];
                                 TempStr[3]= RecData[5];
                                 float TempConst=0;
                                 memcpy(&TempConst,TempStr,4);

                                 float TempScaleDisplay = ui->leScaleDisplay->text().toFloat();
                                 float TempFlowSum = ui->leFlowDisplay_2->text().toFloat();

                                 TempConst=TempConst*(TempScaleDisplay/TempFlowSum);
                                 TempConst=fabs(TempConst);
                                 ui->leFlowDisplay_3->setText(QString::number(TempConst));
                             }
                         }
                         else if(ByteNum==76)
                         {
                             static quint8 EnterCount;
                             quint16 CRCValue = CRC16Check(RecData,81);
                             quint8 CRCHigh = RecData[80];
                             quint8 CRCLow = RecData[79];

                             quint8 TempStr[4];
                             float FlowSum=0;


                             if((CRCHigh*256+CRCLow)==CRCValue)
                             {
                                  for(quint8 i=3;i<79;i+=4)
                                  {
                                      TempStr[0]= RecData[i+1];
                                      TempStr[1]= RecData[i];
                                      TempStr[2]= RecData[i+3];
                                      TempStr[3]= RecData[i+2];

                                      memcpy(&FlowSum,TempStr,4);

                                      LinearCalPara.push_back(FlowSum);
                                  }
                                  QByteArray Indentifier;

                                  if(EnterCount==0)
                                  {
                                      Indentifier[0]=DeviceAddr;
                                      Indentifier[1]=0x03;

                                      Indentifier[2]=0x00;
                                      Indentifier[3]=0xE6;

                                      Indentifier[4]=0x00;
                                      Indentifier[5]=0x26;

                                      quint16 CRCValue = CRC16Check(Indentifier,8);

                                      Indentifier[6]=CRCValue%256;
                                      Indentifier[7]=CRCValue/256;

                                      LastWriteBytes(Indentifier);

                                  }
                                  if(EnterCount==1)
                                  {
                                      EnterCount=0;
                                      emit SendLinearCalPara(LinearCalPara);
                                      LinearCalPara.clear();
                                  }
                                  else
                                      EnterCount++;
                             }
                         }
                      }
                          break;
                        case 0x06:
                      {
                          quint8 High = RecData[2];
                          quint8 Low = RecData[3];

                          quint16 AddressValue = High*16+Low;
                          if(AddressValue == 0xEA)
                          {
                              ShowMessage("流量计已清零",1000);
                          }
                          else if(AddressValue == 0xE8)
                          {
                              ShowMessage("流量计已使能标定功能",1000);
                          }
                      }
                          break;
                      case 0x10:
                      {
                          quint8 High = RecData[2];
                          quint8 Low = RecData[3];

                          quint16 AddressValue = High*16+Low;

                           if(AddressValue==0x85)
                           {
                               ShowMessage("设备常数写入成功！",1000);
                               UpdateResponse();
                           }
                           else if(AddressValue==0xEB)
                           {
                               ShowMessage("零漂校准成功！",1000);
                               emit SendCalibrationOK();
                           }
                           else if(AddressValue==0xE5)
                           {
                               ShowMessage("流速段写入成功！",1000);

                               QByteArray Indentifier;
                               quint32 Temp;

                               Indentifier[0]=DeviceAddr;
                               Indentifier[1]=0x10;

                               Indentifier[2]=0x00;
                               Indentifier[3]=0xE6;

                               Indentifier[4]=0x00;
                               Indentifier[5]=0x26;

                               Indentifier[6]=0x4C;

                                 for(quint8 i=7,j=19;i<83;i+=4,j++)
                               {
                                   Temp = *((int *)&LinearCalPara[j]);

                                   Indentifier[i]=Temp%65536/256;
                                   Indentifier[i+1]=Temp%256;

                                   Indentifier[i+2]=Temp/65536/256;
                                   Indentifier[i+3]=Temp/65536%256;
                               }
                               quint16 CRCValue = CRC16Check(Indentifier,85);

                               Indentifier[83]=CRCValue%256;
                               Indentifier[84]=CRCValue/256;

                               LastWriteBytes(Indentifier);

                               LinearCalPara.clear();

                           }
                           else if(AddressValue==0xE6)
                           {
                               ShowMessage("系数段写入成功！",1000);
                               UpdateResponse();
                           }
                           else if(AddressValue==0x96)
                           {
                               ShowMessage("参数更新成功！",1000);
                           }
                      }
                          break;
                      default:
                          break;
                  }
                }
        }
        break;
    default:
        break;
    }
}
/***********************************************************************************************************
 函数名：DutyCycleUp()
 函数功能：电机转速占空比的控制，增加
 函数参数：无
 函数返回值：无
************************************************************************************************************/
void FCOperationFlowmeter::DutyCycleUp()
{
    QByteArray Indentifier;
    qint8 DutyCycle = ui->leDutyCycle->text().toInt();
    DutyCycle+=1;
    if(DutyCycle>99)
        DutyCycle=99;
    ui->leDutyCycle->setText(QString::number(DutyCycle));
    Indentifier[0]=0x44;
    Indentifier[1]=0x30+DutyCycle/100;
    Indentifier[2]=0x30+DutyCycle/10;
    Indentifier[3]=0x30+DutyCycle%10;
    NextWriteBytes(Indentifier);
}
/***********************************************************************************************************
 函数名：DutyCycleDown()
 函数功能：电机转速占空比的控制，减少
 函数参数：无
 函数返回值：无
************************************************************************************************************/
void FCOperationFlowmeter::DutyCycleDown()
{
    QByteArray Indentifier;
    qint8 DutyCycle = ui->leDutyCycle->text().toInt();
    DutyCycle-=1;
    if(DutyCycle<1)
      DutyCycle=1;
    ui->leDutyCycle->setText(QString::number(DutyCycle));

    Indentifier[0]=0x44;
    Indentifier[1]=0x30+DutyCycle/100;
    Indentifier[2]=0x30+DutyCycle/10;
    Indentifier[3]=0x30+DutyCycle%10;
    NextWriteBytes(Indentifier);
}
/***********************************************************************************************************
 函数名：Switch()
 函数功能：水阀的开端控制，通过485总线控制
 函数参数：无
 函数返回值：无
************************************************************************************************************/
void FCOperationFlowmeter::Switch()
{
    QByteArray Indentifier;
    Indentifier.resize(8);
    Indentifier[0]=0x33;
    Indentifier[1]=0x00;

    Indentifier[3]=0x00;
    Indentifier[4]=0x00;
    Indentifier[5]=0x00;
    if(ui->tbnOpen->text()==tr("放水"))
    {
        Indentifier[2]=0x12;
        Indentifier[6]=0x01;
        Indentifier[7]=0x46;
        ui->tbnOpen->setText(tr("停止"));
        ui->tbnOpen->setIcon(ImageFileOpen);
    }
    else if(ui->tbnOpen->text()==tr("停止"))
    {
        Indentifier[2]=0x11;
        Indentifier[6]=0x01;
        Indentifier[7]=0x45;
        ui->tbnOpen->setText(tr("放水"));
        ui->tbnOpen->setIcon(ImageFileClose);
    }
    WriteBytes(Indentifier);
}
/***********************************************************************************************************
 函数名：Measure()
 函数功能：测量按钮槽函数，负责电机水泵转速控制
 函数参数：无
 函数返回值：无
************************************************************************************************************/
void FCOperationFlowmeter::Measure()
{
     QByteArray Indentifier;
     qint8 DutyCycle = ui->leDutyCycle->text().toInt();
     if(ui->tbnMeasure->text()==tr("标定设备"))
     {
         ui->tbnMeasure->setText(tr("停止"));
         ui->tbnMeasure->setIcon(ImageFileStop);
         Indentifier[0]=0x44;
         Indentifier[1]=0x30+DutyCycle/100;
         Indentifier[2]=0x30+DutyCycle/10;
         Indentifier[3]=0x30+DutyCycle%10;
         NextWriteBytes(Indentifier);
         MeasureFlag=true;
         MyTimer->start(SampleTime);
         FirstMeasureFlag=true;
         ShowTimer->start(1000);
         CalibrationTimeFlag=true;
     }
     else
     {
         ui->tbnMeasure->setText(tr("标定设备"));
         ui->tbnMeasure->setIcon(ImageFileStart);
         DutyCycle=1;
         Indentifier[0]=0x44;
         Indentifier[1]=0x30+DutyCycle/100;
         Indentifier[2]=0x30+DutyCycle/10;
         Indentifier[3]=0x30+DutyCycle%10;
         NextWriteBytes(Indentifier);
         FlowStopFlag=true;
     }
}
/***********************************************************************************************************
 函数名：ClearWaves()
 函数功能：波形的清除
 函数参数：无
 函数返回值：无
************************************************************************************************************/
void FCOperationFlowmeter::ClearWaves()
{
    ui->MyCustomPlot->graph(0)->data()->clear();
    ui->MyCustomPlot->graph(1)->data()->clear();
    ui->MyCustomPlot->graph(2)->data()->clear();
    ui->MyCustomPlot->graph(3)->data()->clear();
    ui->MyCustomPlot->replot();
    ui->leCalculateFlow->setText(tr("0"));
//    ui->leSumQuality->setText(tr("0"));
    ui->leScaleDisplay->setText(tr("0"));
    WaveNum=0;
    SumQuality=0;
    LastQuality=0;
    FlowSpeedFlag=false;
    ui->leFlowDisplay_1->setText("0");
    ui->leFlowDisplay_2->setText("0");
    ui->leFlowDisplay_3->setText("0");
    CalibrationTime="0";
    ui->leCalibrationTime->setText(CalibrationTime);
    Reset();
}
/***********************************************************************************************************
 函数名：Reset()
 函数功能：天平的清零以及流量计的清零。
 函数参数：无
 函数返回值：无
************************************************************************************************************/
void FCOperationFlowmeter::Reset()
{
    QByteArray Indentifier;
    Indentifier[0]=0x1B;
    Indentifier[1]=0x74;
    WriteBytes(Indentifier);

    Indentifier[0]=DeviceAddr;
    Indentifier[1]=0x06;

    Indentifier[2]=0x00;
    Indentifier[3]=0xEA;

    Indentifier[4]=0x00;
    Indentifier[5]=0x01;

    quint16 CRCValue = CRC16Check(Indentifier,8);

    Indentifier[6]=CRCValue%256;
    Indentifier[7]=CRCValue/256;

    LastWriteBytes(Indentifier);
}
/***********************************************************************************************************
 函数名：SetDutyCyeleAddValue()
 函数功能：设置水泵电机占空比增加值
 函数参数：无
 函数返回值：无
************************************************************************************************************/
void FCOperationFlowmeter::SetDutyCyeleAddValue(int AddValue)
{
    QByteArray Indentifier;
    qint8 DutyCycle = ui->leDutyCycle->text().toInt();
    DutyCycle+=AddValue;
    if(DutyCycle<1)
      DutyCycle=1;
    else if(DutyCycle>99)
      DutyCycle=99;
    ui->leDutyCycle->setText(QString::number(DutyCycle));

    Indentifier[0]=0x44;
    Indentifier[1]=0x30+DutyCycle/100;
    Indentifier[2]=0x30+DutyCycle/10;
    Indentifier[3]=0x30+DutyCycle%10;
    NextWriteBytes(Indentifier);
}
/***********************************************************************************************************
 函数名：FlowSpeedCalibration()
 函数功能：流量标定系统流速标定按钮槽函数，负责流速的标定。
 函数参数：无
 函数返回值：无
************************************************************************************************************/
void FCOperationFlowmeter::FlowSpeedCalibration()
{
    static bool FlowSpeedStartFlag=true;
    QByteArray Indentifier;

    if(FlowSpeedStartFlag)
    {
        ui->tbnFlowSpeedCalibration->setText("停止");
        ui->tbnFlowSpeedCalibration->setIcon(ImageFileCalibrationStop);
        MyTimer->start(SampleTime);

        FlowCalibrationFlag=true;
        MeasureFlag=true;

        Indentifier[0]=DeviceAddr;
        Indentifier[1]=0x06;

        Indentifier[2]=0x00;
        Indentifier[3]=0xE8;

        Indentifier[4]=0x00;
        Indentifier[5]=0x01;

        quint16 CRCValue = CRC16Check(Indentifier,8);

        Indentifier[6]=CRCValue%256;
        Indentifier[7]=CRCValue/256;

        WriteBytes(Indentifier);
    }
    else
    {
        ui->tbnFlowSpeedCalibration->setText("测量");
        ui->tbnFlowSpeedCalibration->setIcon(ImageFileCalibration);
        quint8 DutyCycle=1;
        Indentifier[0]=0x44;
        Indentifier[1]=0x30+DutyCycle/100;
        Indentifier[2]=0x30+DutyCycle/10;
        Indentifier[3]=0x30+DutyCycle%10;
        NextWriteBytes(Indentifier);
        FlowStopFlag=true;
        FlowCalibrationFlag=false;
    }
    FlowSpeedStartFlag=!FlowSpeedStartFlag;
}
/*******************************************************************************
函数名：CRC16Check()
函数功能：一帧的数据的CRC校验以及长度校验。
函数参数：u8 RecFrameData[]，接收的一帧数据
函数返回值：校验结果状态
********************************************************************************/
quint16 FCOperationFlowmeter::CRC16Check(QByteArray RecFrameData,quint8 FrameLength)
{
    quint16 CRCValue = 0xFFFF;
    for (quint8 i = 0; i< (FrameLength - 2); i++)
    {
        quint8 TempData=RecFrameData[i];
        CRCValue ^= TempData;
        for (quint8 j = 0; j < 8; j++)
        {
            if (CRCValue & 0x0001)
            {
                CRCValue = (CRCValue >> 1) ^ 0xA001;
            }
            else
            {
                CRCValue >>= 1;
            }
        }
    }

    return CRCValue;
}
void FCOperationFlowmeter::CalculateConst()
{
    QByteArray Indentifier;

    Indentifier[0]=DeviceAddr;
    Indentifier[1]=0x03;

    Indentifier[2]=0x00;
    Indentifier[3]=0x85;

    Indentifier[4]=0x00;
    Indentifier[5]=0x01;

    quint16 CRCValue = CRC16Check(Indentifier,8);

    Indentifier[6]=CRCValue%256;
    Indentifier[7]=CRCValue/256;

    LastWriteBytes(Indentifier);

}
void FCOperationFlowmeter::WriteConst()
{
    QByteArray Indentifier;

    float Const = ui->leFlowDisplay_3->text().toFloat();

    quint32 Temp = *((int *)&Const);

    Indentifier[0]=DeviceAddr;
    Indentifier[1]=0x10;

    Indentifier[2]=0x00;
    Indentifier[3]=0x85;

    Indentifier[4]=0x00;
    Indentifier[5]=0x02;
    Indentifier[6]=0x04;

    Indentifier[7]=Temp%65536/256;
    Indentifier[8]=Temp%256;

    Indentifier[9]=Temp/65536/256;
    Indentifier[10]=Temp/65536%256;

    quint16 CRCValue = CRC16Check(Indentifier,13);

    Indentifier[11]=CRCValue%256;
    Indentifier[12]=CRCValue/256;

    LastWriteBytes(Indentifier);
}
void FCOperationFlowmeter::RecReadSignal()
{
     QByteArray Indentifier;

     Indentifier[0]=DeviceAddr;
     Indentifier[1]=0x03;

     Indentifier[2]=0x00;
     Indentifier[3]=0xE5;

     Indentifier[4]=0x00;
     Indentifier[5]=0x26;

     quint16 CRCValue = CRC16Check(Indentifier,8);

     Indentifier[6]=CRCValue%256;
     Indentifier[7]=CRCValue/256;

     LastWriteBytes(Indentifier);
}

void FCOperationFlowmeter::RecWriteSignal(QVector<float> TempPara)
{
    LinearCalPara = TempPara;

    QByteArray Indentifier;
    quint32 Temp;

    Indentifier[0]=DeviceAddr;
    Indentifier[1]=0x10;

    Indentifier[2]=0x00;
    Indentifier[3]=0xE5;

    Indentifier[4]=0x00;
    Indentifier[5]=0x26;

    Indentifier[6]=0x4C;

    for(quint8 i=7,j=0;i<83;i+=4,j++)
    {
        Temp = *((int *)&LinearCalPara[j]);

        Indentifier[i]=Temp%65536/256;
        Indentifier[i+1]=Temp%256;

        Indentifier[i+2]=Temp/65536/256;
        Indentifier[i+3]=Temp/65536%256;
    }
    quint16 CRCValue = CRC16Check(Indentifier,85);

    Indentifier[83]=CRCValue%256;
    Indentifier[84]=CRCValue/256;

    LastWriteBytes(Indentifier);
}

void FCOperationFlowmeter::UpdateResponse()
{
    QByteArray Indentifier;

    Indentifier[0]=DeviceAddr;
    Indentifier[1]=0x06;

    Indentifier[2]=0x00;
    Indentifier[3]=0x96;

    Indentifier[4]=0x00;
    Indentifier[5]=0x01;

    quint16 CRCValue = CRC16Check(Indentifier,8);

    Indentifier[6]=CRCValue%256;
    Indentifier[7]=CRCValue/256;

    LastWriteBytes(Indentifier);
}
void FCOperationFlowmeter::NullDriftCalibration(QString NullDriftTime)
{
  QByteArray Indentifier;

  float null_dritf_time = NullDriftTime.toFloat();
  quint32 Temp = *((int *)&null_dritf_time);

  Indentifier[0]=DeviceAddr;
  Indentifier[1]=0x10;

  Indentifier[2]=0x00;
  Indentifier[3]=0xEB;

  Indentifier[4]=0x00;
  Indentifier[5]=0x06;

  Indentifier[6]=0x0C;

  Indentifier[7]=Temp%65536/256;
  Indentifier[8]=Temp%256;

  Indentifier[9]=Temp/65536/256;
  Indentifier[10]=Temp/65536%256;

  Indentifier[11]=0xDF;
  Indentifier[12]=0xC3;
  Indentifier[13]=0x2D;
  Indentifier[14]=0xBD;

  Indentifier[15]=0x00;
  Indentifier[16]=0x01;
  Indentifier[17]=0x3F;
  Indentifier[18]=0x80;

  quint16 CRCValue = CRC16Check(Indentifier,21);

  Indentifier[19]=CRCValue%256;
  Indentifier[20]=CRCValue/256;

  LastWriteBytes(Indentifier);
}
