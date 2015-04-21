#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <QHBoxLayout>
#include <QLineEdit>
#include <QCheckBox>
#include <QSpinBox>
#include <QLabel>
#include "answer.h"

class Checkbox : public Answer
{
    Q_OBJECT
public:
    explicit Checkbox(QWidget *parent, QLayout *layout, int id=0);
    ~Checkbox();

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

#endif // CHECKBOX_H
