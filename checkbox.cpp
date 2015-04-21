#include "checkbox.h"
#include "mainwindow.h"

Checkbox::Checkbox(QWidget *parent, QLayout *layout, int id)
{
    setParent(parent);
    setLayout(layout);
    QLineEdit *answerText=new QLineEdit(this);
    QCheckBox *correctCheckbox=new QCheckBox(this);
    correctCheckbox->setText("Правильный");
    QSpinBox *answerPrice=new QSpinBox(this);
    QLabel *priceLabel = new QLabel(this);
    priceLabel->setText("Стоимость");
    //QPushButton *deleteAnswerButton=new QPushButton("Удалить");
    answerPrice->setMaximum(10);
    answer->addWidget(answerText);
    answer->addWidget(correctCheckbox);
    answer->addWidget(answerPrice);
    answer->addWidget(priceLabel);
    //answer->addWidget(deleteAnswerButton);
    getLayout()->addWidget(this);
    connect(answerText, SIGNAL(textChanged(QString)), this, SLOT(on_answerTextChanged(QString)));
    setId(id);
}

Checkbox::~Checkbox()
{

}

void Checkbox::on_answerTextChanged(const QString &s)
{
    qDebug()<<"answerText #"<<getId()<<s;
    this->answerText=s;
}


int Checkbox::getPrice() const
{
    return price;
}

void Checkbox::setPrice(int value)
{
    price = value;
}

bool Checkbox::getCorrect() const
{
    return correct;
}

void Checkbox::setCorrect(bool value)
{
    correct = value;
}

QString Checkbox::getAnswerText() const
{
    return answerText;
}

void Checkbox::setAnswerText(const QString &value)
{
    answerText = value;
}

