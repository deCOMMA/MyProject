#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    form = new Form;
    k = 1;
    h = 0.01*k;
    ui->widget->xAxis->setLabel("X");
    ui->widget->yAxis->setLabel("Y");
    ui->widget->setInteraction(QCP::iRangeZoom,true);
    ui->widget->setInteraction(QCP::iRangeDrag,true);
    pen.setColor(QColor(0, 0, 0)); //красный цвет (R, G, B)
    pen.setWidth(1); //толщину линии
    form->show();
    connect(form,&Form::signalsForm,this,&MainWindow::slotForm);
    connect(form,&Form::signalsForm_parabola,this,&MainWindow::slotForm_parabola);
    connect(form,&Form::signalsForm_sin,this,&MainWindow::slotForm_sin);
    connect(form,&Form::signalsForm_cos,this,&MainWindow::slotForm_cos);
    connect(form,&Form::signalsForm_modal,this,&MainWindow::slotForm_modal);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::FoundPeriod(QVector<double> x,QVector<double> y)
{
    int num=0;
    for(int i = 3; i < y.size()-3;i++)
    {
        double distance1 = fabs(y[0] - y[1]);
        double distance2 = fabs(y[1] - y[2]);
        double distance3 = fabs(y[2] - y[3]);
        double now_distance1 = fabs(y[0] - y[i]);
        double now_distance2 = fabs(y[1] - y[i+1]);
        double now_distance3 = fabs(y[2] - y[i+2]);
        if (now_distance1 < distance1 and now_distance2 < distance2 and now_distance3 < distance3)
        {
            num=i;
            break;
        }
    }
    QVector<double> x1;
    QVector<double> y1;
    if (num != 0){
        for(int i = 0; i <= num; i++)
        {
            x1.push_back(x[i]);
            y1.push_back(y[i]);
        }
        ui->widget->graph(0)->setPen(pen);
        ui->widget->addGraph();
        ui->widget->graph(1)->addData(x1,y1);
        ui->widget->replot();
    }
}

void MainWindow::on_radioButton_clicked()// 1 грвфик
{
    ui->widget->clearGraphs();
    ui->widget->xAxis->setRange(xend,xstart);
    ui->widget->yAxis->setRange(-10,50);
    for (X = xstart; X <= xend; X += h) {
        x.push_back(X);
        double Y = a_p*pow(X,2)+b_p*X+c_p;
        y.push_back(Y);
}
//    for (X = xBegin; X <= xEnd; X += h) {
//       x.push_back(X);
//    }
//   std::ifstream file("1.txt");    xstart = x1; xend = x2+h;
//       while (file >> X){
//       y.push_back(X);
//    }
//    file.close();
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x,y);
    ui->widget->replot();
    FoundPeriod(x,y);
    x.clear();
    y.clear();
}

void MainWindow::on_radioButton_2_clicked()// 2 грвфик
{
    ui->widget->clearGraphs();
    ui->widget->xAxis->setRange(xend,xstart);
    ui->widget->yAxis->setRange(-2,2);
    for (X = xstart; X <= xend; X += h) {
        x.push_back(X);
        double Y = k_sin*sin(n_sin*X);
        y.push_back(Y);
    }
//    for (X = xBegin; X <= xEnd; X += h) {
//        x.push_back(X);
//    }
//    std::ifstream file("2.txt");
//    while (file >> X) {
//        y.push_back(X);
//    }
//    file.close();
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x,y);
    ui->widget->replot();
    FoundPeriod(x,y);
    x.clear();
    y.clear();
}

void MainWindow::on_radioButton_3_clicked()// 3 грвфик
{
    ui->widget->clearGraphs();
    ui->widget->xAxis->setRange(xend,xstart);
    ui->widget->yAxis->setRange(-2,2);
    for (X = xstart; X <= xend; X += h) {
        x.push_back(X);
        double Y = k_cos*cos(n_cos*X);
        y.push_back(Y);
    }
//    for (X = xBegin; X <= xEnd; X += h) {
//        x.push_back(X);
//    }
//    std::ifstream file("3.txt");
//    while (file >> X) {
//        y.push_back(X);
//    }
//    file.close();
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x,y);
    ui->widget->replot();
    FoundPeriod(x,y);
    x.clear();
    y.clear();
}

void MainWindow::on_radioButton_4_clicked()// 4 грвфик
{
    ui->widget->clearGraphs();
    ui->widget->xAxis->setRange(xend,xstart);
    ui->widget->yAxis->setRange(-1,30);
    for (X = xstart; X <= xend; X += h) {
        x.push_back(X);
        double Y = (fabs(X+k_modal))+n_modal;
        y.push_back(Y);
    }
//    for (X = xBegin; X <= xEnd; X += h) {
//        x.push_back(X);
//    }
//    std::ifstream file("4.txt");
//    while (file >> X) {
//        y.push_back(X);
//    }
//    file.close();
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x,y);
    ui->widget->replot();
    FoundPeriod(x,y);
    x.clear();
    y.clear();
}

void MainWindow::on_pushButton_clicked()// Скриншот
{
    QPixmap screenshot = this->grab();
    QString filePath = QFileDialog::getSaveFileName(this, "Сохранить скриншот", "", "PNG (*.png);;JPEG (*.jpg *.jpeg)");
    if (!filePath.isEmpty()) {
        screenshot.save(filePath);
    }
}


void MainWindow::on_pushButton_3_clicked()// Показать период
{
    if (ui->widget->graphCount() != 0) {
    ui->widget->graph(0)->data()->clear();
    ui->widget->replot();
    ui->widget->update();
    }
}

void MainWindow::on_action_triggered()// Меню -> Информация
{
    QMessageBox::information(this,"Информация", "Данная программа создана для определения периода одномерного   сигнала. Программа принимает файл с расширением .txt после чего идет выполнение различных задач."
                                                           " Программа строит график сигнала и выделяет период синим цветом. Если график полностью синий то он не является периодическими. Чтобы увидеть отдельный период графика вы можете использовать кнопу Показать период."
                                                           " Программа создана в учебных целях студентом 2 курса группы ИВТ-223 Щербиновский Дмитрий Андреевич."
                                                           " Используйте с удовольствием.");
}

void MainWindow::on_action_2_triggered()// Меню -> Выход
{
    QApplication::quit();
}


void MainWindow::on_pushButton_4_clicked()// Загрузка файла
{
    QString filePath = QFileDialog::getOpenFileName(nullptr,"Выбрать файл",QString(),"All Files (*.*);; TXT Image (*.txt);");
    if (!filePath.isEmpty())
    {
    QFile file(filePath);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) { // Открытие файла для чтения
            QTextStream in(&file);
            QString fileContent = in.readAll();

            QStringList numberStrings = fileContent.split(" ", Qt::SkipEmptyParts); // Разделение строки на числа
            for (const QString& numberString : numberStrings)
            {
                bool ok;
                double number = numberString.toDouble(&ok);

                if (ok)
                {
                    y.push_back(number);
                } else
                {
                    qDebug() << "Ошибка преобразования строки в число:" << numberString;
                }
            }
            file.close();
    }
    }
    xBegin = xstart;
    xEnd = xend+h;
    ui->widget->clearGraphs();
    ui->widget->xAxis->setRange(xend,xstart);
    ui->widget->yAxis->setRange(-3,3);
    for (X = xBegin; X <= xEnd; X += h) {
    x.push_back(X);
    }
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x,y);
    ui->widget->replot();
    FoundPeriod(x,y);
    x.clear();
    y.clear();
}

void MainWindow::slotForm(double x1, double x2)
{
    xstart = x1;
    xend = x2+h;
}

void MainWindow::slotForm_parabola(double a, double b, double c)
{
    a_p = a;
    b_p = b;
    c_p = c;
}

void MainWindow::slotForm_sin(double a, double b)
{
    k_sin = a;
    n_sin = b;
}

void MainWindow::slotForm_cos(double a, double b)
{
    k_cos = a;
    n_cos = b;
}

void MainWindow::slotForm_modal(double a, double b)
{
    k_modal = a;
    n_modal = b;
}

void MainWindow::on_pushButton_Rebild_clicked()
{
    form->show();
    connect(form,&Form::signalsForm,this,&MainWindow::slotForm);
}




