#include "FCMainWindow.h"
#include "ui_FCMainWindow.h"

FCMainWindow::FCMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FCMainWindow),
    MyTabWidget(new QTabWidget),
    MyFCOperationFlowmeter(new FCOperationFlowmeter(this)),
    MyFCParameter(new FCParameter(this)),
    MyFCRecordEvent(new FCRecordEvent(this))
{
    ui->setupUi(this);
    InitUI();
    InitConnect();
}

FCMainWindow::~FCMainWindow()
{
    delete ui;
}
/************************************************************************************************************
函数名：InitUI()
参数：无
函数功能：负责主界面（框架）下UI初始化，设置Tabwidget,statusBar等
返回值：无
************************************************************************************************************/
void FCMainWindow::InitUI()
{
    QHBoxLayout *Hlayout = new QHBoxLayout;
    Hlayout->addWidget(MyTabWidget);
    QVBoxLayout *Vlayout = new QVBoxLayout;
    Vlayout->addWidget(MyTabWidget);
    ui->centralWidget->setLayout(Vlayout);
    ui->centralWidget->setLayout(Hlayout);

    QFont Ft("Microsoft YaHei");
    Ft.setPointSize(12);

    this->MyTabWidget->setFont(Ft);
    this->MyTabWidget->setStyleSheet("color:rgb(0,0,0)");


    this->MyTabWidget->addTab(MyFCOperationFlowmeter,tr("流量计标定"));
    this->MyTabWidget->addTab(MyFCParameter,tr("参数设置"));
    this->MyTabWidget->addTab(MyFCRecordEvent,tr("日志记录"));

    statusBar()->setFont(Ft);

    ComPort=new QLabel();
    ComPort->setText(tr("端口：无"));
    this->ui->statusBar->addPermanentWidget(ComPort);
    BradRate=new QLabel();
    BradRate->setText(tr("波特率：无"));
    this->ui->statusBar->addPermanentWidget(BradRate);

    NextComPort=new QLabel();
    NextComPort->setText(tr("端口：无"));
    this->ui->statusBar->addPermanentWidget(NextComPort);
    NextBradRate=new QLabel();
    NextBradRate->setText(tr("波特率：无"));
    this->ui->statusBar->addPermanentWidget(NextBradRate);

    LastComPort=new QLabel();
    LastComPort->setText(tr("端口：无"));
    this->ui->statusBar->addPermanentWidget(LastComPort);
    LastBradRate=new QLabel();
    LastBradRate->setText(tr("波特率：无"));
    this->ui->statusBar->addPermanentWidget(LastBradRate);

    TextMessage+=tr("提示消息：");
    TextMessage+=tr("界面创建成功!");
    statusBar()->showMessage(TextMessage,1500);

}
/************************************************************************************************************
函数名：InitConnect()
参数：无
函数功能：负责各界面之间的槽函数连接（兄弟窗口之间，槽函数只能在父窗口之间连接）
返回值：无
************************************************************************************************************/
void FCMainWindow::InitConnect()
{
    connect(MyFCOperationFlowmeter,SIGNAL(ShowMessage(QString,uint16_t)),this,SLOT(ShowSystemMessage(QString,uint16_t)));
    connect(MyFCOperationFlowmeter,SIGNAL(ShowParameter(QString,QString)),this,SLOT(ShowParameter(QString,QString)));
    connect(MyFCOperationFlowmeter,SIGNAL(ShowNextParameter(QString,QString)),this,SLOT(ShowNextParameter(QString,QString)));
    connect(MyFCOperationFlowmeter,SIGNAL(ShowLastParameter(QString,QString)),this,SLOT(ShowLastParameter(QString,QString)));
    connect(MyFCOperationFlowmeter,SIGNAL(SendCalibrationOK()),MyFCParameter,SLOT(RecCalibrationInfo()));

    connect(MyFCParameter,SIGNAL(ReadLinearCalPara()),MyFCOperationFlowmeter,SLOT(RecReadSignal()));
    connect(MyFCParameter,SIGNAL(SendNullDriftCalibrationSignal(QString)),MyFCOperationFlowmeter,SLOT(NullDriftCalibration(QString)));
    connect(MyFCParameter,SIGNAL(WriteLinearCalPara(QVector<float>)),MyFCOperationFlowmeter,SLOT(RecWriteSignal(QVector<float>)));

    connect(MyFCParameter,SIGNAL(ShowMessage(QString,uint16_t)),this,SLOT(ShowSystemMessage(QString,uint16_t)));

    connect(MyFCRecordEvent,SIGNAL(ShowMessage(QString,uint16_t)),this,SLOT(ShowSystemMessage(QString,uint16_t)));
}
/************************************************************************************************************
函数名：ShowSystemMessage(QString Message,uint16_t ShowTime)
参数：QString Message,uint16_t ShowTime，消息和显示消息的时间，单位ms
函数功能：状态栏左侧显示消息
返回值：无
************************************************************************************************************/
void FCMainWindow::ShowSystemMessage(QString Message,uint16_t ShowTime)
{
    statusBar()->showMessage(Message,ShowTime);
}

/************************************************************************************************************
函数名：ShowParameter(QString ComPortData,QString BradRateData)
参数：QString ComPortData,QString BradRateData  ，端口号和波特率
函数功能：状态栏右侧永久显示波特率和端口号。
返回值：无
************************************************************************************************************/
void FCMainWindow::ShowParameter(QString ComPortData,QString BradRateData)
{
   ComPort->setText(tr("端口：")+ComPortData);
   this->ui->statusBar->addPermanentWidget(ComPort);
   BradRate->setText(tr("波特率：")+BradRateData);
   this->ui->statusBar->addPermanentWidget(BradRate);
}
/***********************************************************************************************************
 函数名：ShowNextParameter()
 函数功能：状态栏显示提示USART-TTL端口和波特率参数（右侧）
 函数参数：无
 函数返回值：无
************************************************************************************************************/
void FCMainWindow::ShowNextParameter(QString ComPortData,QString BradRateData)
{
    NextComPort->setText(tr("端口：")+ComPortData);
    this->ui->statusBar->addPermanentWidget(NextComPort);
    NextBradRate->setText(tr("波特率：")+BradRateData);
    this->ui->statusBar->addPermanentWidget(NextBradRate);
}
/***********************************************************************************************************
 函数名：ShowLastParameter()
 函数功能：状态栏显示提示USART-TTL端口和波特率参数（右侧）
 函数参数：无
 函数返回值：无
************************************************************************************************************/
void FCMainWindow::ShowLastParameter(QString ComPortData,QString BradRateData)
{
    LastComPort->setText(tr("端口：")+ComPortData);
    this->ui->statusBar->addPermanentWidget(LastComPort);
    LastBradRate->setText(tr("波特率：")+BradRateData);
    this->ui->statusBar->addPermanentWidget(LastBradRate);
}
