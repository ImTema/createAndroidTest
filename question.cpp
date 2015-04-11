#include "question.h"

Question::Question(QString s)
{
    this->number=s;
    this->questionText="";
    this->questionType=0;
    this->answerExplanation="";
}
void Question::setText(QString text){
    this->questionText=text;
}

void Question::setAnswerExplanation(QString text)
{
    this->answerExplanation=text;
}

void Question::setType(int type)
{
    this->questionType=type;
}

int Question::getType()
{
    return this->questionType;
}

QString Question::getQuestion()
{
    return this->questionText;
}

QString Question::getExplanation()
{
    return this->answerExplanation;
}
QString Question::toString(){
    return "\nname: "+number
            +"\nType: "+QString::number(this->questionType)
            +"\nQuestion: "+this->questionText
            +"\nExplanation: "+this->answerExplanation
            +"\n";
}

QString Question::getText()
{
    return this->number;
}
Question::~Question()
{

}

