#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include "product.h"
#include "clearScreen.h"

void main()
{
	//initialize
	bool fileFound = false;
	std::fstream cashier;
	std::string input;
	initializeProducts();
	float subtotal = 0;

	//initialize time stuff
	struct tm buf; //stores time
	time_t t = time(NULL); //gets time now
	localtime_s(&buf, &t);
	std::string year = std::to_string(buf.tm_year + 1900);
	std::string month = std::to_string(buf.tm_mon + 1);
	std::string day = std::to_string(buf.tm_mday);
	std::string rName = "receipt";
	rName += year;
	rName += "-";
	rName += month;
	rName += "-";
	rName += day;
	rName += ".txt";

	cashier.open(rName, std::ios_base::out);

	//This part is probably useless as hell
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
				clearScreen();

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
				std::cout << "Page: Sales" << std::endl;
				std::cout << "Input product name or barcode." << std::endl;
				std::cout << "Please make sure you are inputing the right information,\nthere is no going back." << std::endl;
				std::cout << "Input \"end\" to finish." << std::endl;
				std::cout << std::endl;

				while (true)
				{
					std::cin >> input;
					std::cin.ignore(100, '\n');

					int barcode = atoi(input.c_str());

					if (input == "end")
					{
						std::cout << std::endl;

						float total = tax(subtotal);

						std::cout << "Subtotal: $" << subtotal << std::endl;
						std::cout << "Tax:      $" << total - subtotal << std::endl;
						std::cout << "Total:    $" << total << std::endl;

						cashier << "Subtotal: $" << subtotal << std::endl;
						cashier << "Tax:      $" << total - subtotal << std::endl;
						cashier << "Total:    $" << total << std::endl;

						change(total);

						std::cout << "Change:   $" << total << std::endl;
						std::cout << "Thank you!" << std::endl;

						cashier << "Change:   $" << total << std::endl;
						cashier << "Thank you!" << std::endl;
						std::cout << std::endl;
						break;
					}

					for (int i = 0; i < food.barcode; i++)
					{
						if (i == barcode || food.item[i].pName == input)
						{
							std::cout << i << " - " << food.item[i].pName << " - $" << food.item[i].price << std::endl;
							cashier << i << " - " << food.item[i].pName << " - $" << food.item[i].price << std::endl;
							std::cout << std::endl;
							subtotal += food.item[i].price;
						}
					}
				}
				break;

			case 2:
				//extra or something

			case 3:
				//print out receipt information
				std::cout << "Not yet implemented." << std::endl;
				menu = 1;
				break;

			case 4:
				std::cout << "Page: Additional Options" << std::endl;
				//additional info
				break;

			default:
				std::cout << "Error: Invalid input." << std::endl;

			}

		}
	}
}