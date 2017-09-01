#include "mainwindow.h"
#include "wind_display.h"
#include <QWidget>

#include <QDebug>
#include <QLabel>
#include <QFont>
#include <QRectF>
#include <QPen>
#include <QPainter>
#include <QString>
#include <QTimer>
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    //���ݳ�ʼ��
    n = 10;
    H_low = 100;
    H_high = 900;
    for(int i=0;i<n;i++)
    {
        H_speed[i] = 0;
        H_direction[i] = 0;
        V_speed[i] = 0;
        Height_values[i] = H_low + i*100;
    }

    //��һ������һ��QWidgetʵ�����������ʵ������ΪcentralWidget������
    DisplaySpeed = new wind_display(this);
    DisplaySpeed->setHeights(Height_values);

    this->setCentralWidget(DisplaySpeed);
    // ���춨ʱ�������ó�ʱΪ 1 ��
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(changeData()));
    timer->start(1000);
}

void MainWindow::changeData()
{

    for (int i = 0; i < n; ++i)
    {
        // ˮƽ����
        H_speed[i] += (1.3 - H_speed[i]*0.01*i);
        if(H_speed[i]>10)
            H_speed[i] -= 7.3;

        // ˮƽ����
        H_direction[i] += 100.3 + H_direction[i]*0.02*i;
        if(H_direction[i]>=360)
            H_direction[i] -= 360;

        // ��ֱ����
        V_speed[i] += (0.7+i*0.2+V_speed[i]*0.51);
        if(V_speed[i]>6)
            V_speed[i] -= 5.5;
        if(V_speed[i]<0)
            V_speed[i] += 5.5;
        V_speed[i] -= 3;
        DisplaySpeed->setHSpeed(H_speed);
        DisplaySpeed->setHDirection(H_direction);
        DisplaySpeed->setVSpeed(V_speed);
    }
}

MainWindow::~MainWindow()
{
    delete DisplaySpeed;
}

