#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "question.h"
#include <QListWidget>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    int count;
    QList<Question*> questions;
    //QList<Question> *questions;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void addQuesion();
private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_questionsListWidget_itemActivated(QListWidgetItem *item);

    void on_comboBox_activated(int index);

    void on_comboBox_highlighted(int index);

    void on_textEdit_textChanged();

    void on_textEdit_2_textChanged();

    void on_questionsListWidget_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
