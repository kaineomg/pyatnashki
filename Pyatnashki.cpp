#include <iostream>
#include <stdlib.h> 
#include <stdio.h>
#include <conio.h> 
using namespace std;
int Field[4][4];
int x, y;
char d;
void CreateField();
void ShowField();
void Move(char d);
bool WinTest();
int main()
{
    setlocale(LC_ALL, "ru");
    char b;
    cout << "=======================================================================================================================" << endl;
    cout << "=                                                                                                                     =" << endl;
    cout << "=                                                 Пятнашки ver 1.0                                                    =" << endl;
    cout << "=                                                   Управление                                                        =" << endl;
    cout << "=                                                                                                                     =" << endl;
    cout << "=                                                                                                                     =" << endl;
    cout << "=                                                                                                                     =" << endl;
    cout << "=                                                                                                                     =" << endl;
    cout << "=                                                                                                                     =" << endl;
    cout << "=                                                                                                                     =" << endl;
    cout << "=                                                                                                                     =" << endl;
    cout << "=                                                                                                                     =" << endl;
    cout << "=                                               w - верх                                                              =" << endl;
    cout << "=                                               a - лево                                                              =" << endl;
    cout << "=                                               s - низ                                                               =" << endl;
    cout << "=                                               d - право                                                             =" << endl;
    cout << "=                                                                                                                     =" << endl;
    cout << "=                                                                                                                     =" << endl;
    cout << "=                                                                                                                     =" << endl;
    cout << "=                                                                                                                     =" << endl;
    cout << "=                                      Введите любую клавишу для продолжения                                          =" << endl;
    cout << "=                                                                                                                     =" << endl;
    cout << "=                                                                                                                     =" << endl;
    cout << "=                                                                                                                     =" << endl;
    cout << "=                                                                                                                     =" << endl;
    cout << "=                                                                                                                     =" << endl;
    cout << "=  q - выход из игры (во время игры)                                                                                  =" << endl;
    cout << "=                                                                                                                     =" << endl;
    cout << "=======================================================================================================================" << endl;
    cin >> b;
    CreateField();
    ShowField();
    char c;
    while (!WinTest())
    {
        cin >> c;
        switch (c)
        {
        case 'a': Move(c); break;
        case 'w': Move(c); break;
        case 'd': Move(c); break;
        case 's': Move(c); break;
        case 'q': return 0;
        }
        ShowField();
    }
    cout << " Победа! ";
}
bool WinTest()
{
    for (int i = 0; i < 15; i++)
        if (Field[i % 4][i / 4] != i + 1)
            return false;
    return true;
}
void Move(char d)
{
    switch (d)
    {
    case 'd':
    {
        if (x < 3)
        {
            Field[x][y] = Field[x + 1][y];
            Field[x + 1][y] = 0;
            x++;
        }
    }
    break;
    case 's':
    {
        if (y < 3)
        {
            Field[x][y] = Field[x][y + 1];
            Field[x][y + 1] = 0;
            y++;
        }
    } break;
    case 'a':
    {
        if (x > 0)
        {
            Field[x][y] = Field[x - 1][y];
            Field[x - 1][y] = 0;
            x--;
        }
    } break;
    case 'w':
    {
        if (y > 0)
        {
            Field[x][y] = Field[x][y - 1];
            Field[x][y - 1] = 0;
            y--;
        }
    }
    break;
    }
}
void ShowField()
{
    system("cls");
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            if (Field[i][j])
                cout << "    ";
            else
                cout << "    ";
        }
        cout << '\n';
        for (int i = 0; i < 4; i++)
        {
            if (Field[i][j])
            {
                cout << " ";
                cout.width(2);
                cout << Field[i][j] << " ";
            }
            else
                cout << "    ";
        }
        cout << '\n';
        for (int i = 0; i < 4; i++)
        {
            if (Field[i][j])
                cout << "    ";
            else
                cout << "    ";
        }
        cout << '\n';
    }
}
void CreateField()
{
    bool NumIsFree[15];
    int numbers[15];
    for (int i = 0; i < 15; i++)
        NumIsFree[i] = true;
    srand(time(0));
    bool Ok;
    int RandNum;
    for (int i = 0; i < 15; i++)
    {
        Ok = false;
        while (!Ok)
        {
            RandNum = rand() % 15 + 1;
            if (NumIsFree[RandNum - 1])
                Ok = true;
        }
        numbers[i] = RandNum;
        NumIsFree[RandNum - 1] = false;
    }


    for (int i = 0; i < 15; i++)
    {
        Field[i % 4][i / 4] = numbers[i];
        Field[3][3] = 0;
        x = 3; y = 3;
    }
}