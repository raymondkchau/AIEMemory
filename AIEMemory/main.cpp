#include <iostream>

int sumTwoIntPtrs(int * a, int * b)
{
	return *a + *b;
}

void closed1()
{
	/*
	int * thingy1 = new int(1);
	float * thingy2 = new float(5.5f);
	bool * thingy3 = new bool(true);
	*/

	/*
	int * thingy4[];
	float * thingy5[];
	bool * thingy6[]
	*/
}

void arrPop(int * arr, int size)
{
	for (int i = 0; i < 100; i++)
	{
		arr[i] = (i + 1) * 3;
	}
}

void arrPrint(int * arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << std::endl;
	}
}



void main()
{
	/*
	//instantiate two pointers to heap-allocated integers
	int * numAPtr = new int(10);
	int * numBPtr = new int(15);

	std::cout << "numA: " << *numAPtr << std::endl;
	std::cout << "numB: " << *numBPtr << std::endl;

	//provide them as arguements
	int res = sumTwoIntPtrs(numAPtr, numBPtr);

	std::cout << "sum: " << res << std::endl;

	system("pause");

	delete numAPtr;
	delete numBPtr;
	*/

	//closed1();

	// == OPEN ==
	//creates an array of 100 elements
	int * nummmz = new int[100];
	arrPop(nummmz, 100);
	arrPrint(nummmz, 100);

	for (int i = 0; i < 100; i++)
	{
		std::cout << nummmz[i] << std::endl;
	}

	int * singleNum = new int;
	arrPop(singleNum, 1);

	std::cout << *singleNum << std::endl;


	//heap-alloc arr of nums
	std::cout << "Howdy! How many?" << std::endl;
	int qty;
	std::cin >> qty;
	int * inputs = new int[qty];

	for (int i = 0; i < qty; i++)
	{
		std::cout << "What's number " << i + 1 << "?" << std::endl;
		int input;
		std::cin >> input;

		inputs[i] = input;
	}

	int even = 0;

	//determine odds and evens
	for (int i = 0; i < qty; i++)
	{
		if (inputs[i] % 2 == 0)
		{
			even++;
		}
	}

	int odd = qty + 1 - even;

	if (even > odd)
	{
		std::cout << "Even Lover" << std::endl;
	}
	else if (odd > even)
	{
		std::cout << "Odd Lover" << std::endl;
	}
	else
	{
		std::cout << "Equal Lover" << std::endl;
	}
	delete[] inputs;

	//adding to 21
	std::cout << "How many?" << std::endl;
	int count = 0;

	std::cin >> count;

	int * numbers = new int[count];

	for (int i = 0; i < count; i++)
	{
		std::cout << "Okay, whats num " << i + 1 << "?" << std::endl;

		int userInput = 0;
		std::cin >> userInput;
		numbers[i] = userInput;
	}
	int total = 0;
	for (int i = 0; i < count; i++)
	{
		total += numbers[i];
	}

	if (total == 21)
	{
		std::cout << "You can add!" << std::endl;
	}
	else
	{
		std::cout << "Guess you can't add." << std::endl;
	}

	delete[] nummmz;
	delete singleNum;

	char end;
	std::cin >> end;
}