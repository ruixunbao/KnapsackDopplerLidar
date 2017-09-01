#include "wind_display.h"
#include "direction_needle.h"
#include "speed_bar.h"
#include "heights_label.h"
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QDateTime>
#include <QPainter>
#include <QFont>
#include <QRectF>
#include <QPen>
#include <QTime>

wind_display::wind_display(QWidget *parent) : QWidget(parent)
{
    // ����̽��߶ȱ�ǩQLabel *DetectedAttitude
    DetectedAttitude = new QLabel(this) ;
    DetectedAttitude -> setText(QString::fromLocal8Bit("̽��߶�")); //����label����
    DetectedAttitude -> setStyleSheet("QLabel{background-color:rgb(200,100,0);"  //����ǰ��ɫ������ɫ���Ӵ�
                                      "color: white;"
                                      "font:bold;"
                                      "}");

    QFont font ( "Microsoft YaHei", 20, 100);
    DetectedAttitude ->setFont(font);
    DetectedAttitude->setAlignment(Qt::AlignCenter); //�������־���

    // ˮƽ���ǩ
    HorizontalDirection= new QLabel(this);
    HorizontalDirection -> setText(QString::fromLocal8Bit("ˮƽ����"));      //����label����
    HorizontalDirection -> setStyleSheet("QLabel{background-color:rgb(32,26,100);"  //����ǰ��ɫ������ɫ���Ӵ�
                                         "color: white;"
                                         "font:bold;"
                                         "}");

    HorizontalDirection ->setFont(font);
    HorizontalDirection->setAlignment(Qt::AlignCenter); //�������־���

    // ˮƽ���ٱ�ǩ
    HorizontalVelocity= new QLabel(this) ;
    HorizontalVelocity -> setText(QString::fromLocal8Bit("ˮƽ����")); //����label����
    HorizontalVelocity -> setStyleSheet("QLabel{background-color:rgb(0,176,240);"  //����ǰ��ɫ������ɫ���Ӵ�
                                        "color: white;"
                                        "font:bold;"
                                        "}");
    HorizontalVelocity ->setFont(font);
    HorizontalVelocity->setAlignment(Qt::AlignCenter); //�������־���

    // ��ֱ���ǩ
    VerticalVelocity= new QLabel(this) ;
    VerticalVelocity -> setText(QString::fromLocal8Bit("��ֱ��")); //����label����
    VerticalVelocity -> setStyleSheet("QLabel{background-color:rgb(0,176,240);"  //����ǰ��ɫ������ɫ���Ӵ�
                                        "color: white;"
                                        "font:bold;"
                                        "}");
    VerticalVelocity ->setFont(font);
    VerticalVelocity->setAlignment(Qt::AlignCenter); //�������־���

    Glayout = new QGridLayout;
    Hlayout = new QHBoxLayout;
    Vlayout = new QVBoxLayout;

    Hlayout->addWidget(DetectedAttitude); //��1�е�1��
    Hlayout->addWidget(HorizontalDirection); //��1�У���2��
    Hlayout->addWidget(HorizontalVelocity); //��1�У���3��
    Hlayout->addWidget(VerticalVelocity); //��1�У���4��


    for (int j = 0; j < nLayers; ++j)
    {

        // ����100~1000�׵�10����ǩ
        my_height[j] = new heights_label;
        my_height[j]->setHeight(Heights[j]);
        Glayout->addWidget(my_height[j], j, 0);
        qDebug()<<Heights[j];

        //�Եڶ���ˮƽ��������񲼾�
        my_needle[j] = new direction_needle;
        my_needle[j]->setHSpeed(HSpeed[j]);
        my_needle[j]->setHdirection(H_direction[j]);
        Glayout->addWidget(my_needle[j],j,1); //��2�У���2��

        // �Դ�ֱ��������񲼾�
        my_bar[j] = new speed_bar;
        my_bar[j]->setHSpeed(HSpeed[j]);
        my_bar[j]->setVSpeed(VSpeed[j]);
        Glayout->addWidget(my_bar[j],j,2);    //��2�У���2��

    }

    Glayout->setColumnStretch(0, 2 );
    Glayout->setColumnStretch(1, 4 );
    Glayout->setColumnStretch(2, 5 );
    Vlayout->addLayout(Hlayout);
    Vlayout->addLayout(Glayout);
    Vlayout->setStretch(0,1);
    Vlayout->setStretch(1,nLayers);

    Hlayout->setStretch(0,2);
    Hlayout->setStretch(1,2.25);
    Hlayout->setStretch(2,3.75);
    Hlayout->setStretch(3,2);
    setLayout(Vlayout);    //���岼��
}



void wind_display::setHSpeed(const double *sp)
{
    for(int i=0;i<nLayers;i++)
        if(HSpeed[i] != *(sp+i))
        {
            HSpeed[i] = *(sp+i);
            my_needle[i]->setHSpeed(HSpeed[i]);
            my_bar[i]->setHSpeed(HSpeed[i]);
        }
}

void wind_display::setHDirection(const double *dir)
{
    for(int i=0;i<nLayers;i++)
        if(H_direction[i] != *(dir+i))
        {
            H_direction[i] = *(dir+i);
            my_needle[i]->setHdirection(H_direction[i]);
        }
}

void wind_display::setVSpeed(const double *sp)
{
    for(int i=0;i<nLayers;i++)
        if(VSpeed[i] != *(sp+i))
        {
            VSpeed[i] = *(sp+i);
            my_bar[i]->setVSpeed(VSpeed[i]);
        }
}

void wind_display::setHeights(const double *h)
{
    for(int i=0;i<nLayers;i++)
        if(Heights[i] != *(h+i))
        {
            Heights[i] = *(h+i);
            my_height[i]->setHeight(Heights[i]);
        }
}


//int display_instantaneous_windspeed::setLayerNum(int n)
//{
//    return n;

//}






