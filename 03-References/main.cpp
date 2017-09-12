#include <iostream>
#include <string>
#include <iomanip>
#include <random>
#include <ctime>

/*
struct Weapon
{
	int bluntDamage;
	int magicDamage;
	int bladeDamage;

	struct OwnerInfo
	{
		int playerID;
		bool isRare;
	};

	OwnerInfo owner;
};

void enhanceWeapon(Weapon &weap)
{
	weap.bluntDamage *= 2;
	weap.bladeDamage *= 2;
	weap.magicDamage *= 2;

}

void sum(int a, int b, int &c)
{
	c = a + b;
}

int main()
{
	int hotdog = 10;             //primitive variable
	int &dinosaur = hotdog;      //reference to hotdog
	int * dinosaurPtr = &hotdog; //pointer to hotdog
	
	int tacos = hotdog;          //copies the value of hotdog

	hotdog = 15;

	std::cout << hotdog << std::endl;
	std::cout << dinosaur << std::endl;
	std::cout << *dinosaurPtr << std::endl;

	std::cout << "tacos" << std::endl;
	std::cout << tacos << std::endl;

	//References with functions
	int valA = 1;
	int valB = 2;
	int valC = -1;

	std::cout << valC << std::endl;

	sum(valA, valB, valC);

	std::cout << valC << std::endl;


	Weapon hammer;
	hammer.bluntDamage = 9001;
	hammer.bladeDamage = 0;
	hammer.magicDamage = 0;

	std::cout << "Blunt " << hammer.bluntDamage << std::endl;
	std::cout << "Blade " << hammer.bladeDamage << std::endl;
	std::cout << "Magic " << hammer.magicDamage << std::endl;

	enhanceWeapon(hammer);

	std::cout << "Blunt " << hammer.bluntDamage << std::endl;
	std::cout << "Blade " << hammer.bladeDamage << std::endl;
	std::cout << "Magic " << hammer.magicDamage << std::endl;

	int thing = -12;

	Weapon arsenal[3] =
	{
		//Blunt   Blade   Magic  PID  Rarity
		{ 9001,     0,      0,   {0,   true}, thing},
		{  0,      9001,    0,   {0,   true}, thing},
		{  0,       0,    9001,  {0,  false}, thing}
	};

	for (int i = 0; i < 3; i++)
	{
		int &pid = arsenal[i].owner.playerID;
		std::cout << pid << std::endl;

		if (pid == 0)
		{
			pid = -1;
		}
	}

	std::cout << arsenal[0].testval << std::endl;

	thing = 32;

	std::cout << arsenal[0].testval << std::endl;

	while (true);
}
*/

void product(float a, float b, float &c)
{
	c = a * b;
}

void swap(float &a, float &b)
{
	a = a + b;
	b = a - b;
	a -= b;
}

struct Aussiegochi
{
	float happiness;
	float hunger;
	float thirst;
	float sanity;
};

void feedAussie(Aussiegochi &aus)
{
	aus.hunger += 10;
	aus.happiness += 5;
}

void waterAussie(Aussiegochi &aus)
{
	aus.thirst += 10;
	aus.happiness += 5;
}

void abuseAussie(Aussiegochi &aus)
{
	aus.sanity -= 10;
	aus.happiness -= 20;
}

void coddleAussie(Aussiegochi &aus)
{
	aus.happiness += 10;
	aus.sanity += 5;
}

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

void printPlaytime(Track track)
{
	if (track.playtime < 10)
	{
		std::cout << "0";
	}
	int min = track.playtime;
	int sec = ((track.playtime - min) * 100);
	std::cout << min << ":" << sec;
}

void printPlaylist(const Playlist &pl)
{
	//Makes floats print with 0 at the end instead of removing it
	std::cout << std::fixed;
	//Always prints a float with 2 decimal places.
	std::cout << std::setprecision(2);

	std::cout << pl.playlistName << std::endl;

	for (int i = 0; i < pl.trackCount; i++)
	{
		std::cout << "[";
		printPlaytime(pl.tracklist[i]);
		std::cout << "] - " << pl.tracklist[i].trackName << std::endl;
	}
}

void shufflePlaylist(Playlist &pl)
{
	srand(time(NULL));
	int counter = rand() % 100;
	Track temp;

	while (counter > 0)
	{
		int bogo = rand() % (pl.trackCount - 1);
		temp = pl.tracklist[bogo];
		pl.tracklist[bogo] = pl.tracklist[bogo + 1];
		pl.tracklist[bogo + 1] = temp;

		counter--;
	}
}

void dedupePlaylist(Playlist &pl)
{
	for (int i = 0; i < pl.trackCount; i++)
	{
		for (int j = 0; j < pl.trackCount; j++)
		{
			if (pl.tracklist[i].trackName == pl.tracklist[j].trackName)
			{
				//skip it or something
			}
		}
	}
}

void main()
{
	//Closed 1
	//Variables
	int num = 0;
	float dec = 0.0f;
	bool tf = false;
	char letter = 'a';

	//References
	int &numRef = num;
	float decRef = dec;
	bool &tfRef = tf;
	char &letterRef = letter;

	//Closed 2
	float valA = 5.0f;
	float valB = 5.0f;
	float valC = 0;
	product(valA, valB, valC);
	std::cout << valC << std::endl;

	valA = 1.5f;
	valB = 3.0f;
	product(valA, valB, valC);
	std::cout << valC << std::endl;

	valA = 7.2f;
	valB = 4.0f;
	product(valA, valB, valC);
	std::cout << valC << std::endl;

	//Open 1
	float numA = 5.0f;
	float numB = 5.0f;
	std::cout << "Value of A: " << numA << "\nValue of B: " << numB << std::endl;
	swap(numA, numB);
	std::cout << "Value of A: " << numA << "\nValue of B: " << numB << std::endl;
	std::cout << std::endl;

	numA = 1.5f;
	numB = 3.0f;
	std::cout << "Value of A: " << numA << "\nValue of B: " << numB << std::endl;
	swap(numA, numB);
	std::cout << "Value of A: " << numA << "\nValue of B: " << numB << std::endl;
	std::cout << std::endl;

	numA = 7.2f;
	numB = 4.0f;
	std::cout << "Value of A: " << numA << "\nValue of B: " << numB << std::endl;
	swap(numA, numB);
	std::cout << "Value of A: " << numA << "\nValue of B: " << numB << std::endl;
	std::cout << std::endl;

	//Open 2
	Aussiegochi pet;
	pet.happiness = 50;
	pet.hunger = 10;
	pet.thirst = 10;
	pet.sanity = 50;

	std::cout << "Aussiegochi's current status is:" << std::endl;
	std::cout << "Happiness: " << pet.happiness << std::endl;
	std::cout << "Hunger: " << pet.hunger << std::endl;
	std::cout << "Thirst: " << pet.thirst << std::endl;
	std::cout << "Sanity: " << pet.sanity << std::endl;
	std::cout << "You decided to feed Aussiegochi." << std::endl;
	std::cout << std::endl;
	feedAussie(pet);

	std::cout << "Aussiegochi's current status is:" << std::endl;
	std::cout << "Happiness: " << pet.happiness << std::endl;
	std::cout << "Hunger: " << pet.hunger << std::endl;
	std::cout << "Thirst: " << pet.thirst << std::endl;
	std::cout << "Sanity: " << pet.sanity << std::endl;
	std::cout << "You decided to water Aussiegochi." << std::endl;
	std::cout << std::endl;
	waterAussie(pet);

	std::cout << "Aussiegochi's current status is:" << std::endl;
	std::cout << "Happiness: " << pet.happiness << std::endl;
	std::cout << "Hunger: " << pet.hunger << std::endl;
	std::cout << "Thirst: " << pet.thirst << std::endl;
	std::cout << "Sanity: " << pet.sanity << std::endl;
	std::cout << "You decided to abuse Aussiegochi." << std::endl;
	std::cout << std::endl;
	abuseAussie(pet);

	std::cout << "Aussiegochi's current status is:" << std::endl;
	std::cout << "Happiness: " << pet.happiness << std::endl;
	std::cout << "Hunger: " << pet.hunger << std::endl;
	std::cout << "Thirst: " << pet.thirst << std::endl;
	std::cout << "Sanity: " << pet.sanity << std::endl;
	std::cout << "You decided to coddle Aussiegochi." << std::endl;
	std::cout << std::endl;
	coddleAussie(pet);

	std::cout << "Aussiegochi's current status is:" << std::endl;
	std::cout << "Happiness: " << pet.happiness << std::endl;
	std::cout << "Hunger: " << pet.hunger << std::endl;
	std::cout << "Thirst: " << pet.thirst << std::endl;
	std::cout << "Sanity: " << pet.sanity << std::endl;
	std::cout << std::endl;

	//Open 3
	Playlist favorite;
	favorite.playlistName = "Favorites";
	favorite.trackCount = 3;
	favorite.tracklist = new Track[favorite.trackCount];
	favorite.tracklist[0] = { "Song 1", 03.40f };
	favorite.tracklist[1] = { "Song 2", 02.50f };
	favorite.tracklist[2] = { "Song 3", 01.35f };

	Playlist videos;
	videos.playlistName = "Videos";
	videos.trackCount = 4;
	videos.tracklist = new Track[videos.trackCount];
	videos.tracklist[0] = { "Uncle Jerry's Embarrassing 51st Birthday", 58.42f };
	videos.tracklist[1] = { "Some stolen Youtube video", 15.36f };
	videos.tracklist[2] = { "That one time you did something really dumb and it got uploaded", 2.12f };
	videos.tracklist[3] = { "A funny video your friend recorded shortly before they moved away forever", 0.56f };

	printPlaylist(favorite);
	std::cout << std::endl;
	printPlaylist(videos);

	std::cout << std::endl;
	shufflePlaylist(favorite);
	printPlaylist(favorite);


	std::cout << "End of Program." << std::endl;
	while (true);
}