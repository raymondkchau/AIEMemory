#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <time.h>
#include "entity.h"

int closed1()
{
	std::string fileName;
	std::cout << "Howdy! ";
	while (true)
	{
		while (true)
		{
			std::cout << "What file would you like to read?" << std::endl;
			std::cin >> fileName;

			std::fstream file;
			file.open(fileName, std::ios_base::in);

			if (file.fail())
			{
				std::cout << "Error: File not found" << std::endl;
				std::cout << std::endl;
				break;
			}

			std::cout << std::endl;
			std::cout << fileName << std::endl;
			std::cout << "----------------" << std::endl;

			std::string buffer;
			while (std::getline(file, buffer))
			{
				std::cout << buffer << std::endl;
			}

			std::cout << std::endl;

			file.clear();
			file.flush();
			file.close();
		}
	}

	return 0;
}

int closed2()
{
	std::string fileName;
	std::cout << "Where would you like to save this?" << std::endl;
	std::cin >> fileName;
	std::cin.ignore(1000, '\n');

	std::fstream file;
	file.open(fileName, std::ios_base::out);

	if (file.fail())
	{
		std::cout << "Error: File not found" << std::endl;
		std::cout << std::endl;
		return -1;
	}
	
	file.seekp(0, std::ios_base::end);

	std::cout << "What's your first name?" << std::endl;
	std::cin >> fileName;
	std::cin.ignore(1000, '\n');
	file << "Name: " << fileName << std::endl;

	std::cout << "How old are you?" << std::endl;
	std::cin >> fileName;
	std::cin.ignore(1000, '\n');
	file << "Age: " << fileName << std::endl;

	std::cout << "What's your favorite color?" << std::endl;
	std::cin >> fileName;
	std::cin.ignore(1000, '\n');
	file << "Favorite Color: " << fileName << std::endl;

	std::cout << "Thanks! Check your file for your results." << std::endl;

	file.clear();
	file.flush();
	file.close();

	return 0;
}

void open1()
{
	/*
	char * text[5];
	text[0] = { "September 13th, 2017" };
	text[1] = { "--------------------" };
	text[2] = { "These are the last minutes of my life." };
	text[3] = { "The dinosaurs will soon break in." };
	text[4] = { "They can smell my hotdogs." };

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < std::strlen(text[i]); j++)
		{
			srand(time(NULL));
			int RNG = rand() % 10;

			if (RNG <= 2)
			{
				char change[128];
				//gonna assume it works since I can't exactly check. Won't let me run strcpy or strcpy_s
				std::strcpy(text[i], change);
				change[j] = '█';
				std::strcpy(change, text[i]);
			}
		}
	}

	std::fstream file;
	file.open("importantMessage.txt", std::ios_base::out);

	if (file.fail())
	{
		std::cout << "Error: File not found." << std::endl;
	}

	file.seekp(0, std::ios_base::end);

	
	//█ alt+219 = Block, \219 maybe?
	file << text[0] << std::endl;
	file << text[1] << std::endl;
	file << std::endl;
	file << text[2] << std::endl;
	file << text[3] << std::endl;
	file << text[4] << std::endl;
	*/
}

void open2()
{
	char end;
	while (true)
	{
		std::cout << "Howdy! The following is from commaSep.txt" << std::endl;
		std::fstream file;
		file.open("commaSep.txt", std::ios_base::in);

		if (file.fail())
		{
			std::cout << "Error: File not found" << std::endl;
			std::cout << std::endl;
			break;
		}

		std::string buffer;
		std::cout << "{";
		while (std::getline(file, buffer))
		{
			std::cout << buffer;
			std::cout << ", ";
		}
		std::cout << "}";

		std::cout << std::endl;

		file.clear();
		file.flush();
		file.close();

		std::cin >> end;
	}
}

void open3()
{
	std::fstream entityStream;
	entityStream.open("monsters.txt");

	if (entityStream.fail())
	{
		std::cout << "Can't open file." << std::endl;
	}

	int entityCount = 0;
	Entity entities[100];

	while (true)
	{
		std::string buf;
		bool entityFound = false;
		//seek to next entity
		while (std::getline(entityStream, buf))
		{
			if (buf[0] == '@')
			{
				entityFound = true;
				break;
			}
		}

		//exit if no entity found
		if (!entityFound)
		{
			break;
		}

		//load data into the array of entities
		Entity &curEntity = entities[entityCount];

		std::getline(entityStream, buf);
		curEntity.hitpoints = stof(buf);
		std::getline(entityStream, buf);
		curEntity.armor = stof(buf);

		std::getline(entityStream, buf);
		curEntity.strength = stof(buf);
		std::getline(entityStream, buf);
		curEntity.defense = stof(buf);
		std::getline(entityStream, buf);
		curEntity.agility = stof(buf);
		std::getline(entityStream, buf);
		curEntity.luck = stof(buf);

		entityCount++;

		std::cout << curEntity.hitpoints << std::endl;
		std::cout << curEntity.armor << std::endl;
		std::cout << std::endl;

		//exit if no entity found
		if(entityCount >= 100)
		{
			break;
		}
	}

	//keep program running
	while (true);
}

int main()
{
	/*
	std::fstream file;

	file.open("text.txt", std::ios_base::out);

	if (file.fail())
	{
		std::cout << "File not found." << std::endl;
		return -1;
	}

	//Reading from a file
	std::string buffer;
	while (std::getline(file, buffer)) //iterates until error or end of file
	{
		//print the line after its buffered
		std::cout << buffer << std::endl;
	}

	file.clear(); // reset the error flags, such as EOF

	file.seekp(0, std::ios_base::end); //move my cursor to the end for writing

	//Writing to a file
	//Write a message!
	//Writes a new line and a message to the text file
	file << std::endl << "Today is always the present! :)";

	file.flush(); //flush the output buffer, making sure all outputs are sent
	file.close(); //close and release the file

	//let's make another thingie

	std::fstream autoCreate;

	autoCreate.open("createme.text", std::ios_base::out | std::ios_base::in);

	if (autoCreate.fail())
	{
		std::cout << "Something went wrong." << std::endl;
		return -1;
	}
	
	autoCreate.close();
	*/

	//closed1();
	//closed2();
	//open1();
	//open2();
	open3();

	while (true); // Keeps the program going
}