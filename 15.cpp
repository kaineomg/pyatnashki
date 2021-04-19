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
		
		
		



