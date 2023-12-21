#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QVector>
#include <QtMath>>
#include <fstream>
#include <QFileDialog>>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QStringList>
#include <QApplication>
#include <QPen>
#include <QScreen>
#include <QPixmap>
#include <QFileDialog>
#include <QMessageBox>
#include <form.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void FoundPeriod(QVector<double> x,QVector<double> y);

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_action_triggered();

    void on_action_2_triggered();

    void on_pushButton_4_clicked();

    void on_pushButton_Rebild_clicked();

private:
    Ui::MainWindow *ui;
    double xBegin, xEnd, h, X, k;
    QVector<double>x,y;
    QPen pen;
    Form *form;
    Form *parabola;
    double xstart, xend;
    double a_p,b_p,c_p,n_sin,k_sin,n_cos,k_cos,n_modal,k_modal;

public slots:
    void slotForm(double x1,double x2);
    void slotForm_parabola(double a,double b,double c);
    void slotForm_sin(double a,double b);
    void slotForm_cos(double a,double b);
    void slotForm_modal(double a,double b);

};
#endif // MAINWINDOW_H
