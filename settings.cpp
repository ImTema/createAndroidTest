#include "settings.h"

Settings::Settings()
{
    orderedQuestions=true;
    orderedAnswers=true;
    limitedTime.setHMS(0,0,0,0);
    numberOfQuestions=1;
}

Settings::~Settings()
{

}


bool Settings::getOrderedQuestions() const
{
    return orderedQuestions;
}

void Settings::setOrderedQuestions(bool value)
{
    orderedQuestions = value;
}

bool Settings::getOrderedAnswers() const
{
    return orderedAnswers;
}

void Settings::setOrderedAnswers(bool value)
{
    orderedAnswers = value;
}

QTime Settings::getLimitedTime() const
{
    return limitedTime;
}

void Settings::setLimitedTime(const QTime &value)
{
    limitedTime = value;
}

int Settings::getNumberOfQuestions() const
{
    return numberOfQuestions;
}

void Settings::setNumberOfQuestions(int value)
{
    numberOfQuestions = value;
}
