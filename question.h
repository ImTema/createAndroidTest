#ifndef QUESTION_H
#define QUESTION_H

#include <QString>

class Question
{
public:
    explicit Question(QString);
    void setText(QString number);
    void setAnswerExplanation(QString number);
    void setType(int type);
    int getType();
    QString getQuestion();
    QString getExplanation();
    QString toString();
    QString getText();
    ~Question();
private:
    QString questionText;
    QString answerExplanation;
    int questionType;
    QString number;
};

#endif // QUESTION_H
