#pragma once

enum class GenerateType
{
	Random,
	Backward,
	Upright
};

int* GetArray(int size, GenerateType GType);

void PrintArr(int* Arr, int size);


void BubbleSort(int* Arr, int size, long long int& CompCount, long long int& SwapCount);

int GetGap(int gap);

void CombSort(int* arr, int size, long long int& CompCount, long long int& SwapCount);
