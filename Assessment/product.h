#pragma once
#include <iostream>
#include <string>
#include <iomanip>

struct Product
{
	std::string pName;
	float price;
};

struct Products
{
	std::string category;
	Product * item;
	int barcode;
};

//initializing things
Products food;

void initializeProducts()
{
	food.category = "Food";
	food.barcode = 6;
	food.item = new Product[food.barcode];
	food.item[0] = { "Cheesy Nuts", 1.50f };
	food.item[1] = { "Chicken Tendies", 2.50f };
	food.item[2] = { "Mac and Cheese - 2 Pack", 5.99f };
	food.item[3] = { "Doritos and Mountain Dew Gamer Pack", 13.37f };
	food.item[4] = { "Spam", 2.50f };
	food.item[5] = { "That cuddy old shoe in the back", 1.99f };
}

float tax(float subtotal)
{
	float total = roundf((subtotal * 1.095) * 100) / 100;
	return total;
}

float changeFunc(float total)
{
	std::string input;
	float payment = 0;

	while (true)
	{
		std::cout << "Input payment: ";
		std::cin >> input;
		std::cin.ignore(100, '\n');

		std::string::size_type sz;
		payment = std::stof(input.c_str(), &sz);

		total -= payment;
		total = roundf(total * 100) / 100;

		if (total <= 0)
		{
			if (total != 0)
			{
				total *= -1;
			}
			return total;
		}
		else if (total > 0)
		{
			std::cout << "An additional $" << total << " required." << std::endl;
		}
	}

	return total;
}