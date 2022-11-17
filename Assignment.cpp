#include <iostream>
#include <string>
using namespace std;

int resistorsinseries();
int resistorsinparallel();
int startodeltaconversion();
int deltatostarconversion();
int calresistor();
int fourbar();
int fivebar();
string checkR(string Color[]); // ประกาศฟังก์ชั่น
string checkR5(string Color5[]);

string Color[4];                                     // เก็บสีรับจากแป้น
int getArrayLength = sizeof(Color) / sizeof(string); // เก็บค่าสีตัวต้านทานที่ป้อน

string Color5[5];
int getArrayLength5 = sizeof(Color5) / sizeof(string); // เก็บค่าสีตัวต้านทานที่ป้อน

int main()
{
    int menu;
    cout << "\n=========================================" << endl;
    cout << "THIS IS PROGRAM CALCULATE RESISTORS VALUE" << endl;
    cout << "1.Resistors in Series\n";
    cout << "2.Resistors in Parallel\n";
    cout << "3.Star to Delta Conversion\n";
    cout << "4.Delta to Star Conversion\n";
    cout << "5.Calculate the value of the resistors\n";
    cout << "6.Exit Program\n";
    cout << "PLEASE SELECT NUMBER : ";
    cin >> menu;
    cout << "==========================================" << endl;

    if (menu == 1)
    {
        resistorsinseries();
    }
    else if (menu == 2)
    {
        resistorsinparallel();
    }
    else if (menu == 3)
    {
        startodeltaconversion();
    }
    else if (menu == 4)
    {
        deltatostarconversion();
    }
    else if (menu == 5)
    {
        calresistor();
    }
    else if (menu == 6)
    {
        return (0);
    }
    else
    {
        cout << "Erorr, You entered the wrong number!!" << endl;
    }

    return main();
}

int resistorsinseries()
{
    float resistors, RT, num = 0;
    cout << "Please Enter the resistors in only ohms" << endl;
    cout << "Enter the number of resistors : ";
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cout << "Enter resistors " << i + 1 << " : ";
        cin >> resistors;
        RT = RT + resistors;
    }
    cout << "Resistors Total : " << RT << " ohms." << endl;

    return (0);
}

int resistorsinparallel()
{
    float RT, R, resistors, num = 0;
    cout << "Please enter the resistors in only ohms" << endl;
    cout << "Enter the number of resistors : ";
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cout << "Enter resistors " << i + 1 << " : ";
        cin >> resistors;
        R = R + 1 / resistors;
    }
    RT = 1 / R;

    cout << "Resistors Total : " << RT << " ohms";

    return (0);
}

int startodeltaconversion()
{
    float RA, RB, RC, RAB, RAC, RBC;
    cout << "Please enter the resistors in only ohms" << endl;
    cout << "Enter A resistors : ";
    cin >> RA;
    cout << "Enter B resistors : ";
    cin >> RB;
    cout << "Enter C resistors : ";
    cin >> RC;
    RAB = RA + RB + (RA * RB) / RC;
    RBC = RB + RC + (RB * RC) / RA;
    RAC = RA + RC + (RA * RC) / RB;
    cout << "Resistors AB : " << RAB << " ohms" << endl;
    cout << "Resistors BC : " << RBC << " ohms" << endl;
    cout << "Resistors AC : " << RAC << " ohms" << endl;
    return (0);
}

int deltatostarconversion()
{
    float RAB, RBC, RAC, RA, RB, RC;
    cout << "Please enter the resistors in only ohms" << endl;
    cout << "Enter Resistors AB : ";
    cin >> RAB;
    cout << "Enter Resistors BC : ";
    cin >> RBC;
    cout << "Enter Resistors AC : ";
    cin >> RAC;
    RA = (RAB * RAC) / (RAB + RBC + RAC);
    RB = (RAB * RBC) / (RAB + RBC + RAC);
    RC = (RBC * RAC) / (RAB + RBC + RAC);
    cout << "Resistors A : " << RA << " ohms" << endl;
    cout << "Resistors B : " << RB << " ohms" << endl;
    cout << "Resistors C : " << RC << " ohms" << endl;
    return (0);
}

int calresistor()
{
    int menu;
    cout << "Please select resistors color bar [4][5] : ";
    cin >> menu;

    if (menu == 4)
    {
        fourbar();
    }

    else if (menu == 5)
    {
        fivebar();
    }

    return (9);
}

int fourbar()
{
    cout << "Color all : [0.black] [1.brown] [2.red] [3.orange] [4.yellow] [5.green] [6.blue] [7.violet] [8.grey] [9.white]" << endl;
    cout << "Enter color resistor Position 1 : ";
    cin >> Color[0];
    cout << "Color all : [0.black] [1.brown] [2.red] [3.orange] [4.yellow] [5.green] [6.blue] [7.violet] [8.grey] [9.white]" << endl;
    cout << "Enter color resistor Position 2 : ";
    cin >> Color[1];
    cout << "Color all : [0.black] [1.brown] [2.red] [3.orange] [4.yellow] [5.green] [6.blue] [7.violet] [8.grey] [9.white] [10.gold] [11.silver]" << endl;
    cout << "Enter color resistor Position 3 : ";
    cin >> Color[2];
    cout << "Color all : [0.brown] [1.red] [2.yellow] [3.green] [4.blue] [5.violet] [6.grey] [7.gold] [8.silver] [9.nocolor]" << endl;
    cout << "Enter color resistor Position 4 : ";
    cin >> Color[3];
    cout << "Resistors : " << checkR(Color) << " ohms" << endl;
    return (3);
}

string checkR(string Color[])
{

    string result;
    for (size_t i = 0; i < getArrayLength; i++) // วนลูปตามค่าสีที่รับมา (สิ่งที่หมดเป็น 4 สี)
    {
        if (i == 2) // สีที่ 3
        {
            if (Color[i] == "brown" || Color[i] == "1")
            {
                result.append("0");
            }
            else if (Color[i] == "red" || Color[i] == "2")
            {
                result.append("00");
            }
            else if (Color[i] == "orange" || Color[i] == "3")
            {
                result.append("000");
            }
            else if (Color[i] == "yellow" || Color[i] == "4")
            {
                result.append("0000");
            }
            else if (Color[i] == "green" || Color[i] == "5")
            {
                result.append("00000");
            }
            else if (Color[i] == "blue" || Color[i] == "6")
            {
                result.append("000000");
            }
            else if (Color[i] == "violet" || Color[i] == "7")
            {
                result.append("0000000");
            }
            else if (Color[i] == "grey" || Color[i] == "8")
            {
                result.append("00000000");
            }
            else if (Color[i] == "white" || Color[i] == "9")
            {
                result.append("000000000");
            }
            else if (Color[i] == "gold" || Color[i] == "10")
            {
                result.append(" x10^-1");
            }
            else if (Color[i] == "silver" || Color[i] == "11")
            {
                result.append(" x10^-2");
            }
            else if (Color[i] == "black" || Color[i] == "0")
            {
                result.append(" x 1");
            }
            else
            {
                cout << "Error";
            }
        }

        else if (i == 3) // สีที่ 4
        {
            if (Color[i] == "brown" || Color[i] == "0")
            {
                result.append(" +-1%");
            }
            else if (Color[i] == "red" || Color[i] == "1")
            {
                result.append(" +-2%");
            }
            else if (Color[i] == "yellow" || Color[i] == "2")
            {
                result.append(" +-5%");
            }
            else if (Color[i] == "green" || Color[i] == "3")
            {
                result.append(" +-0.5%");
            }
            else if (Color[i] == "blue" || Color[i] == "4")
            {
                result.append(" +-0.25%");
            }
            else if (Color[i] == "violet" || Color[i] == "5")
            {
                result.append(" +-0.1%");
            }
            else if (Color[i] == "grey" || Color[i] == "6")
            {
                result.append(" +-0.05%");
            }
            else if (Color[i] == "gold" || Color[i] == "7")
            {
                result.append(" +-5%");
            }
            else if (Color[i] == "silver" || Color[i] == "8")
            {
                result.append(" +-10%");
            }
            else if (Color[i] == "nocolor" || Color[i] == "9")
            {
                result.append(" +-20%");
            }
            else
            {
                cout << "Error";
            }
        }

        else // สีแรกหรือสีที่สอง
        {
            if (Color[i] == "black" || Color[i] == "0")
            {
                result.append("0");
            }
            else if (Color[i] == "brown" || Color[i] == "1")
            {
                result.append("1");
            }
            else if (Color[i] == "red" || Color[i] == "2")
            {
                result.append("2");
            }
            else if (Color[i] == "orange" || Color[i] == "3")
            {
                result.append("3");
            }
            else if (Color[i] == "yellow" || Color[i] == "4")
            {
                result.append("4");
            }
            else if (Color[i] == "green" || Color[i] == "5")
            {
                result.append("5");
            }
            else if (Color[i] == "blue" || Color[i] == "6")
            {
                result.append("6");
            }
            else if (Color[i] == "violet" || Color[i] == "7")
            {
                result.append("7");
            }
            else if (Color[i] == "grey" || Color[i] == "8")
            {
                result.append("8");
            }
            else if (Color[i] == "white" || Color[i] == "9")
            {
                result.append("9");
            }
            else
            {
                cout << "Error";
            }
        }
    }

    return result;
}

int fivebar()
{
    cout << "Color all : [0.black] [1.brown] [2.red] [3.orange] [4.yellow] [5.green] [6.blue] [7.violet] [8.grey] [9.white]" << endl;
    cout << "Enter color resistor Position 1 : ";
    cin >> Color5[0];
    cout << "Color all : [0.black] [1.brown] [2.red] [3.orange] [4.yellow] [5.green] [6.blue] [7.violet] [8.grey] [9.white]" << endl;
    cout << "Enter color resistor Position 2 : ";
    cin >> Color5[1];
    cout << "Color all : [0.black] [1.brown] [2.red] [3.orange] [4.yellow] [5.green] [6.blue] [7.violet] [8.grey] [9.white]" << endl;
    cout << "Enter color resistor Position 3 : ";
    cin >> Color5[2];
    cout << "Color all : [0.black] [1.brown] [2.red] [3.orange] [4.yellow] [5.green] [6.blue] [7.violet] [8.grey] [9.white] [10.gold] [11.silver]" << endl;
    cout << "Enter color resistor Position 4 : ";
    cin >> Color5[3];
    cout << "Color all : [0.brown] [1.red] [2.yellow] [3.green] [4.blue] [5.violet] [6.grey] [7.gold] [8.silver] [9.nocolor]" << endl;
    cout << "Enter color resistor Position 5 : ";
    cin >> Color5[4];
    cout << "Resistors : " << checkR5(Color5) << " ohms" << endl;
    return (3);
}

string checkR5(string Color5[])
{
    string result;
    for (size_t i = 0; i < getArrayLength5; i++) // วนลูปตามค่าสีที่รับมา (สิ่งที่หมดเป็น 5 สี)
    {
        if (i == 3) // สีที่ 3
        {
            if (Color5[i] == "brown" || Color5[i] == "1")
            {
                result.append("0");
            }
            else if (Color5[i] == "red" || Color5[i] == "2")
            {
                result.append("00");
            }
            else if (Color5[i] == "orange" || Color5[i] == "3")
            {
                result.append("000");
            }
            else if (Color5[i] == "yellow" || Color5[i] == "4")
            {
                result.append("0000");
            }
            else if (Color5[i] == "green" || Color5[i] == "5")
            {
                result.append("00000");
            }
            else if (Color5[i] == "blue" || Color5[i] == "6")
            {
                result.append("000000");
            }
            else if (Color5[i] == "violet" || Color5[i] == "7")
            {
                result.append("0000000");
            }
            else if (Color5[i] == "grey" || Color5[i] == "8")
            {
                result.append("00000000");
            }
            else if (Color5[i] == "white" || Color5[i] == "9")
            {
                result.append("000000000");
            }
            else if (Color5[i] == "gold" || Color5[i] == "10")
            {
                result.append(" x10^-1");
            }
            else if (Color5[i] == "silver" || Color5[i] == "11")
            {
                result.append(" x10^-2");
            }
            else if (Color5[i] == "black" || Color5[i] == "0")
            {
                result.append(" x 1");
            }
            else
            {
                cout << "Error";
            }
        }

        else if (i == 4) // สีที่ 4
        {
            if (Color5[i] == "brown" || Color5[i] == "0")
            {
                result.append(" +-1%");
            }
            else if (Color5[i] == "red" || Color5[i] == "1")
            {
                result.append(" +-2%");
            }
            else if (Color5[i] == "yellow" || Color5[i] == "2")
            {
                result.append(" +-5%");
            }
            else if (Color5[i] == "green" || Color5[i] == "3")
            {
                result.append(" +-0.5%");
            }
            else if (Color5[i] == "blue" || Color5[i] == "4")
            {
                result.append(" +-0.25%");
            }
            else if (Color5[i] == "violet" || Color5[i] == "5")
            {
                result.append(" +-0.1%");
            }
            else if (Color5[i] == "grey" || Color5[i] == "6")
            {
                result.append(" +-0.05%");
            }
            else if (Color5[i] == "gold" || Color5[i] == "7")
            {
                result.append(" +-5%");
            }
            else if (Color5[i] == "silver" || Color5[i] == "8")
            {
                result.append(" +-10%");
            }
            else if (Color5[i] == "nocolor" || Color5[i] == "9")
            {
                result.append(" +-20%");
            }
            else
            {
                cout << "Error";
            }
        }

         else // สีแรก สีสอง และสีสาม
        {
            if (Color5[i] == "black" || Color5[i] == "0")
            {
                result.append("0");
            }
            else if (Color5[i] == "brown" || Color5[i] == "1")
            {
                result.append("1");
            }
            else if (Color5[i] == "red" || Color5[i] == "2")
            {
                result.append("2");
            }
            else if (Color5[i] == "orange" || Color5[i] == "3")
            {
                result.append("3");
            }
            else if (Color5[i] == "yellow" || Color5[i] == "4")
            {
                result.append("4");
            }
            else if (Color5[i] == "green" || Color5[i] == "5")
            {
                result.append("5");
            }
            else if (Color5[i] == "blue" || Color5[i] == "6")
            {
                result.append("6");
            }
            else if (Color5[i] == "violet" || Color5[i] == "7")
            {
                result.append("7");
            }
            else if (Color5[i] == "grey" || Color5[i] == "8")
            {
                result.append("8");
            }
            else if (Color5[i] == "white" || Color5[i] == "9")
            {
                result.append("9");
            }
            else
            {
                cout << "Error";
            }
        }
    }

    return result;
}
