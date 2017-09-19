#include <iostream>
#include <string>
#include <fstream>
#include "product.h"

void main()
{
	//initialize
	bool fileFound = false;
	std::fstream cashier;
	std::string input;
	initializeProducts();

	std::cout << food.item[0].pName << std::endl;

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
				std::cin.ignore(100, '\n');

				if (input == "1")
				{
					std::cout << "You have selected Sales." << std::endl;
					menu = 1;
					break;
				}
				else if (input == "2")
				{
					std::cout << "You have selected Show Receipts." << std::endl;
					menu = 2;
					break;
				}

			case 1:
				while (true)
				{
					std::cout << "Page: Sales" << std::endl;
					std::cout << "Input product name or barcode." << std::endl;
					std::cin >> input;
					std::cin.ignore(100, '\n');

					for (int i = 0; i < food.barcode; i++)
					{
						if (food.barcode == input || food.item[i].pName == input)
						{
							//do something with this
						}
					}
				}
				break;


			case 2:
				//print out receipt information
				std::cout << "Not yet implemented." << std::endl;
				menu = 1;
				break;

			case 3:
				std::cout << "Page: Additional Options" << std::endl;
				//additional info
				break;
			}

		}
	}
}