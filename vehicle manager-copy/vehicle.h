#ifndef VEHICLE_H
#define VEHICLE_H


class vehicle
{
    friend class manager;

private:
    int ID;             //车辆编号
    char PlateNumber[20]; //车牌号
    char company[30];     //车辆制造公司
    char date[15];        //车辆购买时间
    int type;        //车辆型号(bus-1,car-2,truck-3)
    double mileage;        //总公里数
    double OilConsumption; //耗油量/公里
    int BasicMaintain;  //基本维护费用
    double RoadToll;       //养路费(话说这到底是什么，题目里也没有说明)
    double TotalCost;      //总费用

    char passenger[10];   //载客量
    char carriage[10];   //箱数
    char goods[10];      //载重量
};

#endif // VEHICLE_H
