#ifndef Sequence_H
#define Sequence_H

#include <QHBoxLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QLabel>

#include "answer.h"

class Sequence : public Answer
{
    Q_OBJECT
public:
    explicit Sequence(QWidget *parent, QLayout *layout, int id=0);
    ~Sequence();

private:
    QString answerText;
    QHBoxLayout *answer = new QHBoxLayout(this);
signals:

public slots:
    void on_answerTextChanged(const QString&);
};

#endif // Sequence_H
