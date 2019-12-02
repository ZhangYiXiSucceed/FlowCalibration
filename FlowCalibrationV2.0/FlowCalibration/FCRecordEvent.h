#ifndef FCRECORDEVENT_H
#define FCRECORDEVENT_H

#include <QWidget>

namespace Ui {
class FCRecordEvent;
}

class FCRecordEvent : public QWidget
{
    Q_OBJECT

public:
    explicit FCRecordEvent(QWidget *parent = 0);
    ~FCRecordEvent();
signals:
    void ShowMessage(QString,uint16_t);
private:
    Ui::FCRecordEvent *ui;
};

#endif // FCRECORDEVENT_H
