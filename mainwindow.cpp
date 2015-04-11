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
    //item->setSelected(true);
    ui->questionsListWidget->addItem(item);
    ui->questionsListWidget->setCurrentItem(item);
    addQuestion(item->text());
    curQues=questions.value(item->text());
    curText=item->text();
    loadData();
    //ui->questionsListWidget->setItemSelected(item, true);
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
    addQuestion(item->text());

    savenload(item->text());
    count++;
}

void MainWindow::on_pushButton_2_clicked()
{
    int currentRow=ui->questionsListWidget->currentRow();
    curQues=questions.value(ui->questionsListWidget->item(currentRow+1)->text());
    curText=ui->questionsListWidget->item(currentRow+1)->text();
    loadData();
    for(int i=currentRow; i<count-2; i++){
        QListWidgetItem* curItem=ui->questionsListWidget->item(i);
        qDebug()<<"current"<<curItem->text();
        QListWidgetItem* nextItem=ui->questionsListWidget->item(i+1);
        saveData(curItem->text(), questions.value(nextItem->text()));
    }
    count--;
    QListWidgetItem* itm1=ui->questionsListWidget->takeItem(count-1);
    curQues=questions.value(ui->questionsListWidget->item(currentRow)->text());
    curText=ui->questionsListWidget->item(currentRow)->text();
    //delete itm1;
}

void MainWindow::on_comboBox_activated(int index)
{
    qDebug()<<"setting question type"<<index;
    curQues->setType(index);
}
void MainWindow::on_textEdit_textChanged()
{
    qDebug()<<"changing question"<<curText<<"text to "<<ui->textEdit->toPlainText();
    curQues->setText(ui->textEdit->toPlainText());
}

void MainWindow::on_textEdit_2_textChanged()
{
       qDebug()<<"changing explanation "<<curText<<" to "<<ui->textEdit_2->toPlainText();
       curQues->setAnswerExplanation(ui->textEdit_2->toPlainText());
}
void MainWindow::addQuestion(QString text){
    qDebug()<<questions.keys();
    if(!questions.contains(text)){
        Question *q=new Question(text);
        questions.insert(text, q);

    }
    qDebug()<<questions.keys();
//    qDebug()<<"THIS IS LIST: "<<questions.count();
//    foreach(QString s, questions.keys()){
//        qDebug()<<s<<":"<<questions.value(s)->getQuestion();
//    }
//    qDebug()<<"";
}

void MainWindow::loadData()
{
    ui->comboBox->setCurrentIndex(curQues->getType());
    ui->textEdit->setText(curQues->getQuestion());
    ui->textEdit_2->setText(curQues->getExplanation());
}

void MainWindow::saveData(QString key, Question *value)
{
    questions.insert(key, value);
}

void MainWindow::savenload(QString text)
{
    saveData(curText, curQues);
    curQues=questions.value(text);
    curText=text;
    loadData();
}

void MainWindow::on_questionsListWidget_clicked(const QModelIndex &index)
{
    QListWidgetItem *item=ui->questionsListWidget->currentItem();
    qDebug()<<"activated item: text "<<item->text();
    savenload(item->text());
}
