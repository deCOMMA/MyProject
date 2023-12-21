#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QString>
#include <QMessageBox>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
    double Xstart,Xend;
    double a_p,b_p,c_p,k_sin,n_sin,k_cos,n_cos,k_modal,n_modal;

private:
    Ui::Form *ui;

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

public slots:

signals:
     void signalsForm(double x1,double x2);
     void signalsForm_parabola(double a,double b,double c);
     void signalsForm_sin(double a,double b);
     void signalsForm_cos(double a,double b);
     void signalsForm_modal(double a,double b);

};

#endif // FORM_H
