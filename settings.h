#ifndef SETTINGS_H
#define SETTINGS_H

#include <QTime>

class Settings
{
public:
    explicit Settings();
    ~Settings();
    bool getOrderedQuestions() const;
    void setOrderedQuestions(bool value);
    bool getOrderedAnswers() const;
    void setOrderedAnswers(bool value);
    QTime getLimitedTime() const;
    void setLimitedTime(const QTime &value);
    int getNumberOfQuestions() const;
    void setNumberOfQuestions(int value);

private:
    bool orderedQuestions;
    bool orderedAnswers;
    QTime limitedTime;
    int numberOfQuestions;
};

#endif // SETTINGS_H
