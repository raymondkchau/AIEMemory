#include <iostream>

void printFloats(float * arr, int size)
{
	std::cout << std::endl;
	std::cout << "Open 1:" << std::endl;

	for (int i = 0; i < size; i++)
	{
		std::cout << *(arr + i) << std::endl;
	}
}

void arraySum(int * arr, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += *(arr + i);
	}

	std::cout << std::endl;
	std::cout << "Closed 2:" << std::endl;
	std::cout << sum << std::endl;
}

void arrayAvg(float * arr, int size)
{
	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum += *(arr + i);
	}

	std::cout << std::endl;
	std::cout << "Closed 3:" << std::endl;
	std::cout << sum / size << std::endl;
}

int findCount(int target, int * arr, int size)
{
	int valFreq = 0;

	for (int i = 0; i < size; i++)
	{
		if (*(arr + i) == target)
		{
			valFreq++;
		}
	}

	return valFreq;
}

void arrCopy(int * srcArr, int srcSize, int * dstArr, int dstSize)
{
	for (int i = 0; i < dstSize; i++)
	{
		*(dstArr + i) = *(srcArr + i);

		std::cout << *(dstArr + i) << ", ";
	}

	std::cout << std::endl;
}

void arrReversal(int * arr, int size)
{
	int * arrTrn = new int[size];

	for (int i = 0; i < size; i++)
	{
		*(arrTrn + i) = *(arr + (size - i - 1));
	}

	std::cout << "Base array:     ";
	for (int i = 0; i < size; i++)
	{
		std::cout << *(arr + i) << ", ";
	}
	std::cout << std::endl;
	std::cout << "Reversed array: ";
	for (int i = 0; i < size; i++)
	{
		std::cout << *(arrTrn + i) << ", ";
	}
	
	std::cout << std::endl;
}

void cstrReversal(char * arr, int size)
{
	char * arrTrn = new char[size];

	for (int i = 0; i < size; i++)
	{
		*(arrTrn + i) = *(arr + (size - i - 1));
	}

	std::cout << "Base string:      ";
	for (int i = 0; i < size; i++)
	{
		std::cout << *(arr + i);
	}
	std::cout << std::endl;
	std::cout << "Reversed string: ";
	for (int i = 0; i < size; i++)
	{
		std::cout << *(arrTrn + i);
	}

	std::cout << std::endl;
}

void main()
{
	//Pointer Artihmetic
	int a = 1;
	int b = 2;

	int * notA = &a;

	std::cout << a << std::endl;
	std::cout << *(notA + 1) << std::endl;

	//Pointer Artihmetic 2: Electric Boogaloo (arrays)
	int * hArr = new int[2];
	hArr[0] = 1;
	hArr[1] = 2;

	std::cout << hArr[0] << std::endl;
	std::cout << hArr[1] << std::endl;

	std::cout << hArr[0] << std::endl;
	std::cout << *(hArr + 1) << std::endl;

	int * arrLarge = new int[100];
	int arrLargeStack[100];

	//iteration with subscript operator
	for (int i = 0; i < 100; i++)
	{
		arrLarge[i] = i;
		arrLargeStack[i] = i;
	}

	//iteration with pointer arithmetic
	for (int i = 0; i < 100; i++)
	{
		std::cout << *(arrLarge + i) << std::endl;
		std::cout << *(arrLargeStack + i) << std::endl;
	}

	delete[] hArr;

	// Type Casting
	float dollars = 1.80f;

	std::cout << dollars << std::endl;

	//uses the float as an int
	std::cout << (int)dollars << std::endl;

	//Closed Activities
	float * input1 = new float[100];

	for (int i = 0; i < 100; i++)
	{
		*(input1 + i) = i;
	}

	int * input2 = new int[100];

	for (int i = 0; i < 100; i++)
	{
		*(input2 + i) = i + 1;
	}

	float * input3 = new float[100];

	for (int i = 0; i < 100; i++)
	{
		*(input3 + i) = i + 1;
	}

	printFloats(input1, 100);
	arraySum(input2, 100);
	arrayAvg(input3, 100);

	delete[] input1;
	delete[] input2;
	delete[] input3;

	//Open Activities
	int freq;
	int * numArr1 = new int[8];
	int * numArr2 = new int[8];
	int * numArr3 = new int[8];
	int value[8] = { 0, 4, 2, 1, 4, 3, 2, 4 };

	for (int i = 0; i < 8; i++)
	{
		*(numArr1 + i) = i;
		*(numArr2 + i) = i;
		*(numArr3 + i) = value[i];
	}

	std::cout << std::endl;
	std::cout << "Open 1:" << std::endl;
	freq = findCount(2, numArr1, 8);
	std::cout << freq << std::endl;
	freq = findCount(8, numArr2, 8);
	std::cout << freq << std::endl;
	freq = findCount(4, numArr3, 8);
	std::cout << freq << std::endl;

	int * dstArr = new int[8];
	int * srcArr1 = new int[8]{ 0, 1, 2, 3, 4, 5, 6, 7 };
	int * srcArr2 = new int[8]{ 0, 4, 2, 1, 4, 3, 2, 1 };
	int * srcArr3 = new int[8]{ 0, 1, 2, 3 };

	std::cout << std::endl;
	std::cout << "Open 2:" << std::endl;
	arrCopy(srcArr1, 8, dstArr, 8);
	arrCopy(srcArr2, 8, dstArr, 8);
	arrCopy(srcArr3, 8, dstArr, 8);

	int * arrFwd1 = new int[8]{ 0, 1, 2, 3, 4, 5, 6, 7 };
	int * arrFwd2 = new int[8]{ 0, 1, 2, 3, 4, 5, 6, 7 };
	int * arrFwd3 = new int[8]{ 0, 4, 2, 1, 4, 3, 2, 1 };

	std::cout << std::endl;
	std::cout << "Open 3:" << std::endl;
	arrReversal(arrFwd1, 8);
	std::cout << std::endl;
	arrReversal(arrFwd2, 8);
	std::cout << std::endl;
	arrReversal(arrFwd3, 8);
	std::cout << std::endl;

	char * arrStr1 = new char[13]{ "Terry Nguyen" };
	char * arrStr2 = new char[18]{ "Hotdogs are cool." };
	char * arrStr3 = new char[9]{ "WoWoWoWo" };

	std::cout << "Open 4:" << std::endl;
	cstrReversal(arrStr1, 13);
	std::cout << std::endl;
	cstrReversal(arrStr2, 18);
	std::cout << std::endl;
	cstrReversal(arrStr3, 9);
	std::cout << std::endl;

	while (true); //Keeps open
}