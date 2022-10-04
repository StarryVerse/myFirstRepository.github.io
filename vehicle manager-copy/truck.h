#ifndef TRUCK_H
#define TRUCK_H
#include "vehicle.h"
#include <string.h>
class truck
{
    public:
        truck();
        virtual ~truck();
        void setgoods(char Goods[10]);
        char *getgoods();
    protected:

    private:
        char m_goods[10];   //‘ÿ÷ÿ¡ø
};

#endif // TRUCK_H
