#ifndef SETTINGS_H
#define SETTINGS_H

#include <QTime>

class Settings
{
public:
    explicit Settings();
    ~Settings();
    void setOrderedQuestions(bool value);
    void setOrderedAnswers(bool value);
    void setOrderedAnswers(int value);
    void setNumberOfQuestions(int value);
    void setLimitedTime(const QTime &value);
    bool getOrderedQuestions() const;
    bool getOrderedAnswers() const;
    QTime getLimitedTime() const;
    int getNumberOfQuestions() const;

private:
    bool orderedQuestions;
    bool orderedAnswers;
    QTime limitedTime;
    int numberOfQuestions;
};

#endif // SETTINGS_H
