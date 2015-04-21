#include "Short.h"
#include "mainwindow.h"

Short::Short(QWidget *parent, QLayout *layout, int id)
{
    setParent(parent);
    setLayout(layout);
    QLineEdit *answerText=new QLineEdit(this);
    QSpinBox *answerPrice=new QSpinBox(this);
    QLabel *priceLabel = new QLabel(this);
    priceLabel->setText("Стоимость");
    //QPushButton *deleteAnswerButton=new QPushButton("Удалить");
    answerPrice->setMaximum(10);
    answer->addWidget(answerText);
    answer->addWidget(answerPrice);
    answer->addWidget(priceLabel);
    //answer->addWidget(deleteAnswerButton);
    getLayout()->addWidget(this);
    connect(answerText, SIGNAL(textChanged(QString)), this, SLOT(on_answerTextChanged(QString)));
    setId(id);
}

Short::~Short()
{

}

void Short::on_answerTextChanged(const QString &s)
{
    qDebug()<<"answerText #"<<getId()<<s;
    this->answerText=s;
}


int Short::getPrice() const
{
    return price;
}

void Short::setPrice(int value)
{
    price = value;
}

QString Short::getAnswerText() const
{
    return answerText;
}

void Short::setAnswerText(const QString &value)
{
    answerText = value;
}

