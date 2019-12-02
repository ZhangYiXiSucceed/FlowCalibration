#include "FCRecordEvent.h"
#include "ui_FCRecordEvent.h"

FCRecordEvent::FCRecordEvent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FCRecordEvent)
{
    ui->setupUi(this);
}

FCRecordEvent::~FCRecordEvent()
{
    delete ui;
}
