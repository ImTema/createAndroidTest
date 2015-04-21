#include "matching.h"

Matching::Matching(QWidget *parent, QLayout *layout, int id)
{
    setParent(parent);
    setLayout(layout);
    QLineEdit *answerText=new QLineEdit(this);
    QLineEdit *answerText2=new QLineEdit(this);
    QLabel *minusLabel = new QLabel(this);
    minusLabel->setText(" - ");
    //QPushButton *deleteAnswerButton=new QPushButton("Удалить");
    answer->addWidget(answerText);
    answer->addWidget(minusLabel);
    answer->addWidget(answerText2);
    //answer->addWidget(deleteAnswerButton);
    getLayout()->addWidget(this);
    connect(answerText, SIGNAL(textChanged(QString)), this, SLOT(on_answerTextChanged(QString)));
    connect(answerText2, SIGNAL(textChanged(QString)), this, SLOT(on_answerTextChanged2(QString)));
    setId(id);
}

Matching::~Matching()
{

}

void Matching::on_answerTextChanged(const QString &s)
{
    qDebug()<<"answerText #"<<getId()<<s;
    this->answerText=s;
}

void Matching::on_answerTextChanged2(const QString &s)
{
    qDebug()<<"answerText2 #"<<getId()<<s;
    this->answerText2=s;
}

