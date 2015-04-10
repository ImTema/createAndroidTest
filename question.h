#ifndef QUESTION_H
#define QUESTION_H

#include <QString>

class Question
{
public:
    explicit Question(QString);
    void setText(QString text);
    void setAnswerExplanation(QString text);
    void setType();
    int getType();
    QString getQuestion();
    QString getExplanation();
    QString toString();
    ~Question();
private:
    QString questionText;
    QString answerExplanation;
    QString questionType;
    QString text;
};

#endif // QUESTION_H
