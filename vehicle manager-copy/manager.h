#ifndef MANAGER_H
#define MANAGER_H
#include <iostream>
#include <windows.h>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include "vehicle.h"
using namespace std;

class manager
{
public:
    manager();
    ~manager();


    void Menu();            //���˵�
    void search_menu();     //��ѯ�����Ӳ˵�����
    void exitsystem();      //�˳�ϵͳ
    void back_menu();       //�������˵�


    void add_vehicle();
    void dele_vehicle();
    void display();
    void search_1();    //���������칫˾��ѯ
    void search_2();    //����Ų�ѯ
    void search_3();    //������ѯ
    void edit_vehicle();    //�༭����
    void census_vehicle();  //ͳ�ƹ���
    void save_vehicle();    //������Ϣ����
    void read_vehicle();    //����������Ϣ
    void help();
protected:

private:
};

#endif // MANAGER_H
