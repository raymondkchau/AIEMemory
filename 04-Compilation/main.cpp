#include <iostream>
#include "incdec.h"
#include "globals.h"
#include <string>
#include <random>
#include <time.h>

void gameRelease()
{
	static int releasedGame = 0;

	releasedGame++;

	if (releasedGame > 2)
	{
		releasedGame = 1;
	}

	std::cout << "The game, Pot-Hole " << releasedGame << ", was released!" << std::endl;
}

void stepFizzBuzz()
{
	static int num = 1;

	if (num % 3 == 0)
	{
		std::cout << "Fizz";
	}
	if (num % 5 == 0)
	{
		std::cout << "Buzz";
	}
	if ((num % 3 != 0) && (num % 5 != 0))
	{
		std::cout << num;
	}

	std::cout << std::endl;
	num++;
}

void divide(float lhs, float rhs)
{
	if (lhs == 0 || rhs == 0)
	{
		std::cout << "FATAL ERROR, DIVIDE BY ZERO!" << std::endl;
	}
	else
	{
		std::cout << "OK" << std::endl;
		std::cout << lhs << " / " << rhs << " = " << lhs / rhs << std::endl;
	}
}

void callMeMaybe()
{
	std::string message[4]{ "Howdy World!", "Hello World!", "The sky is a lie.", "Everything you've ever wanted is a lie." };
	srand(time(NULL));

	std::cout << message[rand() % 4] << std::endl;
}

void picker(int& optA, int& optB, int& optC)
{
	static int pickNum = 0;
	
	if (pickNum > 2 || pickNum < 0)
	{
		pickNum = 0;
	}

	if (pickNum == 0)
	{
		std::cout << optA << std::endl;
	}
	else if (pickNum == 1)
	{
		std::cout << optB << std::endl;
	}
	else if (pickNum == 2)
	{
		std::cout << optC << std::endl;
	}

	pickNum++;
}

void arrayCopy(int * srcArr, size_t srcSize, int * dstArr, size_t dstSize)
{
	if (srcSize != dstSize)
	{
		std::cout << "ERROR: Not the same size." << std::endl;
	}
}

void gridGen(int width, int height)
{
	if (width <= 0 || height <= 0)
	{
		std::cout << "ERROR: Height or width is 0 or a negative number." << std::endl;
	}
}

void toUpper(char * cstr)
{
	int i = 0;
	while (true)
	{
		if (isalnum(cstr[i]))
		{
			std::cout << "Alphanumeric Character detected." << std::endl;
			//other code to change the array to upper and break if end
		}
		else if (!isalnum(cstr[i]))
		{
			std::cout << "ERROR: Non-Alphanumeric character detected." << std::endl;
			break;
		}

		i++;
	}
}

void toLower(char * cstr)
{
	int i = 0;
	while (true)
	{
		if (isalnum(cstr[i]))
		{
			std::cout << "Alphanumeric Character detected." << std::endl;
			//other code to change the array to lower and break if end
		}
		else if (!isalnum(cstr[i]))
		{
			std::cout << "ERROR: Non-Alphanumeric character detected." << std::endl;
			break;
		}

		i++;
	}
}

void main()
{
	/*
	//Closed 1
	while (true)
	{
		gameRelease();
	}
	*/

	/*
	//Closed 2
	while (true)
	{
		stepFizzBuzz();
	}
	*/

	//Closed 3
	std::cout << counter << std::endl;
	increment();
	std::cout << counter << std::endl;
	decrement();
	std::cout << counter << std::endl;
	increment();
	std::cout << counter << std::endl;

	//Closed 4
	divide(2.0f, 3.0f);
	divide(2.0f, 2.0f);
	divide(2.0f, 1.0f);
	divide(2.0f, 0.0f);

	//Open 1
	callMeMaybe();

	/*
	//Open 2
	int a = 2;
	int b = 4;
	int c = 6;

	while (true)
	{
		picker(a, b, c);
	}
	*/

	//Open 3
	//toUpper("Charm!");

	while (true);
}