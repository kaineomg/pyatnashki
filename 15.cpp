#include <iostream>
#include <time.h>
#include<stdlib.h>
using namespace std;



void mix(int numbers[], int size);

void vivod(int numbers[], int size);

int main()
{
	int const size = 16;
	int numbers[size] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0 };
	vivod(numbers, size);
	mix(numbers, size);
	vivod(numbers, size);
	

}


	
void mix(int numbers[], int size)
		{
			int temp;
			srand(time(0));
			for (int i = 0; i < size; i++)
			{
				int random = rand() % size;
				temp = numbers[i];
				numbers[i] = numbers[random];
				numbers[random] = temp;

			}

			cout << endl << endl << endl << endl;
		}
void vivod (int numbers[], int size)

		{

			for (int i = 0;i < size;i++)
			{
				cout << numbers[i] << "\t";
				if (i == 3 || i == 7 || i == 11)
				{
					cout << "\n\n\n";

				}
			}
			cout << endl << endl << endl << endl;
		}

void example(int number[])
{
	for (int i = 0; i < 16; i++)
	{
		if (i != 15)
			number[i] = i + 1;
		else
			number[i] = 0;
	}
}

void move(int numbers[])
{
	int key, temp = 0;
	

	while (true)
	{
		vivod(numbers, 16);
		symbols();
		temp = findZero(numbers);

		key = getch();
		if (key == 224)
			key = getch();

		if (key == 72 && temp < 12) // Up
		{
			numbers[temp] = numbers[temp + 4];
			numbers[temp + 4] = 0;
		}
		else if (key == 80 && temp > 3) // Down
		{
			numbers[temp] = numbers[temp - 4];
			numbers[temp - 4] = 0;
		}
		else if (key == 75 && temp != 3 && temp != 7 && temp != 11 && temp != 15) // Left
		{
			numbers[temp] = numbers[temp + 1];
			numbers[temp + 1] = 0;
		}
		else if (key == 77 && temp % 4 != 0) // Right
		{
			numbers[temp] = numbers[temp - 1];
			numbers[temp - 1] = 0;
		}
		else if (key == 96 && cheat == true) // ` 
		{
			
		}
		else if (key == 23) // ctrl + W
		{
			example(numbers);
			vivod(numbers, 16);
			symbols();
		}
		else if (key == 27) // esc
		{
			break;
		}

		if (cheker(arr, 16))
		{
			show(arr, 16);
			symbols();
			break;
		}
	}
}
		
		
		



