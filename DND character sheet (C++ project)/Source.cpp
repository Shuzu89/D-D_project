#include <iostream>
#include <vector>
#include <filesystem>
#include <random>
#include "CharacterDetails.h"
#include "Equipment.h"
#include "CharacterActions.h"


using namespace std;

void save(CharacterDetails& newCharacter, Equipment& characterEquipment, CharacterActions& charactersActions);
void load(std::vector<CharacterDetails>& characters, std::vector<Equipment>& charactersEquipment,
	std::vector<CharacterActions>& charactersActions);
void rollDice(int rollPick, CharacterDetails& selectedCharacter);

int main()
{

	char userChoice{'z'};
	std::vector<CharacterDetails> characters;
	std::vector<Equipment> charactersEquipment;
	std::vector<CharacterActions> charactersActions;

	std::cout << "Hello, welcome to Johnathan's DND program!" << endl;
	
	while (userChoice != 'q')
	{
		system("PAUSE");
		system("CLS");
		std::cout << "What do you wish to do?" << '\n'
			<< "(c)reate character sheet" << '\n'
			<< "(l)oad character sheet" << '\n'
			<< "(d)isplay character sheet" << '\n'
			<< "(r)oll a dice" << '\n'
			<< "(q)uit program" << endl;

		cin >> userChoice;

		switch (userChoice)
		{
		case 'c':
		{
			system("CLS");
			CharacterDetails newCharacter;
			characters.push_back(newCharacter);
			Equipment characterEquipment(newCharacter);
			charactersEquipment.push_back(characterEquipment);
			CharacterActions characterActions(newCharacter);
			charactersActions.push_back(characterActions);

			std::cout << "Would you like to save this character sheet? (y/n)" << endl;
			char saveChoice;
			cin >> saveChoice;
			switch (saveChoice)
			{
			case 'y':
			{
				save(newCharacter, characterEquipment, characterActions);
				break;
			}
			case 'n':
			{
				break;
			}
			}
			break;
		}
		case 'l':
		{
			load(characters, charactersEquipment, charactersActions);
			break;
		}
		case 'd':
		{

			if (characters.empty())
			{
				std::cout << "There are no characters loaded!" << endl;
				break;
			}

			std::cout << "Which character would you like to display?" << endl;
			for (int i = 0; i < characters.size(); i++)
			{
				std::cout << i + 1 << ". ";
				characters[i].print();
			}
			int temp;
			cin >> temp;
			temp -= 1;


			system("CLS");
			std::cout << "Character's name: ";
			characters[temp].print();
			characters[temp].printRace();
			std::cout << "Class: " << characters[temp].getStrChosenClass() << endl;;
			characters[temp].printStatsModifiers();
			charactersEquipment[temp].printGold();
			charactersEquipment[temp].printArmor();
			charactersEquipment[temp].printWeapons();
			charactersEquipment[temp].printPack();
			charactersActions[temp].printSpells();
			charactersActions[temp].printMainActions();
			break;
		}
		case 'r':
		{
			if (characters.empty())
			{
				std::cout << "There are no characters loaded!" << endl;
				break;
			}

			std::cout << "Which character would you like to roll for?" << endl;
			for (int i = 0; i < characters.size(); i++)
			{
				std::cout << i + 1 << ". ";
				characters[i].print();
			}
			int temp{ 0 };
			std::cin >> temp;

			if (temp <= 0 || temp > characters.size() || temp < characters.size())
			{
				std::cout << "Please select a valid character" << std::endl;
				break;
			}

			temp -= 1;
			int rollPick;
			std::cout << "What kind of dice do you wish to roll?" << '\n'
					<< "1. d4" << '\n'
					<< "2. d6" << '\n'
					<< "3. d8" << '\n'
					<< "4. d10" << '\n'
					<< "5. d12" << '\n'
					<< "6. d20" << endl;
			cin >> rollPick;
			rollDice(rollPick, characters[temp]);
			break;
		}
		default:
			break;
		}
	}
}

void save(CharacterDetails& newCharacter, Equipment& characterEquipment, CharacterActions& characterActions)
{
	std::string fileName;
	std::cout << "Please name the file you wish to save this character sheet in: ";
	std::cin.ignore();
	getline(std::cin, fileName);

	do
	{
		if (std::filesystem::exists(fileName))
		{
			std::cout << "File Name already exists, please choose another: " << std::endl;
			getline(std::cin, fileName);
		}

	} while (std::filesystem::exists(fileName));

	std::ofstream characterFile{ fileName };
	newCharacter.save(characterFile);
	characterEquipment.save(characterFile);
	characterActions.save(characterFile);
}

void load(std::vector<CharacterDetails>& characters, std::vector<Equipment>& charactersEquipment, std::vector<CharacterActions>& charactersActions)
{
	std::string fileName;
	std::cout << "What is the name of the file you wish to load?" << endl;
	cin >> fileName;

	if (std::filesystem::exists(fileName))
	{
		std::ifstream fin{ fileName };
		CharacterDetails loadedCharacter(fin);
		characters.push_back(loadedCharacter);
		Equipment loadedEquipment(fin);
		charactersEquipment.push_back(loadedEquipment);
		CharacterActions loadedCharacterActions(fin);
		charactersActions.push_back(loadedCharacterActions);
		std::cout << "...File Loaded!" << endl;
	}
	else
	{
		std::cout << "File does not exist!" << std::endl;
	}
}

void rollDice(int rollPick, CharacterDetails& selectedCharacter)
{
	random_device seed;
	default_random_engine e(seed());
	switch (rollPick)
	{
	case 1:
	{
		system("CLS");
		uniform_int_distribution diceRoll(1, 4);

		int rolledValue = diceRoll(e);

		std::cout << "You rolled a: " << rolledValue << '\n'
			<< "The roll with modifiers:" << endl;
		selectedCharacter.addModifiers(rolledValue);
		break;
	}
	case 2:
	{
		system("CLS");
		uniform_int_distribution diceRoll(1, 6);

		int rolledValue = diceRoll(e);

		std::cout << "You rolled a: " << rolledValue << '\n'
			<< "The roll with modifiers:" << endl;
		selectedCharacter.addModifiers(rolledValue);
		break;
	}
	case 3:
	{
		system("CLS");
		uniform_int_distribution diceRoll(1, 8);

		int rolledValue = diceRoll(e);

		std::cout << "You rolled a: " << rolledValue << '\n'
			<< "The roll with modifiers:" << endl;
		selectedCharacter.addModifiers(rolledValue);
		break;
	}
	case 4:
	{
		system("CLS");
		uniform_int_distribution diceRoll(1, 10);

		int rolledValue = diceRoll(e);

		std::cout << "You rolled a: " << rolledValue << '\n'
			<< "The roll with modifiers:" << endl;
		selectedCharacter.addModifiers(rolledValue);
		break;
	}
	case 5:
	{
		system("CLS");
		uniform_int_distribution diceRoll(1, 12);

		int rolledValue = diceRoll(e);

		std::cout << "You rolled a: " << rolledValue << '\n'
			<< "The roll with modifiers:" << endl;
		selectedCharacter.addModifiers(rolledValue);
		break;
	}
	case 6:
	{
		system("CLS");
		uniform_int_distribution diceRoll(1, 20);

		int rolledValue = diceRoll(e);

		std::cout << "You rolled a: " << rolledValue << '\n'
			<< "The roll with modifiers:" << endl;
		selectedCharacter.addModifiers(rolledValue);
		break;
	}
	}
}
