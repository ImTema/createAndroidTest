#include "radio.h"

Radio::Radio(QWidget *parent, QLayout *layout, int id)
{
    setParent(parent);
    setLayout(layout);
    QLineEdit *answerText=new QLineEdit(this);
    QRadioButton *correctRadio=new QRadioButton(this);
    correctRadio->setText("Правильный");
    QSpinBox *answerPrice=new QSpinBox(this);
    QLabel *priceLabel = new QLabel(this);
    priceLabel->setText("Стоимость");
    //QPushButton *deleteAnswerButton=new QPushButton("Удалить");
    answerPrice->setMaximum(10);
    answer->addWidget(answerText);
    answer->addWidget(correctRadio);
    answer->addWidget(answerPrice);
    answer->addWidget(priceLabel);
    //answer->addWidget(deleteAnswerButton);
    getLayout()->addWidget(this);
    connect(answerText, SIGNAL(textChanged(QString)), this, SLOT(on_answerTextChanged(QString)));
    setId(id);
}

Radio::~Radio()
{

}

void Radio::on_answerTextChanged(const QString &s)
{
    qDebug()<<"answerText #"<<getId()<<s;
    this->answerText=s;
}


int Radio::getPrice() const
{
    return price;
}

void Radio::setPrice(int value)
{
    price = value;
}

bool Radio::getCorrect() const
{
    return correct;
}

void Radio::setCorrect(bool value)
{
    correct = value;
}

QString Radio::getAnswerText() const
{
    return answerText;
}

void Radio::setAnswerText(const QString &value)
{
    answerText = value;
}

