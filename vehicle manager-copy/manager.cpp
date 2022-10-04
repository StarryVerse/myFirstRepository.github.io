#include "manager.h"
#define N 100
#define oilprice 7.5
vehicle v[N];
int  number;

manager::manager()
{

}
manager::~manager()
{

}

void manager::Menu()
{
    int menu_choice;//主菜单选择
    int search_choice;//查询子菜单选择
    cout << "********  欢迎使用车辆管理系统  ********" << endl;
    cout << "========================================" << endl;
    cout << "*************  0.退出系统  *************" << endl;
    cout << "*************  1.添加车辆  *************" << endl;
    cout << "*************  2.显示车辆信息库  *******" << endl;
    cout << "*************  3.删除车辆  *************" << endl;
    cout << "*************  4.编辑功能  *************" << endl;
    cout << "*************  5.查询车辆  *************" << endl;
    cout << "*************  6.统计信息  *************" << endl;
    cout << "*************  7.车辆信息存盘  *********" << endl;
    cout << "*************  8.读出车辆信息  *********" << endl;
    cout << "*************  9.系统帮助  *************" << endl;
    cout << "========================================" << endl;
    cout << "****************************************" << endl;
    cout << "请输入您的选择 : ";
    cin >> menu_choice;
    switch (menu_choice)
    {
    case 0://退出系统
        exitsystem();
        break;
    case 1://添加车辆
        add_vehicle();
        break;
    case 2://显示车辆信息库
        display();
        break;
    case 3://删除车辆
        dele_vehicle();
        break;
    case 4://编辑功能
        system("cls");
        edit_vehicle();
        break;
    case 5://查询车辆
    {
        search_menu();
        int esc=getch();    //通过conio.h头文件中的getch()函数实现esc返回主菜单功能
        if(esc==27)           //ASC中esc的值为27
        {
            system("cls");
            Menu();
        }
        cout << "请输入您的选择 : ";
        here:
        cin >> search_choice;

        switch (search_choice)
        {
        case 1://按车辆制造公司查询
            search_1();
            break;
        case 2://按编号查询
            search_2();
            break;
        case 3://按类别查询
            search_3();
            break;
        default:
            cout<<"请输入正确的选项:";
            goto here;
            break;
        }
        break;
    }
    case 6:
        census_vehicle();//统计信息
        break;
    case 7:         //车辆信息存盘
        save_vehicle();
        break;
    case 8:     //读取车辆信息
        read_vehicle();
        break;
    case 9:
        help();
        break;
    default:
        cout<<"您的输入有误,请重新输入!";
        Sleep(1500);
        system("cls");
        Menu();
        break;
    }

}
void manager::search_menu()
{
    system("cls");
    cout << "***********  请选择查询方式  ***********" << endl;
    cout << "========================================" << endl;
    cout << "***  查询开始前按下 ESC 以返回主菜单  **" << endl;
    cout << "********  1.按车辆制造公司查询  ********" << endl;
    cout << "************  2.按编号查询  ************" << endl;
    cout << "************  3.按类别查询  ************" << endl;
    cout << "========================================" << endl;
    cout << "****************************************" << endl;
}

void manager::exitsystem()
{
    cout << "欢迎下次使用" << endl;
    system("pause");
    exit(0);
}
void manager::back_menu()
{
    int choice;
    cout<<"请您输入0以返回主菜单。"<<endl;
    here:
    cin>>choice;
    if(choice)
    {
        cout<<"请输入0以返回主菜单!"<<endl;
        goto here;
    }
    else
    {
        system("cls");
        Menu();
    }
}
void manager::add_vehicle()
{
    system("cls");
    cout << "**************  添加车辆  **************" << endl;
    cout << "========================================" << endl;
    cout << "*******  请按照提示输入车辆信息  *******" << endl;
    int id,add_choice;
    while (1)
    {
        if(number>N)
        {
            cout<<"车辆信息库已满,不能再添加车辆! 即将返回主界面"<<endl;
            Sleep(2000);
            system("cls");
            Menu();
            break;
        }
        here:
        cout << "请输入车辆编号(整型):";
        cin >> id;

        for (int i = 0; i < number; i++)
        {
            if (v[i].ID == id)
            {
                cout << "warning:数据添加重复，已取消添加！"<<endl;
                goto here;
                break;
            }
        }

            v[number].ID = id;
            cout << "车牌号:";
            cin >> v[number].PlateNumber;
            cout << "车辆制造公司:";
            cin >> v[number].company;
            cout << "车辆购买时间(xxxx.xx.xx):";
            cin >> v[number].date;
            cout << "总公里数(实数):";
            cin >> v[number].mileage;
            cout << "耗油量(L)/公里(实数):";
            cin >> v[number].OilConsumption;
            cout << "养路费(实数):";
            cin >> v[number].RoadToll;

            cout << "车辆型号(1-客车,2-小轿车,3-卡车):";

            there:
                cin >> v[number].type;
                if (v[number].type == 1)
                {
                    cout << "载客量:";
                    cin >> v[number].passenger;
                    v[number].BasicMaintain = 2000;
                    strcpy(v[number].carriage,"-");
                    strcpy(v[number].goods,"-");
                    v[number].TotalCost=v[number].BasicMaintain+v[number].OilConsumption*oilprice;

                }
                else if (v[number].type == 2)
                {
                    cout << "箱数:";
                    cin >> v[number].carriage;
                    v[number].BasicMaintain = 1000;
                    strcpy(v[number].passenger,"-");
                    strcpy(v[number].goods,"-");
                    v[number].TotalCost=v[number].BasicMaintain+v[number].OilConsumption*oilprice;

                }
                else if (v[number].type == 3)
                {
                    cout << "载重量:";
                    cin >> v[number].goods;
                    v[number].BasicMaintain = 1500;
                    strcpy(v[number].carriage,"-");
                    strcpy(v[number].passenger,"-");
                    v[number].TotalCost=v[number].BasicMaintain+v[number].OilConsumption*oilprice;

                }
                else
                {
                    cout << "您的输入有误,请重新输入:";
                    goto there;
                }
            number++;
            cout<<"是否继续添加(1-是，0-否)";
            BBBB:
            cin>>add_choice;
            if(add_choice==0)
            {
//                outfile1.close();
                system("cls");
                Menu();
                break;
            }
            else if(add_choice==1)
            {
                continue;
            }
            else
            {
                cout<<"您的输入有误，请重新输入:";
                goto BBBB;
            }
        }
}

void manager::dele_vehicle()
{
    int id;
    system("cls");
    cout << "**************  删除车辆  **************" << endl;
    cout << "========================================" << endl;
    cout << "*******  请按照提示输入车辆信息  *******" << endl;
    while(1)
    {
        if(number==0)
        {
            cout<<"车辆信息库为空!系统即将返回主界面"<<endl;
            Sleep(1500);
            system("cls");
            Menu();
            break;
        }
        else
        {
            here:
            int flag=0,index;
            cout<<"请输入需要删除的车辆编号:";
            cin>>id;
            for(int i=0;i<number;i++)
            {
                if(v[i].ID==id)   //车辆编号存在
                {
                    flag=1;
                    index=i;
                }
            }
            if(flag==0)
            {
                cout<<"该编号不存在!请重新输入编号:";
                goto here;
            }
            else
            {
                for(index;index<number-1;index++)
                {
                    v[index]=v[index+1];
                }
                number--;
            }
            int dele_choice;
            cout<<"是否继续删除车辆?(1-是,0-否)";
            there:
            cin>>dele_choice;
            if(dele_choice==0)
            {
                system("cls");
                Menu();
            }
            else if(dele_choice==1)
            {
                continue;
            }
            else
            {
                cout<<"您的输入有误，请重新输入:";
                goto there;
            }
        }
    }
}

void manager::display()
{
    system("cls");
    cout<<"**************************************************************  车辆信息库  **************************************************************"<<endl;
    cout<<" 编号 "<<"|     "<<"车牌号"<<"     |     "<<"车辆制造公司"<<"     |"<<"车辆购买时间"<<"|"<<"车辆型号"<<"|"<<"总公里数"<<"|"<<"耗油量(L)/公里"<<"|"<<"基本维护费用"<<"|"<<"养路费"<<"|"<<"总费用"<<"|"<<"载客量"<<"|"<<"箱数"<<"|"<<"载重量";
    if(number<=0)
    {
        cout<<endl<<"当前车辆信息库为空,即将返回主菜单!"<<endl;
        Sleep(2000);
        system("cls");
        Menu();
    }
    else
    {
        for(int i=0;i<number;i++)
        {
            cout<<endl<<std::left<<setw(6)<<v[i].ID<<"|"<<std::left<<setw(16)<<v[i].PlateNumber<<"|"
            <<std::left<<setw(22)<<v[i].company<<"|"<<std::left<<setw(12)<<v[i].date<<"|"<<std::left<<setw(8)<<v[i].type<<"|"
            <<std::left<<setw(8)<<v[i].mileage<<"|"<<std::left<<setw(14)<<v[i].OilConsumption<<"|"
            <<std::left<<setw(12)<<v[i].BasicMaintain<<"|"<<std::left<<setw(6)<<v[i].RoadToll<<"|"
            <<std::left<<setw(6)<<v[i].TotalCost<<"|"<<std::left<<setw(6)<<v[i].passenger<<"|"
            <<std::left<<setw(4)<<v[i].carriage<<"|"<<std::left<<setw(6)<<v[i].goods;
        }
        cout<<endl;
        back_menu();
    }
}
void manager::search_1()    //按车辆制造公司查询
{
    int search_choice;
    string search_company;
    int index=-1;

    cout<<"请您输入车辆的制造公司:";
    cin>>search_company;
    cout<<" 编号 "<<"|     "<<"车牌号"<<"     |     "<<"车辆制造公司"<<"     |"<<"车辆购买时间"<<"|"<<"车辆型号"<<"|"<<"总公里数"<<"|"<<"耗油量(L)/公里"<<"|"<<"基本维护费用"<<"|"<<"养路费"<<"|"<<"总费用"<<"|"<<"载客量"<<"|"<<"箱数"<<"|"<<"载重量";
    for(int i=0;i<number;i++)
    {
        if(search_company==v[i].company)
        {
            index=i;

            cout<<endl<<std::left<<setw(6)<<v[index].ID<<"|"<<std::left<<setw(16)<<v[index].PlateNumber<<"|"
                <<std::left<<setw(22)<<v[index].company<<"|"<<std::left<<setw(12)<<v[index].date<<"|"<<std::left<<setw(8)<<v[index].type<<"|"
                <<std::left<<setw(8)<<v[index].mileage<<"|"<<std::left<<setw(14)<<v[index].OilConsumption<<"|"
                <<std::left<<setw(12)<<v[index].BasicMaintain<<"|"<<std::left<<setw(6)<<v[index].RoadToll<<"|"
                <<std::left<<setw(6)<<v[index].TotalCost<<"|"<<std::left<<setw(6)<<v[index].passenger<<"|"
                <<std::left<<setw(4)<<v[index].carriage<<"|"<<std::left<<setw(6)<<v[index].goods;
        }
    }
    if(index==-1)
    {
        cout<<endl<<"未查询到相关信息!"<<endl;
        back_menu();
    }
    else
    {
        cout<<endl<<"是否进行编辑?(1-是,0-否)";
        AAAA:
        cin>>search_choice;
        if(search_choice==1)
        {
            edit_vehicle();
        }
        else if(search_choice==0)
        {
            system("cls");
            Menu();
        }
        else
        {
            cout<<"您的输入有误，请重新输入(1,0):";
            goto AAAA;
        }
    }

}
void manager::search_2()    //按编号查询
{
    int search_choice;
    int search_id;
    int index=-1;
    cout<<"请您输入车辆的制造公司:";
    cin>>search_id;
    cout<<" 编号 "<<"|     "<<"车牌号"<<"     |     "<<"车辆制造公司"<<"     |"<<"车辆购买时间"<<"|"<<"车辆型号"<<"|"<<"总公里数"<<"|"<<"耗油量(L)/公里"<<"|"<<"基本维护费用"<<"|"<<"养路费"<<"|"<<"总费用"<<"|"<<"载客量"<<"|"<<"箱数"<<"|"<<"载重量";
    for(int i=0;i<number;i++)
    {
        if(search_id==v[i].ID)
        {
            index=i;
            cout<<endl<<std::left<<setw(6)<<v[index].ID<<"|"<<std::left<<setw(16)<<v[index].PlateNumber<<"|"
                <<std::left<<setw(22)<<v[index].company<<"|"<<std::left<<setw(12)<<v[index].date<<"|"<<std::left<<setw(8)<<v[index].type<<"|"
                <<std::left<<setw(8)<<v[index].mileage<<"|"<<std::left<<setw(14)<<v[index].OilConsumption<<"|"
                <<std::left<<setw(12)<<v[index].BasicMaintain<<"|"<<std::left<<setw(6)<<v[index].RoadToll<<"|"
                <<std::left<<setw(6)<<v[index].TotalCost<<"|"<<std::left<<setw(6)<<v[index].passenger<<"|"
                <<std::left<<setw(4)<<v[index].carriage<<"|"<<std::left<<setw(6)<<v[index].goods;
        }
    }
    if(index==-1)
    {
        cout<<endl<<"未查询到相关信息!"<<endl;
        back_menu();
    }
    else
    {
        cout<<endl<<"是否进行编辑?(1-是,0-否)";
        AAAA:
        cin>>search_choice;
        if(search_choice==1)
        {
            edit_vehicle();
        }
        else if(search_choice==0)
        {
            system("cls");
            Menu();
        }
        else
        {
            cout<<"您的输入有误，请重新输入(1,0):";
            goto AAAA;
        }
    }

}
void manager::search_3()    //按类别查询
{
    int search_choice;
    int search_type;
    int index=-1;
    cout<<"请您输入车辆的制造公司:";
    cin>>search_type;
    cout<<" 编号 "<<"|     "<<"车牌号"<<"     |     "<<"车辆制造公司"<<"     |"<<"车辆购买时间"<<"|"<<"车辆型号"<<"|"<<"总公里数"<<"|"<<"耗油量(L)/公里"<<"|"<<"基本维护费用"<<"|"<<"养路费"<<"|"<<"总费用"<<"|"<<"载客量"<<"|"<<"箱数"<<"|"<<"载重量";
    for(int i=0;i<number;i++)
    {
        if(search_type==v[i].type)
        {
            index=i;
            cout<<endl<<std::left<<setw(6)<<v[index].ID<<"|"<<std::left<<setw(16)<<v[index].PlateNumber<<"|"
                <<std::left<<setw(22)<<v[index].company<<"|"<<std::left<<setw(12)<<v[index].date<<"|"<<std::left<<setw(8)<<v[index].type<<"|"
                <<std::left<<setw(8)<<v[index].mileage<<"|"<<std::left<<setw(14)<<v[index].OilConsumption<<"|"
                <<std::left<<setw(12)<<v[index].BasicMaintain<<"|"<<std::left<<setw(6)<<v[index].RoadToll<<"|"
                <<std::left<<setw(6)<<v[index].TotalCost<<"|"<<std::left<<setw(6)<<v[index].passenger<<"|"
                <<std::left<<setw(4)<<v[index].carriage<<"|"<<std::left<<setw(6)<<v[index].goods;
        }
    }
    if(index==-1)
    {
        cout<<endl<<"未查询到相关信息!"<<endl;
        back_menu();
    }
    else
    {
        cout<<endl<<"是否进行编辑?(1-是,0-否)";
        AAAA:
        cin>>search_choice;
        if(search_choice==1)
        {
            edit_vehicle();
        }
        else if(search_choice==0)
        {
            system("cls");
            Menu();
        }
        else
        {
            cout<<"您的输入有误，请重新输入(1,0):";
            goto AAAA;
        }
    }
}
void manager::edit_vehicle()
{
    int id;
    int index=-1;
    int edit_choice;
    cout << "****************************************" << endl;
    cout << "==============  编辑功能  ==============" << endl;
    cout << "****************************************" << endl;
    cout<<"**tip:输入负数以退出"<<endl;
    while(1)
    {
        cout << "请输入车辆编号:";
        cin>>id;
        for(int i=0;i<number;i++)
        {
            if(v[i].ID==id)
            {
                index=i;
            }
        }
        if(index==-1)
        {
            cout<<"无该车辆编号!即将返回主菜单";
            Sleep(2000);
            system("cls");
            Menu();
            break;
        }

        v[index].ID=id;
        cout << "请输入车牌号:";
        cin>>v[index].PlateNumber;
        cout << "请输入车辆制造公司:";
        cin >> v[index].company;
        cout << "请输入车辆购买时间:";
        cin >> v[index].date;
        cout << "请输入总公里数:";
        cin >> v[index].mileage;
        cout << "请输入耗油量(L)/公里:";
        cin >> v[index].OilConsumption;
        cout << "请输入养路费:";
        cin >> v[index].RoadToll;

        cout << "请输入车辆型号(1-客车,2-小轿车,3-卡车):";

        here:
        cin >> v[index].type;
        if (v[index].type == 1)
        {
            cout << "请输入载客量:";
            cin >> v[index].passenger;
            v[index].BasicMaintain = 2000;
            strcpy(v[index].carriage,"-");
            strcpy(v[index].goods,"-");
            v[index].TotalCost=v[index].BasicMaintain+v[index].OilConsumption*oilprice;

        }
        else if (v[index].type == 2)
        {
            cout << "请输入箱数:";
            cin >> v[index].carriage;
            v[index].BasicMaintain = 1000;
            strcpy(v[index].goods,"-");
            strcpy(v[index].passenger,"-");
            v[index].TotalCost=v[index].BasicMaintain+v[index].OilConsumption*oilprice;

        }
        else if (v[index].type == 3)
        {
            cout << "请输入载重量:";
            cin >> v[index].goods;
            v[index].BasicMaintain = 1500;
            strcpy(v[index].carriage,"-");
            strcpy(v[index].passenger,"-");
            v[index].TotalCost=v[index].BasicMaintain+v[index].OilConsumption*oilprice;

        }
        else
        {
            cout << "您的输入有误,请重新输入(1,2,3):";
            goto here;
        }
        cout<<"是否继续编辑?(1-是,0-否)";
        AAAA:
        cin>>edit_choice;
        if(edit_choice==1)
        {
            continue;
        }
        else if(edit_choice==0)
        {
            system("cls");
            Menu();
            break;
        }
        else
        {
            cout<<"您的输入有误，请重新输入(1,0):";
            goto AAAA;
        }
    }

}
void manager::census_vehicle()
{
    //(bus-1,car-2,truck-3)
    system("cls");
    cout << "****************************************" << endl;
    cout << "==============  统计信息  ==============" << endl;
    cout << "****************************************" << endl;
    int b=0;  //客车数量
    int c=0;  //小轿车数量
    int t=0;  //卡车数量
    int census_choice;
    for(int i=0;i<number;i++)
    {
        if(v[i].type==1)
            b++;
        if(v[i].type==2)
            c++;
        if(v[i].type==3)
            t++;
    }
    cout<<"车辆总数:"<<number<<endl;
    cout<<"客车总数:"<<b<<endl;
    cout<<"小轿车总数:"<<c<<endl;
    cout<<"卡车总数:"<<t<<endl;
    back_menu();

}

void manager::save_vehicle()
{
    ofstream outfile1("vehicles.dat",ios::app | ios::binary);
    ofstream outfile2("number.txt",ios::out);

    if((!outfile1)&&(!outfile2))
    {
        cerr<<"存盘失败!"<<endl;
        back_menu();
    }
    outfile2<<number;
    for(int i=0;i<number;i++)
    {
        outfile1.write((char*)&v[i],sizeof(v[i]));

    }

    outfile1.close();
    outfile2.close();
    cout<<"存盘成功!"<<endl;
    back_menu();
}
void manager::read_vehicle()
{
    int temp,i;
    ifstream infile1("vehicles.dat",ios::binary);
    ifstream infile2("number.txt",ios::in);
    if((!infile1)&&(!infile2))
    {
        cerr<<"读入失败!"<<endl;
        back_menu();
    }
    infile2>>temp;
    for(i=0;i<temp;i++)
    {
        infile1.read((char*)&v[i],sizeof(v[i]));
    }
    number+=i;
    cout<<"已成功读取"<<i<<"条信息!"<<endl;
    infile1.close();
    infile2.close();
    back_menu();
}

void manager::help()
{
    system("cls");
    cout<<"**********************************************************************************************************************"<<endl;
    cout<<"1.请按照严格提示输入信息，否则可能造成程序崩溃;"<<endl;
    cout<<"2.本程序的增加、编辑、删除、显示、查询、统计功能均在内存中操作;"<<endl;
    cout<<"  因此有执行效率高的优点,但缺点是程序运行时容易占用内存空间,所以我设置程序执行时信息库中最多可暂存 100 条记录"<<endl;
    cout<<"3.使用“车辆信息存盘”功能,将当前程序中的车辆信息存入一个二进制文件（vehicles.dat）和一个ASCII文件（number.txt）中"<<endl;
    cout<<"  其中二进制文件存放当前程序中的车辆信息库,文本文件存放当前程序中的车辆总数。可以将该功能理解为Word中的保存功能。"<<endl;
    cout<<"4.使用“读出车辆信息”功能,从已保存的文件中将车辆信息读入程序。可以理解为Word中的打开功能。"<<endl;
    cout<<"5.若已经保存了至少一条记录，请先使用“读出车辆信息”功能，将已保存的车辆信息读入程序中。"<<endl;
    cout<<"6.退出程序前切记使用“读出车辆信息”功能，以免造成信息丢失。"<<endl;
    cout<<"7.每台车辆当月总费用=油价*耗油量/公里+基本维护费用(感觉油价计算方式有问题，/应该改成*,没办法题目这么要求的)"<<endl;
    cout<<"8.基本维护费用：客车：2000元/月，小轿车：1000元/月，卡车：1500元/月"<<endl;
    cout<<"9.油价设置为7.5元/L"<<endl;
    cout<<"**********************************************************************************************************************"<<endl;
    cout<<"按ESC以返回主菜单。";
    int esc=getch();
        if(esc==27)
        {
            system("cls");
            Menu();
        }
}
