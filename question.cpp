#include "question.h"

Question::Question(QString s)
{
    this->text=s;
}
void Question::setText(QString text){
    this->questionText=text;
}

void Question::setAnswerExplanation(QString text)
{
    this->answerExplanation=text;
}
QString Question::toString(){
    return text;
}
Question::~Question()
{

}

