#include "answer.h"


Answer::Answer()
{
}

Answer::~Answer()
{

}


int Answer::getId() const
{
    return id;
}

void Answer::setId(int value)
{
    id = value;
}

QWidget *Answer::getParent() const
{
    return parent;
}

void Answer::setParent(QWidget *value)
{
    parent = value;
}

QLayout *Answer::getLayout() const
{
    return layout;
}

void Answer::setLayout(QLayout *value)
{
    layout = value;
}
