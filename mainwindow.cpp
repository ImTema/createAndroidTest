#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListWidget>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    count=2;
    QListWidgetItem *item = new QListWidgetItem("Вопрос 1");
    ui->questionsListWidget->addItem(item);
    ui->questionsListWidget->setCurrentItem(item);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QListWidgetItem *item = new QListWidgetItem("Вопрос "+ QString::number(count));
    ui->questionsListWidget->addItem(item);
    ui->questionsListWidget->setCurrentItem(item);

    count++;
}

void MainWindow::on_pushButton_2_clicked()
{
    QListWidgetItem* itm1 =ui->questionsListWidget->takeItem(ui->questionsListWidget->currentRow());
    delete itm1;

}

void MainWindow::on_questionsListWidget_itemActivated(QListWidgetItem *item)
{
    qDebug()<<"changing item to: text "<<item->text();
    addQuesion();
}

void MainWindow::on_comboBox_activated(int index)
{
    qDebug()<<"setting question type"<<index;
}
void MainWindow::on_textEdit_textChanged()
{
    qDebug()<<"changing question text to "<<ui->textEdit->toPlainText();
}

void MainWindow::on_textEdit_2_textChanged()
{
       qDebug()<<"changing explanation text to "<<ui->textEdit->toPlainText();
}
void MainWindow::addQuesion(){
    Question *q=new Question("qwe");
    Question *w=new Question("qww");
    q->setText("text");
    questions.push_back(q);
    questions.push_back(w);
    Question *t=questions.at(0);
    qDebug()<<t->toString();
}
