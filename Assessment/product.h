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
	food.barcode = 5;
	food.item = new Product[food.barcode];
	food.item[0] = { "Cheesy Nuts", 1.50f };
	food.item[1] = { "Chicken Tendies", 2.50f };
	food.item[2] = { "Mac and Cheese - 2 Pack", 5.99f };
}