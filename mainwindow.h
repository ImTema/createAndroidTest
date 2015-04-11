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
    QMap<QString,Question*> questions;
    Question* curQues;
    QString curText;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void firstInitialization();
    void addQuestion(QString);
    void loadData();
    void saveData(QString, Question* );
    void savenload(QString);

private slots:

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_comboBox_activated(int index);
    void on_textEdit_textChanged();
    void on_textEdit_2_textChanged();

    void on_questionsListWidget_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
