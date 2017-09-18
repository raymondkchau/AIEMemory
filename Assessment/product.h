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

Products dollarStore;
dollarStore.category = "Food";
dollarStore.barcode = 5;
dollarStore.item = new Product[barcode];
dollarStore.item[1]{ "Cheesy Nuts", 1.50f };

//Reference Code Below
struct Track
{
	std::string trackName; //name of track
	float playtime;        //track runtime
};

struct Playlist
{
	std::string playlistName; //name of playlist
	Track * tracklist;        //pointer to array of tracks
	int trackCount;           //number of tracks
};

Playlist favorite;
favorite.playlistName = "Favorites";
favorite.trackCount = 3;
favorite.tracklist = new Track[favorite.trackCount];
favorite.tracklist[0] = { "Song 1", 03.40f };
favorite.tracklist[1] = { "Song 2", 02.50f };
favorite.tracklist[2] = { "Song 3", 01.35f };