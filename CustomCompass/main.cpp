#include "mainwindow.h"
//#include "detectionheight.h"
//#include "direction_needle.h"
#include <QApplication>
#include <QFont>
#include <QWidget>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow  w; // ��ִ�й��캯��
    w.setWindowTitle(QString::fromLocal8Bit("�����糡"));
    QFont font = w.font();
    font.setPointSize(16);
    w.setFont(font);
//    w.show();


//    w.showMaximized();
    w.showFullScreen();
    w.setMinimumSize(800, 800);
    return a.exec();

}
