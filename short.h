#ifndef SHORT_H
#define SHORT_H


#include "answer.h"

class Short : public Answer
{
    Q_OBJECT
public:
    explicit Short(QWidget *parent, QLayout *layout, int id=0);
    ~Short();

    int getPrice() const;
    void setPrice(int value);

    QString getAnswerText() const;
    void setAnswerText(const QString &value);

private:
    QString answerText;
    int price=1;
    QHBoxLayout *answer = new QHBoxLayout(this);
signals:

public slots:
    void on_answerTextChanged(const QString&);
};

#endif // SHORT_H
