#include "car.h"

car::car()
{
    //ctor
}

car::~car()
{
    //dtor
}

void car::setcarriage(char Carriage[10])
{
    strcpy(m_carriage,Carriage);
}
char* car::getcarriage()
{
    return m_carriage;
}
