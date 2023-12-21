#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    bool nice1,nice2,nice3;
    Xstart = ui->lineEdit->text().toDouble(&nice1);
    Xend = ui->lineEdit_2->text().toDouble(&nice2);
    if(!nice1 or ui->lineEdit->text().isEmpty() or Xstart>Xend or Xstart==Xend or !nice2 or ui->lineEdit_2->text().isEmpty()){
        QMessageBox::critical(this,"Ошибка", "Ошибка входных данных попробуйте снова");
        nice3 = false;
    }
    if(nice3){
        emit signalsForm(Xstart,Xend);
    }
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}

void Form::on_pushButton_2_clicked()
{
    bool ok1,ok2,ok3,ok4;

    a_p = ui->lineEdit_3->text().toDouble(&ok1);
    b_p = ui->lineEdit_4->text().toDouble(&ok2);
    c_p = ui->lineEdit_5->text().toDouble(&ok3);
    if(!ok1 or !ok2 or !ok3 or ui->lineEdit_3->text().isEmpty() or ui->lineEdit_4->text().isEmpty() or ui->lineEdit_5->text().isEmpty()){
        QMessageBox::critical(this,"Ошибка", "Ошибка входных данных попробуйте снова");
        ok4 = false;
    }
    if(ok4){
        emit signalsForm_parabola(a_p,b_p,c_p);
}
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
}


void Form::on_pushButton_3_clicked()
{
    bool ok1,ok2,ok3;
    n_sin = ui->lineEdit_6->text().toDouble(&ok1);
    k_sin = ui->lineEdit_7->text().toDouble(&ok2);
    if(!ok1 or !ok2 or ui->lineEdit_6->text().isEmpty() or ui->lineEdit_7->text().isEmpty()){
        QMessageBox::critical(this,"Ошибка", "Ошибка входных данных попробуйте снова");
        ok3 = false;
    }
    if(ok3){
        emit signalsForm_sin(k_sin,n_sin);
    }
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
}

void Form::on_pushButton_4_clicked()
{
    bool ok1,ok2,ok3;
    n_cos = ui->lineEdit_8->text().toDouble(&ok1);
    k_cos = ui->lineEdit_9->text().toDouble(&ok2);
    if(!ok1 or !ok2 or ui->lineEdit_8->text().isEmpty() or ui->lineEdit_9->text().isEmpty()){
        QMessageBox::critical(this,"Ошибка", "Ошибка входных данных попробуйте снова");
        ok3 = false;
    }
    if(ok3){
        emit signalsForm_cos(k_cos,n_cos);
    }
    ui->lineEdit_8->clear();
    ui->lineEdit_9->clear();
}


void Form::on_pushButton_5_clicked()
{
    bool ok1,ok2,ok3;
    n_modal = ui->lineEdit_10->text().toDouble(&ok1);
    k_modal= ui->lineEdit_11->text().toDouble(&ok2);
    if(!ok1 or !ok2 or ui->lineEdit_10->text().isEmpty() or ui->lineEdit_11->text().isEmpty()){
        QMessageBox::critical(this,"Ошибка", "Ошибка входных данных попробуйте снова");
        ok3 = false;
    }
    if(ok3){
        emit signalsForm_modal(k_modal,n_modal);
    }
    ui->lineEdit_10->clear();
    ui->lineEdit_11->clear();
}

