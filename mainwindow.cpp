#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolButton>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/ASUS/Desktop/xcircuit figures/rc_circuit_4");
    ui->label_pic->setPixmap(pix);
    connect(ui->toolButton,SIGNAL(clicked()),this,SLOT(onclicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onclicked()
{
    solver();
}
void MainWindow::solver()
{
    double h=1/(10000.0);
    double V=ui->lineEdit->text().toDouble();
    double R=ui->lineEdit_2->text().toDouble();
    double C=ui->lineEdit_3->text().toDouble();
    double q0=ui->lineEdit_4->text().toDouble();
    QVector<double> t(1000002),q(1000002);
    t[0]=0;
    q[0]=q0;


    for(double n=1;n<1000001;n++)
    {
        double dqdt=(C*V-q[n-1])/(R*C);

        t[n]=n/10000.0;
        q[n]=q[n-1]+(h*dqdt);

    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(t,q);
    ui->customPlot->xAxis->setLabel("t");
    ui->customPlot->yAxis->setLabel("q");
    ui->customPlot->xAxis->setRange(0,100);
    ui->customPlot->yAxis->setRange(20,0);
    ui->customPlot->replot();

}
