#include "Algs.h"
#include <iostream>

using std::cout;
using std::cin;

constexpr unsigned int ignore_limit = ~(unsigned int(0));

int main()
{
	long long int Comp, Swap;
	GenerateType GType = GenerateType::Random;
	int size = 1;
	bool alg = true;

	int *arr = new int[size];
	
	char key;
	bool SWITCH = true;

	while (SWITCH)
	{
		std::cout << "\n 1 - Change algorithm\n 2 - Change size of the array\n 3 - Change Generation type\n 4 - Start\n 5 - Exit\n";
		std::cout << "Active Cfg: s_" << size << " alg_" << alg << " gt_" << (int)GType << '\n';
		key = std::cin.get();
		std::cin.ignore(ignore_limit,'\n');

		switch (key)
		{
		case '1':
			cout << " 0 - Bubble Sort\n Anything other - Comb Sort\n";
			cin >> alg;
			cin.clear(); cin.ignore(ignore_limit, '\n');
			break;
		case '2':
			do
			{
				cout << "Enter size: ";
				cin >> size;
				cin.clear(); cin.ignore(ignore_limit, '\n');
			} while (size < 0);
			break;
		case '3':
			cout << "Choose generation:\n B - backward\n U - upright \n r - random\n";
				switch (cin.get())
				{
				case 'r': case 'R': GType = GenerateType::Random; break;
				case 'b': case 'B': GType = GenerateType::Backward; break;
				case 'u': case 'U': GType = GenerateType::Upright; break;
				default:
					cout << "Something went wrog. Setted to Random\n"; GType = GenerateType::Random;
					break;
				}
				cin.ignore(ignore_limit, '\n');
			break;
		case '4': 
			Comp = 0; Swap = 0;
			delete[] arr;
			arr = GetArray(size, GType);
			alg ? CombSort(arr, size, Comp, Swap) : BubbleSort(arr, size, Comp, Swap);
			cout << "\n\nSize: " << size << " Comparations: " << Comp << " Swaps: " << Swap << "\n\n";
			break;
		case '5':
			SWITCH = false; break;
			
		default:
			break;
		}
	}
	delete[] arr;
	return 0;
}