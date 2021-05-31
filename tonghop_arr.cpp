// tonghop_arr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<math.h>
#include <cstdlib> 
#include <ctime> 
using namespace std;

void enterArr(int arr[], const int &numberOfElements)
{
	for (int i = 0; i < numberOfElements; i++)
	{
		cout << "arr[" << i << "]: ";
		cin >> arr[i];
	}
}

void display(int arr[], const int &numberOfElements)
{
	for (int i = 0; i < numberOfElements; i++)
	{
		cout << arr[i] << " ";
	}
}

//tim kiem
int findMaxEven(int arr[], const int &numberOfElements)
{
	int max = arr[0];
	int pos = 0;
	for (int i = 0; i < numberOfElements; i++)
	{
		if (arr[i] % 2 == 0)// chan
		{
			if (arr[i] > max)
			{
				max = arr[i];
				pos = i;
			}
		}
	}
	cout << "Even max element = " << max;
	return pos;
}

int findMaxOdd(int arr[], const int &numberOfElement)
{
	int max = arr[0];
	int pos = 0;
	for (int i = 0; i < numberOfElement; i++)
	{
		if (arr[i] % 2 != 0)// le
		{
			if (arr[i] > max)
			{
				max = arr[i];
				pos = i;
			}
		}
	}
	cout << "Odd max element = " << max;
	return pos;
}

//sap xep

void swap(int arr[],int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
void ascending(int arr[],const int &numberOfElements)// sap xep tang dan
{
	for (int i = 0; i < numberOfElements - 1; i++)
	{
		for (int j = i + 1; j < numberOfElements; j++)
		{
			if (arr[i] > arr[j])// so trc lon hon so sau => doi cho
			{
				swap(arr, i, j);
			}
		}
	}
}

void descending(int arr[], const int &numberOfElements)// sap xep tang dan
{
	for (int i = 0; i < numberOfElements - 1; i++)
	{
		for (int j = i + 1; j < numberOfElements; j++)
		{
			if (arr[i] < arr[j])// so trc nho hon so sau => doi cho
			{
				swap(arr, i, j);
			}
		}
	}
}

// Tim so chinh phuong (bai 2)
bool isSquareNumber(const int &number)
{
	int n = int(sqrt(number));
	if (pow(n, 2) == number)
	{
		return true;
	}
	return false;
}

//Tim so nguyen to (bai 3)
bool isPrimeNumber(const int &number)
{
	if (number < 2)
	{
		return false;
	}
	for (int i = 2; i < (number / 2); i++)
	{
		if (number%i == 0)
		{
			return false;
		}
		return true;
	}
}

//find pos of max, min numbers (bai4)

int getMaxNumber(int arr[], const int &numberOfElements)
{
	int max = arr[0];
	
	for (int i = 0; i < numberOfElements; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	return max;
}

void findMaxNumbers(int arr[], const int &numberOfElements)
{
	cout << " at pos: ";
	for (int i = 0; i < numberOfElements; i++)
	{
		if (arr[i] == getMaxNumber(arr,numberOfElements))
		{
			cout<<i<<" ";
		}
	}
}

int getMinNumber(int arr[], const int &numberOfElements)
{
	int min = arr[0];

	for (int i = 0; i < numberOfElements; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
		}
	}
	return min;
}

void findMinNumbers(int arr[], const int &numberOfElements)
{
	cout << " at pos: ";
	for (int i = 0; i < numberOfElements; i++)
	{
		if (arr[i] == getMinNumber(arr, numberOfElements))
		{
			cout << i << " ";
		}
	}
}

//Insert(bai5)

void insert(int arr[],int &numberOfElements, const int &pos, const int &value)
{
	
	
	for (int i = numberOfElements ; i >= pos; i--)
	{
		arr[i+1] = arr[i];// dich lui
	}
	numberOfElements++;
	arr[pos] = value;
}


int main()
{
	int numberOfElements = 0;
	int originalArray[100];
	int evenArray[20];// mang chua phan tu chan
	int oddArray[20];// mang chua phan tu le
	int countEven = 0, countOdd = 0;

	cout << "Enter number of elements: ";
	cin >> numberOfElements;

	enterArr(originalArray, numberOfElements);
	cout << "Original array: ";
	display(originalArray, numberOfElements);

	for (int i = 0; i < numberOfElements; i++)// tach mang
	{
		if (originalArray[i] % 2 == 0)
		{
			evenArray[countEven] = originalArray[i];
			countEven++;
		}
		else
		{
			oddArray[countOdd] = originalArray[i];
			countOdd++;
		}
	}

	cout << "\n\nAfter classifying: ";
	cout << "\nEven array: ";
	display(evenArray, countEven);
	cout << "\nOdd array: ";
	display(oddArray, countOdd);

	//find max, min
	cout << "\n\n";
	cout << " at position: " << findMaxEven(originalArray, numberOfElements);
	cout << endl;
	cout << " at position: " << findMaxOdd(originalArray, numberOfElements);



	//ascending
	ascending(evenArray, countEven);
	ascending(oddArray, countOdd);
	cout << "\n\nAfter sort in ascending order: ";
	cout << "\nEven array: ";
	display(evenArray, countEven);
	cout << "\nOdd array: ";
	display(oddArray, countOdd);

	//descending
	descending(evenArray, countEven);
	descending(oddArray, countOdd);
	cout << "\n\nAfter sort in descending order: ";
	cout << "\nEven array: ";
	display(evenArray, countEven);
	cout << "\nOdd array: ";
	display(oddArray, countOdd);

	//find square numbers
	cout << "\n\nList of square numbers: ";
	for (int i = 0; i < numberOfElements; i++)
	{
		if (isSquareNumber(originalArray[i]))
		{
			cout << originalArray[i] << " ";
		}
	}

	//find prime numbers
	int countPrime = 0;
	cout << "\n\nList of prime numbers: ";
	for (int i = 0; i < numberOfElements; i++)
	{
		if (isPrimeNumber(originalArray[i]))
		{
			cout << originalArray[i] << " ";
			countPrime++;
		}
	}
	cout << "=> " << countPrime << " prime numbers";

	//max positions
	cout << "\n\n";
	cout << "Max value = " << getMaxNumber(originalArray, numberOfElements);
	findMaxNumbers(originalArray, numberOfElements);

	//min positions

	cout << "\n";
	cout << "Mix value = " << getMinNumber(originalArray, numberOfElements);
	findMinNumbers(originalArray, numberOfElements);

	//create a randome arraya[30]
	int newArray[30];

	srand(time(NULL));

	newArray[0] = rand() % 3;

	for (int i = 1; i < 30; i++)
	{
		newArray[i] = newArray[i - 1] + rand() % 3;// tang dan
	}

	cout << "\n\nNew array: ";
	display(newArray, 30);

	//insert
	int x = 0;
	cout<<"\nEnter x: ";
	cin >> x;
	cout << "After insert "<<x<<" at middle: ";
	int number = 30;
	insert(newArray, number, 15, x);
	display(newArray, number);

}



	



