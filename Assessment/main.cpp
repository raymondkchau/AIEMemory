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
	std::string buffer;
	initializeProducts();
	bool end = false;
	bool endProgram = false;
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

		while (!endProgram)
		{
			switch (menu)
			{
			case 0:
				std::cout << "Page: Main Menu" << std::endl;
				std::cout << "1 - Sales" << std::endl;
				std::cout << "2 - Show Receipts" << std::endl;
				std::cout << "5 - Close Program" << std::endl;
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
				else if (input == "5")
				{
					menu = 5;
					break;
				}

			case 1:
				end = false;
				subtotal = 0;
				std::cout << "Page: Sales" << std::endl;
				std::cout << "Input product name or barcode." << std::endl;
				std::cout << "Please make sure you are inputing the right information,\nthere is no going back." << std::endl;
				std::cout << "Input \"end\" to finish." << std::endl;
				std::cout << "Input \"menu\" to return to the menu." << std::endl;
				std::cout << std::endl;

				while (!end)
				{
					std::cin >> input;
					std::cin.ignore(100, '\n');

					int barcode = atoi(input.c_str());

					if (input == "menu")
					{
						std::cout << "Transaction Canceled/Returned to Menu" << std::endl;
						cashier << "Transaction Canceled/Returned to Menu" << std::endl;
						std::cout << std::endl;
						cashier << std::endl;
						menu = 0;
						end = true;
						break;
					}

					if (input == "end")
					{
						std::cout << std::endl;

						float total = tax(subtotal);

						std::cout << std::endl;
						std::cout << "Subtotal: $" << subtotal << std::endl;
						std::cout << "Tax:      $" << total - subtotal << std::endl;
						std::cout << "Total:    $" << total << std::endl;

						cashier << std::endl;
						cashier << "Subtotal: $" << subtotal << std::endl;
						cashier << "Tax:      $" << total - subtotal << std::endl;
						cashier << "Total:    $" << total << std::endl;

						float change = changeFunc(total);

						std::cout << std::endl;
						std::cout << "Change:   $" << change << std::endl;
						std::cout << "Thank you!" << std::endl;

						cashier << std::endl;
						cashier << "Change:   $" << change << std::endl;
						cashier << "Thank you!" << std::endl;

						std::cout << std::endl;
						cashier << std::endl;
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
				std::cout << std::endl;

				cashier.clear();
				cashier.flush();
				cashier.close();

				cashier.open(rName, std::ios_base::in);

				if (cashier.fail())
				{
					std::cout << "File not found." << std::endl;
					std::cout << std::endl;
					break;
				}

				while (std::getline(cashier, buffer))
				{
					std::cout << buffer << std::endl;
				}

				std::cout << std::endl;

				cashier.clear();
				cashier.flush();
				cashier.clear();

				cashier.open(rName, std::ios_base::out);

				menu = 0;
				break;

			case 4:
				std::cout << "Page: Additional Options" << std::endl;
				//additional info
				break;

			case 5:
				std::cout << std::endl;
				std::cout << "Ending Program..." << std::endl;
				cashier.clear();
				cashier.flush();
				cashier.close();
				std::cout << "Enter anything to continue." << std::endl;
				std::cin >> input;
				endProgram = true;
				break;

			default:
				std::cout << "Error: Invalid input." << std::endl;

			}

		}
	}
}