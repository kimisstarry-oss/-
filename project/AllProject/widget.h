#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "title.h"
#include "nowsee.h"
#include "devicecontroller.h"
#include "deviceshow.h"
#include "systemlog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    Title *title;
    Nowsee *nowsee;
    DeviceController *devicecontroller;
    DeviceShow *deviceshow;
    SystemLog *systemlog;
};
#endif // WIDGET_H
