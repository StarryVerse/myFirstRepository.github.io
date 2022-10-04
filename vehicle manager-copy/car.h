#ifndef CAR_H
#define CAR_H
#include "vehicle.h"
#include <string.h>
class car:public vehicle
{
    public:
        car();
        virtual ~car();
        void setcarriage(char Carriage[10]);
        char *getcarriage();
    protected:

    private:
        char m_carriage[10];    //ÏäÊý
};

#endif // CAR_H
