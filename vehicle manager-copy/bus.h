#ifndef BUS_H
#define BUS_H
#include "vehicle.h"
#include <string.h>
class bus
{
    public:
        bus();
        virtual ~bus();
        void setpassenger(char Passenger[10]);
        char *getpassenger();
    protected:

    private:
        char m_passenger[10];   //ть©ма©
};

#endif // BUS_H
