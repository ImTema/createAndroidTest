#ifndef QUESTION_H
#define QUESTION_H

#include <QString>
#include <answer.h>
#include <QMap>

class Question
{
public:
    explicit Question(QString);
    QString getQuestion();

    void setType(int type);
    int getType();

    void setAnswerExplanation(QString number);
    QString getExplanation();

    void setText(QString number);
    QString getText();

    QString getFileName() const;
    void setFileName(const QString &value);

    QMap<int, Answer *> getAnswers() const;
    void setAnswers(const QMap<int, Answer *> &value);

    QString toString();
    ~Question();

private:
    QMap<int, Answer*> answers;
    QString questionText;
    QString answerExplanation;
    int questionType;
    QString number;
    QString fileName;
};

#endif // QUESTION_H
