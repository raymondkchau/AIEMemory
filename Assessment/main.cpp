#include <iostream>
#include <string>
#include <fstream>
#include "product.h"

void main()
{
	bool fileFound = false;
	std::fstream cashier;
	std::string input;
	cashier.open("receipts.txt", std::ios_base::out);

	if (cashier.fail())
	{
		std::cout << "File not found." << std::endl;
		fileFound = false;
	}
	else
	{
		fileFound = true;
	}

	if (fileFound)
	{
		cashier.seekp(0, std::ios_base::end);
		int menu = 0;

		while (true)
		{
			switch (menu)
			{
			case 0:
				std::cout << "Page: Main Menu" << std::endl;
				std::cout << "1 - Sales" << std::endl;
				std::cout << "2 - Show Receipts" << std::endl;
				std::cin >> input;

			case 1:
				while (true)
				{
					std::cout << "Page: Sales" << std::endl;
					std::cout << "Input product name." << std::endl;
					std::cin >> input;
				}

			case 2:
				std::cout << "Page: Additional Options" << std::endl;
			}

		}
	}
}