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


    void Menu();            //主菜单
    void search_menu();     //查询车辆子菜单界面
    void exitsystem();      //退出系统
    void back_menu();       //返回主菜单


    void add_vehicle();
    void dele_vehicle();
    void display();
    void search_1();    //按车辆制造公司查询
    void search_2();    //按编号查询
    void search_3();    //按类别查询
    void edit_vehicle();    //编辑功能
    void census_vehicle();  //统计功能
    void save_vehicle();    //车辆信息存盘
    void read_vehicle();    //读出车辆信息
    void help();
protected:

private:
};

#endif // MANAGER_H
