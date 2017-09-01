#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include "heights_label.h"
#include "direction_needle.h"
#include "speed_bar.h"
#include "wind_display.h"
#include <QLabel>
//#include <QTime>
#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:
    void data_changed();
public slots:
    void changeData();
//    void setHeight(int hei);
//    void setHSpeed(double sp);
//    void setHdirection(double dir);
//    void setVSpeed(double sp);

private:
    Ui::MainWindow *ui;
    QWidget *widget;
    heights_label *my_height;
    direction_needle *my_needle;
    speed_bar *my_speed;

//    QPen pen;
//    QPainter painter;
//    QPainter painter1;
//    QRectF *rectF_v;

    QLabel *DetectedAttitude;
    QLabel *HorizontalDirection;
    QLabel *HorizontalVelocity;
    wind_display *DisplaySpeed;
       QGridLayout *Glayout;
public:

    QTimer *timer;

    int n;
    int H_low;
    int H_high;

    double H_speed[10];
    double H_direction[10];
    double V_speed[10];
    double Height_values[10];

};

#endif // MAINWINDOW_H
