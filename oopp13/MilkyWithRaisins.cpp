#include "MilkyWithRaisins.h"

int MilkyWithRaisins::getLength(int number)
{
    int counter = 0;
    while (number != 0)
    {
        counter++;
        number /= 10;
    }
    return counter;
}

MilkyWithRaisins::MilkyWithRaisins(int id, double milkProcentage, double raisinsPercantage)
{
    if (!validateId())
    {
        id = 45;
    }
    this->id = id;
    this->milkProcentage = milkProcentage;
    this->raisinsPercantage = raisinsPercantage;
}

bool MilkyWithRaisins::validateId()
{
    int length = getLength(id);
    return ((id / (pow(10, (length - 2)))) == 45);
}
