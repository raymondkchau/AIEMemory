#pragma once
#include <string>

struct Product
{
	int barcode;
	std::string pName;
	float price;
};

struct Products
{
	Product item;
};

Products *dollarStore[10];
dollarStore[1]{ 03, "Stuff", 1.50f };