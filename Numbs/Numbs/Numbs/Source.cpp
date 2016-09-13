#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
const int n = 1000000;		
void main()
{
	cout << "Quantity of all simple numbs of 1000000 is calculating...\n"  << "Wait please... " << endl;
	bool lol = false;		//if the current numbs simple
	int sum = 1;			//sum all simple numbs of n
	for (int i = 3; i <= n; i++)
	{
		lol = false;			//start condition - current numb is simple
		for (int j = 3; j <= sqrt(i); j+=2)
		{
			if (i%j == 0)
			{
				lol = true;		//if current numb isn't simple, break cycle
				break;
			}
		
			
		}
		
		if (!lol && i%2!=0)
			sum++;				//increase quantity of simple numbs
	}
	cout << "All simple numbs:  " << sum;		//result
	getchar();

}