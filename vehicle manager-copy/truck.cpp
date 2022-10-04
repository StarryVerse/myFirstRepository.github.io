#include "truck.h"

truck::truck()
{
    //ctor
}

truck::~truck()
{
    //dtor
}

void truck::setgoods(char Goods[10])
{
    strcpy(m_goods,Goods);
}
char* truck::getgoods()
{
    return m_goods;
}
