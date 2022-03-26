#include "blink.h"
#include <iostream>
#include <lgpio.h>
#include "ui_blink.h"
#include <QDebug>
#define OUT 18


blink::blink(QWidget *parent) :
    QMainWindow(parent)
    , ui(new Ui::blink)

{
    int lFlags = 0; /* default line flags */

    m_led_handle = lgGpiochipOpen(0); /* get a handle to the GPIO */
    lgGpioClaimOutput(m_led_handle, lFlags, OUT, 0); /* initial level 0 */

   ui->setupUi(this);
   timer = new QTimer();
   timer->setInterval(500);
   connect(timer, &QTimer::timeout, this, &blink::onTimer);
}

void blink::onTimer()
{
    qDebug() << "Timer!";
    state = !state;
    lgGpioWrite(m_led_handle, OUT, state);
}

blink::~blink()
{
   delete ui;
}

void blink::on_u_startButton_clicked()
{
    timer->start();

}

void blink::on_u_stopButton_clicked()
{
    timer->stop();
    lgGpioWrite(m_led_handle, OUT, 0);
    state = false;
}

void blink::on_horizontalSlider_valueChanged(int value)
{
    if(value == 0)
    {
        timer->setInterval(1000);
    }
    else if(value == 1)
    {
        timer->setInterval(900);
    }
    else if(value == 2)
    {
        timer->setInterval(800);
    }
    else if(value == 3)
    {
        timer->setInterval(700);
    }
    else if(value == 4)
    {
        timer->setInterval(600);
    }
    else if(value == 5)
    {
        timer->setInterval(500);
    }
    else if(value == 6)
    {
        timer->setInterval(400);
    }
    else if(value == 7)
    {
        timer->setInterval(300);
    }
    else if(value == 8)
    {
        timer->setInterval(200);
    }
    else if(value == 9)
    {
        timer->setInterval(100);
    }
    else if(value == 10)
    {
        timer->setInterval(50);
    }
    qDebug() << value;
}
