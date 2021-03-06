#include "AxLine.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStyle>
#include <qdesktopwidget.h>
#include <qrandom.h>
#include <istream>
#include <AxCircle.h>
#include <common_functions.h>
#include <QDebug>
#include <math.h>
#include <AxShape.h>
#include <Vertice.h>
#include <bisection_intersection.h>
#include <clipper.hpp>
using namespace ClipperLib;


MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    //ui->setupUi(this);

    // set the size of window
    QSize availableSize = qApp->desktop()->availableGeometry(this).size();
    int width = availableSize.width();
    int height = availableSize.height();
    qDebug() << "Available dimensions " << width << "x" << height;
    width *= 0.7; // 70% of the screen size
    height *= 0.7; // 70% of the screen size
    qDebug() << "Computed dimensions " << width << "x" << height;
    QSize newSize( width, height );

    setGeometry(
                QStyle::alignedRect(
                    Qt::LeftToRight,
                    Qt::AlignCenter,
                    newSize,
                    qApp->desktop()->availableGeometry(this)
                    )
                );

  //--------------------------------------------------------------------


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{

    qDebug() << "paint event";

    QPainter painter;
    painter.begin(this);
    QPen pen,pen1,pen2;
    pen.setWidth(4);
    painter.setPen(pen);


    pen1.setWidth(10);
    pen1.setColor("red");
    painter.setPen(pen1);

    AxShape poly,poly2;

    poly.append(new AxLine(QPoint(20,100),QPoint(80,160)));
    poly.append(new AxLine(QPoint(80,160),QPoint(20,260)));
    poly.append(new AxLine(QPoint(20,260),QPoint(520,260)));
    poly.append(new AxArc(QLine(QPoint(520,260),QPoint(540,240)),20,true));
    poly.append(new AxLine(QPoint(540,240),QPoint(540,200)));
    poly.append(new AxLine(QPoint(540,200),QPoint(380,200)));
    poly.append(new AxLine(QPoint(380,200),QPoint(380,100)));
    poly.append(new AxLine(QPoint(380,100),QPoint(440,40)));
    poly.append(new AxLine(QPoint(440,40),QPoint(100,40)));
    poly.append(new AxLine(QPoint(100,40),QPoint(20,100)));

    poly.display(this,2,"red");

    poly2.append(new AxLine(QPoint(20,100),QPoint(80,160)));
    poly2.append(new AxLine(QPoint(80,160),QPoint(20,260)));
    poly2.append(new AxLine(QPoint(20,260),QPoint(520,260)));
    poly2.append(new AxArc(QLine(QPoint(520,260),QPoint(540,240)),20,true));
    poly2.append(new AxLine(QPoint(540,240),QPoint(540,200)));
    poly2.append(new AxLine(QPoint(540,200),QPoint(380,200)));
    poly2.append(new AxLine(QPoint(380,200),QPoint(380,100)));
    poly2.append(new AxLine(QPoint(380,100),QPoint(440,40)));
    poly2.append(new AxLine(QPoint(440,40),QPoint(100,40)));
    poly2.append(new AxLine(QPoint(100,40),QPoint(20,100)));

    //poly2.set_cw(true);
    //poly2[3]->set_cw(false);

    poly2.analyse_dir();


    poly2.offset(-40);

    qDebug() <<"poly2 size";
    qDebug() <<poly2.size();

    poly2.link();

    qDebug() <<"poly2 size";
    qDebug()<< poly2;



    poly2.display(this,3,"black");


    /*AxArc arc(QPoint(200,200),100);

    arc.display(this,5,"red");*/


}
