#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int MaxSize = 100; 		// max size of triangle
int Element_mas[MaxSize][MaxSize] = { 0 };		//value of element triangle
int quan_length = 0;	//current length of triangle
FILE *f;		//file which read date about triangle

// FUNCTION READ DATE ABOUT TRIANGLE 
void ReadData()
{
	int i = 0, j = 0;

	fopen_s(&f, "triangl.txt", "r");		// open file


		while (!feof(f))	//while don't reach the base of the triangle
		{

			fscanf_s(f, "%d", &Element_mas[i][j]);	//read value of current element and add to massive
			if (j == quan_length)			//move to next string
			{
				i++;			//increase numb of current string
				j = 0;			//set to zero current column 
				quan_length++;		//determinate height of triangle
			}
			else
			j++;
		}
	fclose(f);		//close file



}
// FUNCITON FIND MAX PATH
void FindPath()
{

	for (int i = quan_length-1; i >=0; i--)		//iratate all variants from base of triangle
	{
		for (int j = 0; j <= i; j++)			
		{
			if (Element_mas[i][j] != NULL && Element_mas[i][j + 1] != NULL) //choose two adjacent elements for compare
			{
				if (Element_mas[i][j] > Element_mas[i][j + 1])
				{
					Element_mas[i - 1][j] += Element_mas[i][j];		//if left elements more than right, increase top elements on current (left ) element 
				}
				else Element_mas[i - 1][j] += Element_mas[i][j + 1];	//else increase top elements on current element (right)
			}
			else break;

		}
	}

	



}
// FUNCTION START CONDITION
void OutPutDate(){
	for (int i = 0; i+1 < quan_length; i++)		//condition date
	{
		for (int j = 0; j < quan_length; j++)
		{
			if (Element_mas[i][j] != NULL)
				cout <<setw(5)<< Element_mas[i][j] << setw(5);
			else break;

		}

		cout << endl;
	}
}
void main()
{
	ReadData();		//read date about triangle
	OutPutDate();	//output begin condition
	FindPath();		//find max path
	cout << "Sum: " << Element_mas[0][0] << endl; // utput result
	getchar();
		
}

