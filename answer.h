#ifndef ANSWER_H
#define ANSWER_H

#include <QWidget>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QCheckBox>
#include <QSpinBox>
#include <QLabel>
#include <QRadioButton>
#include <QDebug>

class Answer : public QWidget
{
    Q_OBJECT
public:
    explicit Answer();
    ~Answer();
    int getId() const;
    void setId(int value);

    QWidget *getParent() const;
    void setParent(QWidget *value);

    QLayout *getLayout() const;
    void setLayout(QLayout *value);

private:
    QWidget *parent;
    QLayout *layout;
    int id;
signals:

public slots:
};

#endif // ANSWER_H
