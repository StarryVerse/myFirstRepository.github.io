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
    int menu_choice;//���˵�ѡ��
    int search_choice;//��ѯ�Ӳ˵�ѡ��
    cout << "********  ��ӭʹ�ó�������ϵͳ  ********" << endl;
    cout << "========================================" << endl;
    cout << "*************  0.�˳�ϵͳ  *************" << endl;
    cout << "*************  1.��ӳ���  *************" << endl;
    cout << "*************  2.��ʾ������Ϣ��  *******" << endl;
    cout << "*************  3.ɾ������  *************" << endl;
    cout << "*************  4.�༭����  *************" << endl;
    cout << "*************  5.��ѯ����  *************" << endl;
    cout << "*************  6.ͳ����Ϣ  *************" << endl;
    cout << "*************  7.������Ϣ����  *********" << endl;
    cout << "*************  8.����������Ϣ  *********" << endl;
    cout << "*************  9.ϵͳ����  *************" << endl;
    cout << "========================================" << endl;
    cout << "****************************************" << endl;
    cout << "����������ѡ�� : ";
    cin >> menu_choice;
    switch (menu_choice)
    {
    case 0://�˳�ϵͳ
        exitsystem();
        break;
    case 1://��ӳ���
        add_vehicle();
        break;
    case 2://��ʾ������Ϣ��
        display();
        break;
    case 3://ɾ������
        dele_vehicle();
        break;
    case 4://�༭����
        system("cls");
        edit_vehicle();
        break;
    case 5://��ѯ����
    {
        search_menu();
        int esc=getch();    //ͨ��conio.hͷ�ļ��е�getch()����ʵ��esc�������˵�����
        if(esc==27)           //ASC��esc��ֵΪ27
        {
            system("cls");
            Menu();
        }
        cout << "����������ѡ�� : ";
        here:
        cin >> search_choice;

        switch (search_choice)
        {
        case 1://���������칫˾��ѯ
            search_1();
            break;
        case 2://����Ų�ѯ
            search_2();
            break;
        case 3://������ѯ
            search_3();
            break;
        default:
            cout<<"��������ȷ��ѡ��:";
            goto here;
            break;
        }
        break;
    }
    case 6:
        census_vehicle();//ͳ����Ϣ
        break;
    case 7:         //������Ϣ����
        save_vehicle();
        break;
    case 8:     //��ȡ������Ϣ
        read_vehicle();
        break;
    case 9:
        help();
        break;
    default:
        cout<<"������������,����������!";
        Sleep(1500);
        system("cls");
        Menu();
        break;
    }

}
void manager::search_menu()
{
    system("cls");
    cout << "***********  ��ѡ���ѯ��ʽ  ***********" << endl;
    cout << "========================================" << endl;
    cout << "***  ��ѯ��ʼǰ���� ESC �Է������˵�  **" << endl;
    cout << "********  1.���������칫˾��ѯ  ********" << endl;
    cout << "************  2.����Ų�ѯ  ************" << endl;
    cout << "************  3.������ѯ  ************" << endl;
    cout << "========================================" << endl;
    cout << "****************************************" << endl;
}

void manager::exitsystem()
{
    cout << "��ӭ�´�ʹ��" << endl;
    system("pause");
    exit(0);
}
void manager::back_menu()
{
    int choice;
    cout<<"��������0�Է������˵���"<<endl;
    here:
    cin>>choice;
    if(choice)
    {
        cout<<"������0�Է������˵�!"<<endl;
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
    cout << "**************  ��ӳ���  **************" << endl;
    cout << "========================================" << endl;
    cout << "*******  �밴����ʾ���복����Ϣ  *******" << endl;
    int id,add_choice;
    while (1)
    {
        if(number>N)
        {
            cout<<"������Ϣ������,��������ӳ���! ��������������"<<endl;
            Sleep(2000);
            system("cls");
            Menu();
            break;
        }
        here:
        cout << "�����복�����(����):";
        cin >> id;

        for (int i = 0; i < number; i++)
        {
            if (v[i].ID == id)
            {
                cout << "warning:��������ظ�����ȡ����ӣ�"<<endl;
                goto here;
                break;
            }
        }

            v[number].ID = id;
            cout << "���ƺ�:";
            cin >> v[number].PlateNumber;
            cout << "�������칫˾:";
            cin >> v[number].company;
            cout << "��������ʱ��(xxxx.xx.xx):";
            cin >> v[number].date;
            cout << "�ܹ�����(ʵ��):";
            cin >> v[number].mileage;
            cout << "������(L)/����(ʵ��):";
            cin >> v[number].OilConsumption;
            cout << "��·��(ʵ��):";
            cin >> v[number].RoadToll;

            cout << "�����ͺ�(1-�ͳ�,2-С�γ�,3-����):";

            there:
                cin >> v[number].type;
                if (v[number].type == 1)
                {
                    cout << "�ؿ���:";
                    cin >> v[number].passenger;
                    v[number].BasicMaintain = 2000;
                    strcpy(v[number].carriage,"-");
                    strcpy(v[number].goods,"-");
                    v[number].TotalCost=v[number].BasicMaintain+v[number].OilConsumption*oilprice;

                }
                else if (v[number].type == 2)
                {
                    cout << "����:";
                    cin >> v[number].carriage;
                    v[number].BasicMaintain = 1000;
                    strcpy(v[number].passenger,"-");
                    strcpy(v[number].goods,"-");
                    v[number].TotalCost=v[number].BasicMaintain+v[number].OilConsumption*oilprice;

                }
                else if (v[number].type == 3)
                {
                    cout << "������:";
                    cin >> v[number].goods;
                    v[number].BasicMaintain = 1500;
                    strcpy(v[number].carriage,"-");
                    strcpy(v[number].passenger,"-");
                    v[number].TotalCost=v[number].BasicMaintain+v[number].OilConsumption*oilprice;

                }
                else
                {
                    cout << "������������,����������:";
                    goto there;
                }
            number++;
            cout<<"�Ƿ�������(1-�ǣ�0-��)";
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
                cout<<"����������������������:";
                goto BBBB;
            }
        }
}

void manager::dele_vehicle()
{
    int id;
    system("cls");
    cout << "**************  ɾ������  **************" << endl;
    cout << "========================================" << endl;
    cout << "*******  �밴����ʾ���복����Ϣ  *******" << endl;
    while(1)
    {
        if(number==0)
        {
            cout<<"������Ϣ��Ϊ��!ϵͳ��������������"<<endl;
            Sleep(1500);
            system("cls");
            Menu();
            break;
        }
        else
        {
            here:
            int flag=0,index;
            cout<<"��������Ҫɾ���ĳ������:";
            cin>>id;
            for(int i=0;i<number;i++)
            {
                if(v[i].ID==id)   //������Ŵ���
                {
                    flag=1;
                    index=i;
                }
            }
            if(flag==0)
            {
                cout<<"�ñ�Ų�����!������������:";
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
            cout<<"�Ƿ����ɾ������?(1-��,0-��)";
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
                cout<<"����������������������:";
                goto there;
            }
        }
    }
}

void manager::display()
{
    system("cls");
    cout<<"**************************************************************  ������Ϣ��  **************************************************************"<<endl;
    cout<<" ��� "<<"|     "<<"���ƺ�"<<"     |     "<<"�������칫˾"<<"     |"<<"��������ʱ��"<<"|"<<"�����ͺ�"<<"|"<<"�ܹ�����"<<"|"<<"������(L)/����"<<"|"<<"����ά������"<<"|"<<"��·��"<<"|"<<"�ܷ���"<<"|"<<"�ؿ���"<<"|"<<"����"<<"|"<<"������";
    if(number<=0)
    {
        cout<<endl<<"��ǰ������Ϣ��Ϊ��,�����������˵�!"<<endl;
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
void manager::search_1()    //���������칫˾��ѯ
{
    int search_choice;
    string search_company;
    int index=-1;

    cout<<"�������복�������칫˾:";
    cin>>search_company;
    cout<<" ��� "<<"|     "<<"���ƺ�"<<"     |     "<<"�������칫˾"<<"     |"<<"��������ʱ��"<<"|"<<"�����ͺ�"<<"|"<<"�ܹ�����"<<"|"<<"������(L)/����"<<"|"<<"����ά������"<<"|"<<"��·��"<<"|"<<"�ܷ���"<<"|"<<"�ؿ���"<<"|"<<"����"<<"|"<<"������";
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
        cout<<endl<<"δ��ѯ�������Ϣ!"<<endl;
        back_menu();
    }
    else
    {
        cout<<endl<<"�Ƿ���б༭?(1-��,0-��)";
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
            cout<<"����������������������(1,0):";
            goto AAAA;
        }
    }

}
void manager::search_2()    //����Ų�ѯ
{
    int search_choice;
    int search_id;
    int index=-1;
    cout<<"�������복�������칫˾:";
    cin>>search_id;
    cout<<" ��� "<<"|     "<<"���ƺ�"<<"     |     "<<"�������칫˾"<<"     |"<<"��������ʱ��"<<"|"<<"�����ͺ�"<<"|"<<"�ܹ�����"<<"|"<<"������(L)/����"<<"|"<<"����ά������"<<"|"<<"��·��"<<"|"<<"�ܷ���"<<"|"<<"�ؿ���"<<"|"<<"����"<<"|"<<"������";
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
        cout<<endl<<"δ��ѯ�������Ϣ!"<<endl;
        back_menu();
    }
    else
    {
        cout<<endl<<"�Ƿ���б༭?(1-��,0-��)";
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
            cout<<"����������������������(1,0):";
            goto AAAA;
        }
    }

}
void manager::search_3()    //������ѯ
{
    int search_choice;
    int search_type;
    int index=-1;
    cout<<"�������복�������칫˾:";
    cin>>search_type;
    cout<<" ��� "<<"|     "<<"���ƺ�"<<"     |     "<<"�������칫˾"<<"     |"<<"��������ʱ��"<<"|"<<"�����ͺ�"<<"|"<<"�ܹ�����"<<"|"<<"������(L)/����"<<"|"<<"����ά������"<<"|"<<"��·��"<<"|"<<"�ܷ���"<<"|"<<"�ؿ���"<<"|"<<"����"<<"|"<<"������";
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
        cout<<endl<<"δ��ѯ�������Ϣ!"<<endl;
        back_menu();
    }
    else
    {
        cout<<endl<<"�Ƿ���б༭?(1-��,0-��)";
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
            cout<<"����������������������(1,0):";
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
    cout << "==============  �༭����  ==============" << endl;
    cout << "****************************************" << endl;
    cout<<"**tip:���븺�����˳�"<<endl;
    while(1)
    {
        cout << "�����복�����:";
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
            cout<<"�޸ó������!�����������˵�";
            Sleep(2000);
            system("cls");
            Menu();
            break;
        }

        v[index].ID=id;
        cout << "�����복�ƺ�:";
        cin>>v[index].PlateNumber;
        cout << "�����복�����칫˾:";
        cin >> v[index].company;
        cout << "�����복������ʱ��:";
        cin >> v[index].date;
        cout << "�������ܹ�����:";
        cin >> v[index].mileage;
        cout << "�����������(L)/����:";
        cin >> v[index].OilConsumption;
        cout << "��������·��:";
        cin >> v[index].RoadToll;

        cout << "�����복���ͺ�(1-�ͳ�,2-С�γ�,3-����):";

        here:
        cin >> v[index].type;
        if (v[index].type == 1)
        {
            cout << "�������ؿ���:";
            cin >> v[index].passenger;
            v[index].BasicMaintain = 2000;
            strcpy(v[index].carriage,"-");
            strcpy(v[index].goods,"-");
            v[index].TotalCost=v[index].BasicMaintain+v[index].OilConsumption*oilprice;

        }
        else if (v[index].type == 2)
        {
            cout << "����������:";
            cin >> v[index].carriage;
            v[index].BasicMaintain = 1000;
            strcpy(v[index].goods,"-");
            strcpy(v[index].passenger,"-");
            v[index].TotalCost=v[index].BasicMaintain+v[index].OilConsumption*oilprice;

        }
        else if (v[index].type == 3)
        {
            cout << "������������:";
            cin >> v[index].goods;
            v[index].BasicMaintain = 1500;
            strcpy(v[index].carriage,"-");
            strcpy(v[index].passenger,"-");
            v[index].TotalCost=v[index].BasicMaintain+v[index].OilConsumption*oilprice;

        }
        else
        {
            cout << "������������,����������(1,2,3):";
            goto here;
        }
        cout<<"�Ƿ�����༭?(1-��,0-��)";
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
            cout<<"����������������������(1,0):";
            goto AAAA;
        }
    }

}
void manager::census_vehicle()
{
    //(bus-1,car-2,truck-3)
    system("cls");
    cout << "****************************************" << endl;
    cout << "==============  ͳ����Ϣ  ==============" << endl;
    cout << "****************************************" << endl;
    int b=0;  //�ͳ�����
    int c=0;  //С�γ�����
    int t=0;  //��������
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
    cout<<"��������:"<<number<<endl;
    cout<<"�ͳ�����:"<<b<<endl;
    cout<<"С�γ�����:"<<c<<endl;
    cout<<"��������:"<<t<<endl;
    back_menu();

}

void manager::save_vehicle()
{
    ofstream outfile1("vehicles.dat",ios::app | ios::binary);
    ofstream outfile2("number.txt",ios::out);

    if((!outfile1)&&(!outfile2))
    {
        cerr<<"����ʧ��!"<<endl;
        back_menu();
    }
    outfile2<<number;
    for(int i=0;i<number;i++)
    {
        outfile1.write((char*)&v[i],sizeof(v[i]));

    }

    outfile1.close();
    outfile2.close();
    cout<<"���̳ɹ�!"<<endl;
    back_menu();
}
void manager::read_vehicle()
{
    int temp,i;
    ifstream infile1("vehicles.dat",ios::binary);
    ifstream infile2("number.txt",ios::in);
    if((!infile1)&&(!infile2))
    {
        cerr<<"����ʧ��!"<<endl;
        back_menu();
    }
    infile2>>temp;
    for(i=0;i<temp;i++)
    {
        infile1.read((char*)&v[i],sizeof(v[i]));
    }
    number+=i;
    cout<<"�ѳɹ���ȡ"<<i<<"����Ϣ!"<<endl;
    infile1.close();
    infile2.close();
    back_menu();
}

void manager::help()
{
    system("cls");
    cout<<"**********************************************************************************************************************"<<endl;
    cout<<"1.�밴���ϸ���ʾ������Ϣ�����������ɳ������;"<<endl;
    cout<<"2.����������ӡ��༭��ɾ������ʾ����ѯ��ͳ�ƹ��ܾ����ڴ��в���;"<<endl;
    cout<<"  �����ִ��Ч�ʸߵ��ŵ�,��ȱ���ǳ�������ʱ����ռ���ڴ�ռ�,���������ó���ִ��ʱ��Ϣ���������ݴ� 100 ����¼"<<endl;
    cout<<"3.ʹ�á�������Ϣ���̡�����,����ǰ�����еĳ�����Ϣ����һ���������ļ���vehicles.dat����һ��ASCII�ļ���number.txt����"<<endl;
    cout<<"  ���ж������ļ���ŵ�ǰ�����еĳ�����Ϣ��,�ı��ļ���ŵ�ǰ�����еĳ������������Խ��ù������ΪWord�еı��湦�ܡ�"<<endl;
    cout<<"4.ʹ�á�����������Ϣ������,���ѱ�����ļ��н�������Ϣ������򡣿������ΪWord�еĴ򿪹��ܡ�"<<endl;
    cout<<"5.���Ѿ�����������һ����¼������ʹ�á�����������Ϣ�����ܣ����ѱ���ĳ�����Ϣ��������С�"<<endl;
    cout<<"6.�˳�����ǰ�м�ʹ�á�����������Ϣ�����ܣ����������Ϣ��ʧ��"<<endl;
    cout<<"7.ÿ̨���������ܷ���=�ͼ�*������/����+����ά������(�о��ͼۼ��㷽ʽ�����⣬/Ӧ�øĳ�*,û�취��Ŀ��ôҪ���)"<<endl;
    cout<<"8.����ά�����ã��ͳ���2000Ԫ/�£�С�γ���1000Ԫ/�£�������1500Ԫ/��"<<endl;
    cout<<"9.�ͼ�����Ϊ7.5Ԫ/L"<<endl;
    cout<<"**********************************************************************************************************************"<<endl;
    cout<<"��ESC�Է������˵���";
    int esc=getch();
        if(esc==27)
        {
            system("cls");
            Menu();
        }
}
