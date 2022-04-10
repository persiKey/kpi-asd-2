#include "Algs.h"
#include <iostream>
#include <iomanip>
#include <random>
#include <time.h>


using std::cout;
using std::cin;
using std::setw;


int* GetArray(int size, GenerateType GType )
{
	int* Arr = new int[size];
	switch (GType)
	{
	case GenerateType::Random:
		srand(time(NULL));
		for (int i = 0; i < size; i++)
		{
			Arr[i] = rand();
		}
		break;
	case GenerateType::Backward:
		for (int i = 0; i < size; i++)
		{
			Arr[i] = size-i;
		}
		break;
	case GenerateType::Upright:
		for (int i = 0; i < size; i++)
		{
			Arr[i] = i;
		}
		break;
	default:
		break;
	}
	return Arr;
}

void PrintArr(int *Arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << setw(6) << Arr[i];
	}
	cout << '\n';
}



void BubbleSort(int* Arr, int size, long long int &CompCount,long long int &SwapCount)
{
	int temp;
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size-1; j++)
		{
			if (Arr[j] > Arr[j + 1])
			{
				temp = Arr[j];
				Arr[j] = Arr[j + 1];
				Arr[j + 1] = temp;
				++SwapCount;
			}
			++CompCount;
		}
	}
}

int GetGap(int gap)
{
	gap /= 1.3;
	if (gap < 1)
	{
	gap = 1;
	}
	return gap;
}

void CombSort(int* arr, int size, long long int& CompCount, long long int& SwapCount)
{
	int temp, gap = size;
	bool swapped = true;
	while (gap > 1 || swapped)
	{
		swapped = false;
		gap = GetGap(gap);
		for (int i = 0; i < size - gap; ++i)
		{
			if (arr[i] > arr[i + gap])
			{
				temp = arr[i];
				arr[i] = arr[i + gap];
				arr[i + gap] = temp;
				swapped = true;
				++SwapCount;
			}
			++CompCount;
		}
	}
}
