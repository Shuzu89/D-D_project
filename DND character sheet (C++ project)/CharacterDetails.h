#pragma once
#include <iostream>
#include <string>
#include <fstream>

//determine stats, first and last name, modifiers, and class
class CharacterDetails
{
public:
	enum class Classes 
	{
		Artificer,
		Barbarian,
		Bard,
		Cleric,
		Monk,
		Ranger,
		Wizard,
		Warlock,
		Sorcerer,
		Druid,
		Fighter,
		Paladin,
		Rogue
	};

	CharacterDetails(); //Default Constructor
	CharacterDetails(std::string firstName, std::string lastName, int stats, Classes chosenClass, std::string strChosenClass);//Conversion constructor
	CharacterDetails(std::ifstream& fin); //loads character file
	int rollStat(int& stats); //rolls a character's stats
	void calcModifiers(int array[], int stats[]); //calculates modifiers based on the rolled stats
	void classSelect(Classes& chosenClass, std::string& strChosenClass); //lets the user pick a class from the list
	void raceSelect(std::string& race); //lets the user pcik a race from the list
	void save(std::ofstream& fout); //saves the data from the variables of the object to the passed in save file
	bool nameCheck(std::string currFirstName); //checks if the passed in name matches the objecct's firstName variable

	void print(); //prints firstName variable
	void addModifiers(int rolledValue); //adds modifiers to the roled values from the DiceRoll class
	Classes getChosenClass() const; //getter for chosenClass
	std::string getStrChosenClass() const; //getter for strChosenClass
	void printStatsModifiers(); //prints stats and modifiers variables
	void printRace(); //prints race variable

private:
	std::string firstName;
	std::string lastName;
	std::string race;
	Classes chosenClass;
	std::string strChosenClass;
	int stats[6];
	int modifiers[6];

};
