#ifndef MATCHING_H
#define MATCHING_H

#include "answer.h"

class Matching : public Answer
{
    Q_OBJECT
public:
    explicit Matching(QWidget *parent, QLayout *layout, int id=0);
    ~Matching();
private:
    QHBoxLayout *answer = new QHBoxLayout(this);
    QString answerText;
    QString answerText2;
signals:

public slots:
    void on_answerTextChanged(const QString &s);
    void on_answerTextChanged2(const QString &s);
};

#endif // MATCHING_H
