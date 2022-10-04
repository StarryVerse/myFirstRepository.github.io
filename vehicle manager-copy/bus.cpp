#include "bus.h"

bus::bus()
{
    //ctor
}

bus::~bus()
{
    //dtor
}
void bus::setpassenger(char Passenger[10])
{
    strcpy(m_passenger,Passenger);
}
char* bus::getpassenger()
{
    return m_passenger;
}
