#ifndef VEHICLE_H
#define VEHICLE_H


class vehicle
{
    friend class manager;

private:
    int ID;             //�������
    char PlateNumber[20]; //���ƺ�
    char company[30];     //�������칫˾
    char date[15];        //��������ʱ��
    int type;        //�����ͺ�(bus-1,car-2,truck-3)
    double mileage;        //�ܹ�����
    double OilConsumption; //������/����
    int BasicMaintain;  //����ά������
    double RoadToll;       //��·��(��˵�⵽����ʲô����Ŀ��Ҳû��˵��)
    double TotalCost;      //�ܷ���

    char passenger[10];   //�ؿ���
    char carriage[10];   //����
    char goods[10];      //������
};

#endif // VEHICLE_H
