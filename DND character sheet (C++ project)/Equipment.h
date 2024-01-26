#pragma once
#include "CharacterDetails.h"
#include <iostream>
#include <string>
#include <vector>

//determines character's starting armor, wealth, weapons, and pack
class Equipment
{
public:
	Equipment(CharacterDetails& character); //Default constructor
	Equipment(std::ifstream& fin); //takes the loaded file and saves it's data to the created object's variable
	std::string pickArmor(std::string armor, CharacterDetails& character); //allows the user to pick a set of armor based on their character's class
	int calcWealth(int startingWealth, CharacterDetails& character); //calculates a character's wealth based on their class
	void pickWeapons(std::vector<std::string>& weapons, CharacterDetails& character); //allows the user to pick a weapon based on their character's class
	void pickPack(std::string& pack, CharacterDetails& character); //lets the user pick a pack based on their class
	void save(std::ofstream& fout); //saves the data from the variables of the object to the passed in save file
	
	void printArmor(); //prints armor
	void printGold(); //prints startingWealth 
	void printWeapons(); //prints weapons
	void printPack(); //prints pack

	enum class SimpleWeapons
	{
		CLUB = 1,
		DAGGER,
		GREATCLUB,
		HANDAXE,
		JAVELIN,
		LIGHTHAMMER,
		MACE,
		QUARTERSTAFF,
		SICKLE,
		SPEAR,
		LIGHTCROSSBOW,
		DART,
		SHORTBOW,
		SLING,
	};

	enum class MartialWeapons
	{
		BATTLEAXE = 1,
		FLAIL,
		GLAIVE,
		GREATAXE,
		GREATSWORD,
		HALBERD,
		LANCE,
		LONGSWORD,
		MAUL,
		MORNINGSTAR,
		PIKE,
		RAPIER,
		SCIMITAR,
		SHORTSWORD,
		TRIDENT,
		WARPICK,
		WARHAMMER,
		WHIP,
		BLOWGUN,
		HANDCROSSBOW,
		HEAVYCROSSBOW,
		LONGBOW,
		NET
	};


private:
	std::string armor;
	int startingWealth{ 0 };
	std::vector<std::string> weapons;
	std::string pack;
};