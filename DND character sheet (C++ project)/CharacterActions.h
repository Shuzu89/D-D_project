#pragma once
#include "CharacterDetails.h"
#include <iostream>
#include <string>
#include <vector>

class CharacterActions
{
public:
	CharacterActions(CharacterDetails& character); //default constructor
	CharacterActions(std::ifstream& fin);
	void pickSpells(std::vector<std::string>& spells, CharacterDetails& character);
	void assignMainActions(std::vector<std::string>& mainActions, CharacterDetails& character);
	void save(std::ofstream& fout);

	void printSpells(); //prints spells
	void printMainActions(); //prints mainActions

private:
	std::vector<std::string> spells;
	std::vector<std::string> mainActions;
};
