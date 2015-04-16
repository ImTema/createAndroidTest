#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "question.h"
#include <QListWidget>
#include "settings.h"
#include <QGroupBox>
#include <QRadioButton>
#include <QSignalMapper>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    int countQuestions;
    QMap<QString,Question*> questions;
    Question* curQues;
    QString curText;
    Settings* sets;
    int countAnswers;
    QSignalMapper *signalMapper = new QSignalMapper(this);
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void clearLayout(QLayout& layout);
    void addQuestion(QString);
    void loadData();
    void saveData(QString, Question* );
    void savenload(QString);
    void compileTest();
    void generateAnswers(int);
    void generateCheckbox();
    void generateRadio();
    void generateSequence();
    void generateMatching();
    void generateShort();

private slots:
    void on_addQuestionButton_clicked();
    void on_deleteQuestionButton_clicked();
    void on_questionTypeComboBox_activated(int index);
    void on_questionTextTextEdit_textChanged();
    void on_explanationTextTextEdit_textChanged();
    void on_questionsListWidget_clicked(const QModelIndex &index);
    void on_limitedTimeTimeEdit_timeChanged(const QTime &time);
    void on_compileTestButton_released();

    void on_answerText_textChanged(const QString &s);


    void on_trueOrderedQuestions_toggled(bool checked);

    void on_insertImage_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
