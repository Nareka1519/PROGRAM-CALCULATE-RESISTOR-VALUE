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
string checkR(string Color[]);                       // ประกาศฟังก์ชั่น
string checkR5(string Color5[]);

string Color[4];                                     // เก็บสีรับจากแป้น
int getArrayLength = sizeof(Color) / sizeof(string); // เก็บค่าสีตัวต้านทานที่ป้อน


string Color5[5];
int getArrayLength5 = sizeof(Color5) / sizeof(string); // เก็บค่าสีตัวต้านทานที่ป้อน

int main()
{
    int menu;
    cout << "\n=========================================" << endl;
    cout << "THIS IS PROGRAM CALCULATE RESISTOR VALUE" << endl;
    cout << "1.Resistors in Series\n";
    cout << "2.Resistors in Parallel\n";
    cout << "3.Star to Delta Conversion\n";
    cout << "4.Delta to Star Conversion\n";
    cout << "5.Calculate the value of the resistor\n";
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
    cout << "Enter AB resistors : ";
    cin >> RAB;
    cout << "Enter AC resistors : ";
    cin >> RAC;
    cout << "Enter BC resistors : ";
    cin >> RBC;
    RA = RAB * RAC / RAB + RAC + RBC;
    RB = RAB * RBC / RAB + RAC + RBC;
    RC = RAC * RBC / RAB + RAC + RBC;
    cout << "Resistors A : " << RA << " ohms" << endl;
    cout << "Resistors B : " << RB << " ohms" << endl;
    cout << "Resistors C : " << RC << " ohms" << endl;
    return (0);
}

int deltatostarconversion()
{
    float RAB, RBC, RAC, RA, RB, RC;
    cout << "Please enter the resistors in only ohms" << endl;
    cout << "Enter Resistors A : ";
    cin >> RA;
    cout << "Enter Resistors B : ";
    cin >> RB;
    cout << "Enter Resistors C : ";
    cin >> RC;
    RAB = RA * RB + RA * RC + RB * RC / RC;
    RBC = RA * RB + RA * RC + RB * RC / RA;
    RAC = RA * RB + RA * RC + RB * RC / RB;
    cout << "Resistors AB : " << RAB << " ohms" << endl;
    cout << "Resistors BC : " << RBC << " ohms" << endl;
    cout << "Resistors AC : " << RAC << " ohms" << endl;
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
    cout << "Color all : [0.black] [1.brown] [2.red] [3.orange] [4.yellow] [5.green] [6.blue] [7.violet] [8.grey] [9.white] [10.gold] [11.silver] [12.nocolor]" << endl;
    cout << "Enter color resistor [Ex. color1 color2 color3 color4] : ";
    cin >> Color[0] >> Color[1] >> Color[2] >> Color[3];
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
            else if (Color[i] == "nocolor" || Color[i] == "12")
            {
                result.append("");
            }
            else if (Color[i] == "black" || Color[i] == "0")
            {
                result.append("");
            }
            else
            {
                cout << "Error";
            }

        }

        else if (i == 3) // สีที่ 4
        {
            if (Color[i] == "brown" || Color[i] == "1")
            {
                result.append(" +-1%");
            }
            else if (Color[i] == "red" || Color[i] == "2")
            {
                result.append(" +-2%");
            }
            else if (Color[i] == "orange" || Color[i] == "3")
            {
                result.append("");
            }
            else if (Color[i] == "yellow" || Color[i] == "4")
            {
                result.append(" +-5%");
            }
            else if (Color[i] == "green" || Color[i] == "5")
            {
                result.append(" +-0.5%");
            }
            else if (Color[i] == "blue" || Color[i] == "6")
            {
                result.append(" +-0.25%");
            }
            else if (Color[i] == "violet" || Color[i] == "7")
            {
                result.append(" +-0.1%");
            }
            else if (Color[i] == "grey" || Color[i] == "8")
            {
                result.append(" +-0.05%");
            }
            else if (Color[i] == "white" || Color[i] == "9")
            {
                result.append("");
            }
            else if (Color[i] == "gold" || Color[i] == "10")
            {
                result.append(" +-5%");
            }
            else if (Color[i] == "silver" || Color[i] == "11")
            {
                result.append(" +-10%");
            }
            else if (Color[i] == "nocolor" || Color[i] == "12")
            {
                result.append(" +-20%");
            }
            else if (Color[i] == "black" || Color[i] == "0")
            {
                result.append("");
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
    cout << "Color all : [0.black] [1.brown] [2.red] [3.orange] [4.yellow] [5.green] [6.blue] [7.violet] [8.grey] [9.white] [10.gold] [11.silver] [12.nocolor]" << endl;
    cout << "Enter color resistor [Ex. color1 color2 color3 color4 color5] : ";
    cin >> Color[0] >> Color[1] >> Color[2] >> Color[3] >> Color[4];
    cout << "Resister : " << checkR5(Color5) << " ohms" << endl;
    return (6);
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
            else if (Color5[i] == "grey"  || Color5[i] == "8")
            {
                result.append("00000000");
            }
            else if (Color5[i] == "white" || Color5[i] == "9")
            {
                result.append("000000000");
            }
            else if (Color5[i] == "gold"  || Color5[i] == "10")
            {
                result.append(" x10^-1");
            }
            else if (Color5[i] == "silver" || Color5[i] == "11")
            {
                result.append(" x10^-2");
            }
            else if (Color5[i] == "nocolor" || Color5[i] == "12")
            {
                result.append("");
            }
            else if (Color5[i] == "black" || Color5[i] == "0")
            {
                result.append("");
            }
            else
            {
                cout << "Error";
            }
        }

        else if (i == 4) // สีที่ 4
        {
            if (Color5[i] == "brown" || Color5[i] == "1")
            {
                result.append(" +-1%");
            }
            else if (Color5[i] == "red" || Color5[i] == "2")
            {
                result.append(" +-2%");
            }
            else if (Color5[i] == "orange" || Color5[i] == "3")
            {
                result.append("");
            }
            else if (Color5[i] == "yellow" || Color5[i] == "4")
            {
                result.append(" +-5%");
            }
            else if (Color5[i] == "green" || Color5[i] == "5")
            {
                result.append(" +-0.5%");
            }
            else if (Color5[i] == "blue" || Color5[i] == "6")
            {
                result.append(" +-0.25%");
            }
            else if (Color5[i] == "violet" || Color5[i] == "7")
            {
                result.append(" +-0.1%");
            }
            else if (Color5[i] == "grey"  || Color5[i] == "8")
            {
                result.append(" +-0.05%");
            }
            else if (Color5[i] == "white" || Color5[i] == "9")
            {
                result.append("");
            }
            else if (Color5[i] == "gold"  || Color5[i] == "10")
            {
                result.append(" +-5%");
            }
            else if (Color5[i] == "silver" || Color5[i] == "11")
            {
                result.append(" +-10%");
            }
            else if (Color5[i] == "nocolor" || Color5[i] == "12")
            {
                result.append(" +-20%");
            }
            else if (Color5[i] == "black" || Color5[i] == "0")
            {
                result.append("");
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