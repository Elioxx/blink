#ifndef BLINK_H
#define BLINK_H
#include <QDebug>
#include <QTimer>


#include "ui_blink.h"

namespace Ui{class MainWindow;}
QT_END_NAMESPACE

class blink : public QMainWindow
{
    Q_OBJECT

public:
    blink(QWidget *parent = nullptr);
    ~blink();

private slots:
    void onTimer();
    void on_u_startButton_clicked();
    void on_u_stopButton_clicked();
    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::blink *ui;
    int m_led_handle;
    QTimer* timer;
    bool state = false;
};

#endif // BLINK_H
