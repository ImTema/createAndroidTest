#ifndef RADIO_H
#define RADIO_H

#include <QHBoxLayout>
#include <QLineEdit>
#include <QRadioButton>
#include <QSpinBox>
#include <QLabel>
#include <QDebug>
#include "answer.h"

class Radio : public Answer
{
    Q_OBJECT
public:
    explicit Radio(QWidget *parent, QLayout *layout, int id=0);
    ~Radio();

    int getPrice() const;
    void setPrice(int value);

    bool getCorrect() const;
    void setCorrect(bool value);

    QString getAnswerText() const;
    void setAnswerText(const QString &value);

private:
    QString answerText;
    bool correct;
    int price;
    QWidget *parent;
    QHBoxLayout *answer = new QHBoxLayout(this);
signals:

public slots:
    void on_answerTextChanged(const QString&);
};

#endif // RADIO_H
