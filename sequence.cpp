#include "sequence.h"

Sequence::Sequence(QWidget *parent, QLayout *layout, int id)
{
    setParent(parent);
    setLayout(layout);
    QLabel *sequenceNumber = new QLabel(QString::number(id+1));
    QLineEdit *answerText=new QLineEdit(this);
    //QPushButton *deleteAnswerButton=new QPushButton("Удалить");
    //answer->addWidget(deleteAnswerButton);
    answer->addWidget(sequenceNumber);
    answer->addWidget(answerText);
    getLayout()->addWidget(this);
    connect(answerText, SIGNAL(textChanged(QString)), this, SLOT(on_answerTextChanged(QString)));
    setId(id);
}

Sequence::~Sequence()
{

}

void Sequence::on_answerTextChanged(const QString &s)
{
    qDebug()<<"answerText #"<<getId()<<s;
    this->answerText=s;
}

