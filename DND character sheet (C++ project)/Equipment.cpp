#include "Equipment.h"
#include "CharacterDetails.h"
#include <iostream>
#include <random>
#include <vector>

std::string simpleWeapList();
std::string martialWeapList();

Equipment::Equipment(CharacterDetails& character)
{
	armor = pickArmor(armor, character);
	startingWealth = calcWealth(startingWealth, character);
	pickWeapons(weapons, character);
	pickPack(pack, character);
}

Equipment::Equipment(std::ifstream& fin)
{
	fin >> startingWealth;
	fin.ignore();
	getline(fin, armor);
	int numOfWeapons;
	fin >> numOfWeapons;
	for (int i = 0; i < numOfWeapons; i++)
	{
		std::string temp;
		fin >> temp;
		weapons.push_back(temp);
	}
	fin.ignore();
	getline(fin, pack);
}

std::string Equipment::pickArmor(std::string armor, CharacterDetails& character)
{
	CharacterDetails::Classes characterClass = character.getChosenClass();

	switch (characterClass)
	{
	case CharacterDetails::Classes::Artificer:
	{
		system("CLS");
		std::cout << "You have chosen the Artificer class, please pick your starting armor:" << '\n'
			<< "1. Studded leather armor" << '\n'
			<< "2. Scale mail" << std::endl;
		int userChoice{ 0 };
		std::cin >> userChoice;
		switch (userChoice)
		{
		case 1:
		{
			armor = "Studded leather armor";
			break;
		}
		case 2:
			armor = "Scale mail";
			break;
		}
		break;
	}
	case CharacterDetails::Classes::Barbarian:
	{
		system("CLS");
		std::cout << "Barbarian doesn't start with armor" << std::endl;
		armor = "None";
		break;
	}
	case CharacterDetails::Classes::Bard:
	{
		system("CLS");
		std::cout << "Bards start with Leather armor" << std::endl;
		armor = "Leather armor";
		break;
	}
	case CharacterDetails::Classes::Cleric:
	{
		system("CLS");
		std::cout << "You have chosen the Cleric class, please pick your starting armor:" << '\n'
			<< "1. Leather armor" << '\n'
			<< "2. Scale mail" << std::endl;
		int userChoice{ 0 };
		std::cin >> userChoice;
		switch (userChoice)
		{
		case 1:
		{
			armor = "Leather armor";
			break;
		}
		case 2:
		{
			armor = "Scale mail";
			break;
		}
		}
		break;
	}
	case CharacterDetails::Classes::Druid:
	{
		system("CLS");
		std::cout << "Druids start with leather armor" << std::endl;
		armor = "Leather armor";
		break;
	}
	case CharacterDetails::Classes::Fighter:
	{
		system("CLS");
		std::cout << "You have chosen the Fighter class, please pick your starting armor:" << '\n'
			<< "1. Leather armor" << '\n'
			<< "2. Chain mail" << std::endl;
		int userChoice{ 0 };
		std::cin >> userChoice;
		switch (userChoice)
		{
		case 1:
		{
			armor = "Leather armor";
			break;
		}
		case 2:
		{
			armor = "Chain mail";
			break;
		}
		}
		break;
	}
	case CharacterDetails::Classes::Monk:
	{
		system("CLS");
		std::cout << "Monks don't start with armor" << std::endl;
		armor = "None";
		break;
	}
	case CharacterDetails::Classes::Paladin:
	{
		system("CLS");
		std::cout << "Paladins start with Chain mail" << std::endl;
		armor = "Chain mail";
		break;
	}
	case CharacterDetails::Classes::Ranger:
	{
		system("CLS");
		std::cout << "You have chosen the Ranger class, please pick your starting armor:" << '\n'
			<< "1. Leather armor" << '\n'
			<< "2. Scale mail" << std::endl;
		int userChoice{ 0 };
		std::cin >> userChoice;
		switch (userChoice)
		{
		case 1:
		{
			armor = "Leather armor";
			break;
		}
		case 2:
		{
			armor = "Scale mail";
			break;
		}
		}
		break;
	}
	case CharacterDetails::Classes::Rogue:
	{
		system("CLS");
		std::cout << "Rogues start with leather armor" << std::endl;
		armor = "Leather armor";
		break;
	}
	case CharacterDetails::Classes::Sorcerer:
	{
		system("CLS");
		std::cout << "Sorcerers don't start with armor" << std::endl;
		armor = "None";
		break;
	}
	case CharacterDetails::Classes::Warlock:
	{
		system("CLS");
		std::cout << "Warlocks start with leather armor" << std::endl;
		armor = "Leather armor";
		break;
	}
	case CharacterDetails::Classes::Wizard:
	{
		system("CLS");
		std::cout << "Wizards don't start with armor" << std::endl;
		armor = "None";
		break;
	}
	default:
		break;
	}
	return armor;
}

int Equipment::calcWealth(int startingWealth, CharacterDetails& character)
{
	CharacterDetails::Classes characterClass = character.getChosenClass();

	std::random_device seed;
	std::default_random_engine e(seed());
	std::uniform_int_distribution d4Roll(1, 4);

	switch (characterClass)
	{
	case CharacterDetails::Classes::Artificer:
		for (int i = 0; i < 5; i++)
		{
			startingWealth += d4Roll(e);
		}
		startingWealth *= 10;
		break;
	case CharacterDetails::Classes::Barbarian:
		for (int i = 0; i < 2; i++)
		{
			startingWealth += d4Roll(e);
		}
		startingWealth *= 10;
		break;
	case CharacterDetails::Classes::Bard:
		for (int i = 0; i < 5; i++)
		{
			startingWealth += d4Roll(e);
		}
		startingWealth *= 10;
		break;
	case CharacterDetails::Classes::Cleric:
		for (int i = 0; i < 5; i++)
		{
			startingWealth += d4Roll(e);
		}
		startingWealth *= 10;
		break;
	case CharacterDetails::Classes::Monk:
		for (int i = 0; i < 5; i++)
		{
			startingWealth += d4Roll(e);
		}
		break;
	case CharacterDetails::Classes::Ranger:
		for (int i = 0; i < 5; i++)
		{
			startingWealth += d4Roll(e);
		}
		startingWealth *= 10;
		break;
	case CharacterDetails::Classes::Wizard:
		for (int i = 0; i < 4; i++)
		{
			startingWealth += d4Roll(e);
		}
		startingWealth *= 10;
		break;
	case CharacterDetails::Classes::Warlock:
		for (int i = 0; i < 4; i++)
		{
			startingWealth += d4Roll(e);
		}
		startingWealth *= 10;
		break;
	case CharacterDetails::Classes::Sorcerer:
		for (int i = 0; i < 3; i++)
		{
			startingWealth += d4Roll(e);
		}
		startingWealth *= 10;
		break;
	case CharacterDetails::Classes::Druid:
		for (int i = 0; i < 2; i++)
		{
			startingWealth += d4Roll(e);
		}
		startingWealth *= 10;
		break;
	case CharacterDetails::Classes::Fighter:
		for (int i = 0; i < 5; i++)
		{
			startingWealth += d4Roll(e);
		}
		startingWealth *= 10;
		break;
	case CharacterDetails::Classes::Paladin:
		for (int i = 0; i < 5; i++)
		{
			startingWealth += d4Roll(e);
		}
		startingWealth *= 10;
		break;
	case CharacterDetails::Classes::Rogue:
		for (int i = 0; i < 4; i++)
		{
			startingWealth += d4Roll(e);
		}
		startingWealth *= 10;
		break;
	default:
		break;
	}


	std::cout << "" << '\n'
		<< "Your starting gold is: " << startingWealth << '\n'
		<< " " << std::endl;

	return startingWealth;
}

void Equipment::pickWeapons(std::vector<std::string>& weapons, CharacterDetails& character)
{
	CharacterDetails::Classes characterClass = character.getChosenClass();

	std::string weapon;

	switch (characterClass)
	{
	case CharacterDetails::Classes::Artificer:
	{
		std::cout << "Artificers get to pick two simple weapons" << std::endl;
		for (int i = 0; i < 2; i++)
		{
			std::cout << "So far you have: ";
			if (!weapons.empty())
			{
				for (int j = 0; j < weapons.size(); j++)
				{
					std::cout << weapons[j] << std::endl;
				}
			}
			else
			{
				std::cout << "nothing" << std::endl;
			}

			weapon = simpleWeapList();
			weapons.push_back(weapon);
			system("CLS");
		}
		break;
	}
	case CharacterDetails::Classes::Barbarian:
	{
		std::cout << "Barbarians get to pick one Martial Weapon" << std::endl;
		weapon = martialWeapList();
		weapons.push_back(weapon);
		system("CLS");
		break;
	}
	case CharacterDetails::Classes::Bard:
	{
		int userChoice;
		std::cout << "Bards get to pick from the list below:" << '\n'
			<< "1. Rapier" << '\n'
			<< "2. Longsword" << '\n'
			<< "3. Simple weapon of choice" << std::endl;
		std::cin >> userChoice;
		switch (userChoice)
		{
		case 1:
		{
			weapon = "Rapier";
			weapons.push_back(weapon);
			system("CLS");
			break;
		}
		case 2:
		{
			weapon = "Longsword";
			weapons.push_back(weapon);
			system("CLS");
			break;
		}
		case 3:
		{
			weapon = simpleWeapList();
			weapons.push_back(weapon);
			system("CLS");
			break;
		}
		default:
			break;
		}
		break;
	}
	case CharacterDetails::Classes::Cleric:
	{
		std::cout << "Cleric start with a Mace" << std::endl;
		weapon = "Mace";
		weapons.push_back(weapon);
		system("CLS");
		break;
	}
	case CharacterDetails::Classes::Druid:
	{
		int userChoice;
		std::cout << "Druids get to pick from the list below:" << '\n'
			<< "1. Scimitar" << '\n'
			<< "2. Simple weapon of choice" << std::endl;
		std::cin >> userChoice;
		switch (userChoice)
		{
		case 1:
		{
			weapon = "Scimitar";
			weapons.push_back(weapon);
			system("CLS");
			break;
		}
		case 2:
		{
			weapon = simpleWeapList();
			weapons.push_back(weapon);
			system("CLS");
			break;
		}
		default:
			break;
		}
		break;
	}
	case CharacterDetails::Classes::Fighter:
	{
		std::cout << "Fighters get to pick two martial weapons" << " " << '\n' << std::endl;
		for (int i = 0; i < 2; i++)
		{
			std::cout << "So far you have: ";
			if (!weapons.empty())
			{
				for (int j = 0; j < weapons.size(); j++)
				{
					std::cout << weapons[j] << std::endl;
				}
			}
			else
			{
				std::cout << "nothing" << std::endl;
			}

			weapon = martialWeapList();
			weapons.push_back(weapon);
			system("CLS");
		}
		break;
	}
	case CharacterDetails::Classes::Monk:
	{
		int userChoice;
		std::cout << "Monks get to pick from the list below:" << '\n'
			<< "1. Shortsword" << '\n'
			<< "2. Simple weapon of choice" << std::endl;
		std::cin >> userChoice;
		switch (userChoice)
		{
		case 1:
		{
			weapon = "Shortsword";
			weapons.push_back(weapon);
			system("CLS");
			break;
		}
		case 2:
		{
			weapon = simpleWeapList();
			weapons.push_back(weapon);
			system("CLS");
			break;
		}
		default:
			break;
		}
		break;
	}
	case CharacterDetails::Classes::Paladin:
	{
		std::cout <<  "Paladins get to pick two martial weapons" << std::endl;
		for (int i = 0; i < 2; i++)
		{
			std::cout << "So far you have: ";
			if (!weapons.empty())
			{
				for (int j = 0; j < weapons.size(); j++)
				{
					std::cout << weapons[j] << std::endl;
				}
			}
			else
			{
				std::cout << "nothing" << std::endl;
			}

			weapon = martialWeapList();
			weapons.push_back(weapon);
			system("CLS");
		}
		break;
	}
	case CharacterDetails::Classes::Ranger:
	{
		int userChoice{ 0 };
		std::cout << "Rangers get to pick from the list below:" << '\n'
			<< "1. Two shortswords" << '\n'
			<< "2. Two simple melee weapons of choice" << std::endl;
		std::cin >> userChoice;
		switch (userChoice)
		{
		case 1:
		{
			for (int i = 0; i < 2; i++)
			{
				weapon = "Shortsword";
				weapons.push_back(weapon);
				system("CLS");
			}
			break;
		}
		case 2:
		{
			for (int i = 0; i < 2; i++)
			{
				system("CLS");
				std::cout << "So far you have: ";
				if (!weapons.empty())
				{
					for (int j = 0; j < weapons.size(); j++)
					{
						std::cout << weapons[j] << std::endl;
					}
				}
				else
				{
					std::cout << "nothing" << std::endl;
				}

				std::cout << "Please pick a weapon from the list below:" << '\n'
					<< "Melee Weapons:" << '\n'
					<< "1. Club" << '\n'
					<< "2. Dagger" << '\n'
					<< "3. Greatclub" << '\n'
					<< "4. Handaxe" << '\n'
					<< "5. Javelin" << '\n'
					<< "6. Light hammer" << '\n'
					<< "7. Mace	" << '\n'
					<< "8. Quarterstaff" << '\n'
					<< "9. Sickle" << '\n'
					<< "10. Spear" << std::endl;

				int weapChoice{ 0 };
				std::cin >> weapChoice;
				switch (weapChoice)
				{
				case 1:
				{
					weapon = "Club";
					weapons.push_back(weapon);
					system("CLS");
					break;
				}
				case 2:
				{
					weapon = "Dagger";
					weapons.push_back(weapon);
					system("CLS");
					break;
				}
				case 3:
				{
					weapon = "Greatclub";
					weapons.push_back(weapon);
					system("CLS");
					break;
				}
				case 4:
				{
					weapon = "Handaxe";
					weapons.push_back(weapon);
					system("CLS");
					break;
				}
				case 5:
				{
					weapon = "Javeline";
					weapons.push_back(weapon);
					system("CLS");
					break;
				}
				case 6:
				{
					weapon = "Lighthammer";
					weapons.push_back(weapon);
					system("CLS");
					break;
				}
				case 7:
				{
					weapon = "Mace";
					weapons.push_back(weapon);
					system("CLS");
					break;
				}
				case 8:
				{
					weapon = "Quarterstaff";
					weapons.push_back(weapon);
					system("CLS");
					break;
				}
				case 9:
				{
					weapon = "Sickle";
					weapons.push_back(weapon);
					system("CLS");
					break;
				}
				case 10:
				{
					weapon = "Spear";
					weapons.push_back(weapon);
					system("CLS");
					break;
				}
				default:
					break;
				}
			}
			break;
		}
		default:
			break;
		}
		break;
	}
	case CharacterDetails::Classes::Rogue:
	{
		int userChoice;
		std::cout << "Rogues get to pick from the list below:" << '\n'
			<< "1. Rapier" << '\n'
			<< "2. Shortsword" << std::endl;
		std::cin >> userChoice;
		switch (userChoice)
		{
		case 1:
		{
			weapon = "Rapier";
			weapons.push_back(weapon);
			system("CLS");
			break;
		}
		case 2:
		{
			weapon = "Shortsword";
			weapons.push_back(weapon);
			system("CLS");
			break;
		}
		default:
			break;
		}
		break;
	}
	case CharacterDetails::Classes::Sorcerer:
	{
		int userChoice;
		std::cout <<  "Sorcerers get to pick from the list below: " << '\n'
			<< "1. Light crossbow" << '\n'
			<< "2. Simple weapon of choice" << std::endl;
		std::cin >> userChoice;
		switch (userChoice)
		{
		case 1:
		{
			weapon = "Scimitar";
			weapons.push_back(weapon);
			system("CLS");
			break;
		}
		case 2:
		{
			weapon = simpleWeapList();
			weapons.push_back(weapon);
			system("CLS");
			break;
		}
		default:
			break;
		}
		break;
	}
	case CharacterDetails::Classes::Warlock:
	{
		int userChoice;
		std::cout << "Warlocks get to pick from the list below: " << '\n'
			<< "1. Light crossbow" << '\n'
			<< "2. Simple weapon of choice" << std::endl;
		std::cin >> userChoice;
		switch (userChoice)
		{
		case 1:
		{
			weapon = "Light crossbow";
			weapons.push_back(weapon);
			system("CLS");
			break;
		}
		case 2:
		{
			weapon = simpleWeapList();
			weapons.push_back(weapon);
			system("CLS");
			break;
		}
		default:
			break;
		}
		break;
	}
	case CharacterDetails::Classes::Wizard:
	{
		int userChoice;
		std::cout << "Wizards get to pick from the list below: " << '\n'
			<< "1. Quarterstaff" << '\n'
			<< "2. Dagger" << std::endl;
		std::cin >> userChoice;
		switch (userChoice)
		{
		case 1:
		{
			weapon = "Quarterstaff";
			weapons.push_back(weapon);
			system("CLS");
			break;
		}
		case 2:
		{
			weapon = "Dagger";
			weapons.push_back(weapon);
			system("CLS");
			break;
		}
		default:
			break;
		}
		break;
	}
	default:
		break;
	}
}

void Equipment::pickPack(std::string& pack, CharacterDetails& character)
{
	CharacterDetails::Classes characterClass = character.getChosenClass();

	switch (characterClass)
	{
	case CharacterDetails::Classes::Artificer:
	{
		std::cout << "Artificer's start with a dungeoneer's pack" << std::endl;
		pack = "Dungeoneer's pack";
		break;
	}
	case CharacterDetails::Classes::Barbarian:
	{
		pack = "Explorer's pack";
		break;
	}
	case CharacterDetails::Classes::Bard:
	{
		int packChoice;
		std::cout << "Bards get to pick from the following:" << '\n'
			<< "1. Diplomat's pack" << '\n'
			<< "2. Entertainer's pack" << std::endl;
		std::cin >> packChoice;

		switch (packChoice)
		{
		case 1:
		{
			pack = "Diplomat's pack";
			break;
		}
		case 2:
		{
			pack = "Entertainer's pack";
			break;
		}
		default:
			break;
		}
		break;
	}
	case CharacterDetails::Classes::Cleric:
	{
		int packChoice;
		std::cout << "Clerics get to pick from the following:" << '\n'
			<< "1. Priest's pack" << '\n'
			<< "2. Explorer's pack" << std::endl;
		std::cin >> packChoice;

		switch (packChoice)
		{
		case 1:
		{
			pack = "Priest's pack";
			break;
		}
		case 2:
		{
			pack = "Explorer's pack";
			break;
		}
		default:
			break;
		}
		break;
	}
	case CharacterDetails::Classes::Druid:
	{
		std::cout << "Druid's get an Explorer's pack";
		pack = "Explorer's pack";
		break;
	}
	case CharacterDetails::Classes::Fighter:
	{
		int packChoice;
		std::cout << "Fighters get to pick from the following:" << '\n'
			<< "1. Dungeoneer's pack" << '\n'
			<< "2. Explorer's pack" << std::endl;
		std::cin >> packChoice;
		switch (packChoice)
		{
		case 1:
		{
			pack = "Dungeoneer's pack";
			break;
		}
		case 2:
		{
			pack = "Explorer's pack";
			break;
		}
		default:
			break;
		}
		break;
	}
	case CharacterDetails::Classes::Monk:
	{
		int packChoice;
		std::cout << "Monks get to pick from the following:" << '\n'
			<< "1. Dungeoneer's pack" << '\n'
			<< "2. Explorer's pack" << std::endl;
		std::cin >> packChoice;
		switch (packChoice)
		{
		case 1:
		{
			pack = "Dungeoneer's pack";
			break;
		}
		case 2:
		{
			pack = "Explorer's pack";
			break;
		}
		default:
			break;
		}
		break;
	}
	case CharacterDetails::Classes::Paladin:
	{
		int packChoice;
		std::cout << "Paladins get to pick from the following:" << '\n'
			<< "1. Priest's pack" << '\n'
			<< "2. Explorer's pack" << std::endl;
		std::cin >> packChoice;

		switch (packChoice)
		{
		case 1:
		{
			pack = "Priest's pack";
			break;
		}
		case 2:
		{
			pack = "Explorer's pack";
			break;
		}
		default:
			break;
		}
		break;
	}
	case CharacterDetails::Classes::Ranger:
	{
		int packChoice;
		std::cout << "Rangers get to pick from the following:" << '\n'
			<< "1. Dungeoneer's pack" << '\n'
			<< "2. Explorer's pack" << std::endl;
		std::cin >> packChoice;
		switch (packChoice)
		{
		case 1:
		{
			pack = "Dungeoneer's pack";
			break;
		}
		case 2:
		{
			pack = "Explorer's pack";
			break;
		}
		default:
			break;
		}
		break;
	}
	case CharacterDetails::Classes::Rogue:
	{
		int packChoice;
		std::cout << "Rogues get to pick from the following:" << '\n'
			<< "1. Dungeoneer's pack" << '\n'
			<< "2. Burglar's pack" << '\n'
			<< "3. Explorer's pack" << std::endl;
		std::cin >> packChoice;
		switch (packChoice)
		{
		case 1:
		{
			pack = "Dungeoneer's pack";
			break;
		}
		case 2:
		{
			pack = "Burglar's pack";
			break;
		}
		case 3:
		{
			pack = "Explorer's pack";
			break;
		}
		default:
			break;
		}
		break;
	}
	case CharacterDetails::Classes::Sorcerer:
	{
		int packChoice;
		std::cout << "Sorcerers get to pick from the following:" << '\n'
			<< "1. Dungeoneer's pack" << '\n'
			<< "2. Explorer's pack" << std::endl;
		std::cin >> packChoice;
		switch (packChoice)
		{
		case 1:
		{
			pack = "Dungeoneer's pack";
			break;
		}
		case 2:
		{
			pack = "Explorer's pack";
			break;
		}
		default:
			break;
		}
		break;
	}
	case CharacterDetails::Classes::Warlock:
	{
		int packChoice;
		std::cout << "Warlocks get to pick from the following:" << '\n'
			<< "1. Dungeoneer's pack" << '\n'
			<< "2. Scholar's pack" << std::endl;
		std::cin >> packChoice;
		switch (packChoice)
		{
		case 1:
		{
			pack = "Dungeoneer's pack";
			break;
		}
		case 2:
		{
			pack = "Scholar's pack";
			break;
		}
		default:
			break;
		}
		break;
	}
	case CharacterDetails::Classes::Wizard:
	{
		int packChoice;
		std::cout << "Wizards get to pick from the following:" << '\n'
			<< "1. Explorer's pack" << '\n'
			<< "2. Scholar's pack" << std::endl;
		std::cin >> packChoice;
		switch (packChoice)
		{
		case 1:
		{
			pack = "Explorer's pack";
			break;
		}
		case 2:
		{
			pack = "Scholar's pack";
			break;
		}
		default:
			break;
		}
		break;
	}
	default:
		break;
	}
}

void Equipment::save(std::ofstream& fout)
{
	fout << startingWealth << '\n'
		<< armor << '\n'
		<< weapons.size();
	for(int i = 0; i < weapons.size(); i++ )
	{
		fout << '\n' << weapons[i];
	}
	fout << '\n' <<
		pack;
}

void Equipment::printArmor()
{
	std::cout << "Armor: " << armor << std::endl;
}

void Equipment::printGold()
{
	std::cout << "Gold: " << startingWealth << std::endl;
}

void Equipment::printWeapons()
{
	std::cout << "Weapons: " << std::endl;
	for (int i = 0; i < weapons.size(); i++)
	{
		std::cout << weapons.at(i) << '\n';
	}
}

void Equipment::printPack()
{
	std::cout << "Pack: " << pack << std::endl;
}
	
std::string simpleWeapList()
{
	std::cout << "Please pick a weapon from the list below:" << '\n'
		<< "Melee Weapons:" << '\n'
		<< "1. Club" << '\n'
		<< "2. Dagger" << '\n'
		<< "3. Greatclub" << '\n'
		<< "4. Handaxe" << '\n'
		<< "5. Javelin" << '\n'
		<< "6. Light hammer" << '\n'
		<< "7. Mace	" << '\n'
		<< "8. Quarterstaff" << '\n'
		<< "9. Sickle" << '\n'
		<< "10. Spear" << '\n'
		<< " " << '\n'
		<< "Ranged Weapons:" << '\n'
		<< "11. Light Crossbow" << '\n'
		<< "12. Dart" << '\n'
		<< "13. Shortbow" << '\n'
		<< "14. Sling" << std::endl;
	int weapChoice{ 0 };
	std::cin >> weapChoice;

	Equipment::SimpleWeapons chosenWeap{ weapChoice };

	switch (chosenWeap)
	{
	case Equipment::SimpleWeapons::CLUB:
		return "Club";
		break;
	case Equipment::SimpleWeapons::DAGGER:
		return "Dagger";
		break;
	case Equipment::SimpleWeapons::GREATCLUB:
		return "Great club";
		break;
	case Equipment::SimpleWeapons::HANDAXE:
		return "Handaxe";
		break;
	case Equipment::SimpleWeapons::JAVELIN:
		return "Javelin";
		break;
	case Equipment::SimpleWeapons::LIGHTHAMMER:
		return "Light hammer";
		break;
	case Equipment::SimpleWeapons::MACE:
		return "Mace";
		break;
	case Equipment::SimpleWeapons::QUARTERSTAFF:
		return "Quarterstaff";
		break;
	case Equipment::SimpleWeapons::SICKLE:
		return "Sickle";
		break;
	case Equipment::SimpleWeapons::SPEAR:
		return "Spear";
		break;
	case Equipment::SimpleWeapons::LIGHTCROSSBOW:
		return "Light Crossbow";
		break;
	case Equipment::SimpleWeapons::DART:
		return "Dart";
		break;
	case Equipment::SimpleWeapons::SHORTBOW:
		return "Short bow";
		break;
	case Equipment::SimpleWeapons::SLING:
		return "Sling";
		break;
	default:
		return "";
		break;
	}
}

std::string martialWeapList()
{
	std::cout << "Please pick a weapon from the list below:" << '\n'
		<< "Melee Weapons:" << '\n'
		<< "1. Battleaxe" << '\n'
		<< "2. Flail" << '\n'
		<< "3. Glaive" << '\n'
		<< "4. Greataxe" << '\n'
		<< "5. Greatsword" << '\n'
		<< "6. Halberd" << '\n'
		<< "7. Lance" << '\n'
		<< "8. Longsword" << '\n'
		<< "9. Maul" << '\n'
		<< "10. Morningstar" << '\n'
		<< "11. Pike" << '\n'
		<< "12. Rapier" << '\n'
		<< "13. Scimitar" << '\n'
		<< "14. Shortsword" << '\n'
		<< "15. Trident" << '\n'
		<< "16. War pick" << '\n'
		<< "17. Warhammer" << '\n'
		<< "18. Whip" << '\n'
		<< " " << '\n'
		<< "Ranged Weapons:" << '\n'
		<< "19. Blowgun" << '\n'
		<< "20. Hand Crossbow" << '\n'
		<< "21. Heavy Crossbow" << '\n'
		<< "22. Longbow" << '\n'
		<< "23. Net" << std::endl;
	int weapChoice{ 0 };
	std::cin >> weapChoice;


	//work on the block below, either enum class or int value is the conditional
	Equipment::MartialWeapons chosenWeapon{ weapChoice };

	switch (chosenWeapon)
	{
	case Equipment::MartialWeapons::BATTLEAXE:
		return "Battleaxe";
		break;
	case Equipment::MartialWeapons::FLAIL:
		return "Flail";
		break;
	case Equipment::MartialWeapons::GLAIVE:
		return "Glaive";
		break;
	case Equipment::MartialWeapons::GREATAXE:
		return "Greataxe";
		break;
	case Equipment::MartialWeapons::GREATSWORD:
		return "Greatsword";
		break;
	case Equipment::MartialWeapons::HALBERD:
		return "Halberd";
		break;
	case Equipment::MartialWeapons::LANCE:
		return "Lance";
		break;
	case Equipment::MartialWeapons::LONGSWORD:
		return "Longsword";
		break;
	case Equipment::MartialWeapons::MAUL:
		return "Maul";
		break;
	case Equipment::MartialWeapons::MORNINGSTAR:
		return "Morningstar";
		break;
	case Equipment::MartialWeapons::PIKE:
		return "Pike";
		break;
	case Equipment::MartialWeapons::RAPIER:
		return "Rapier";
		break;
	case Equipment::MartialWeapons::SCIMITAR:
		return "Scimitar";
		break;
	case Equipment::MartialWeapons::SHORTSWORD:
		return "Shortsword";
		break;
	case Equipment::MartialWeapons::TRIDENT:
		return "Trident";
		break;
	case Equipment::MartialWeapons::WARPICK:
		return "Warpick";
		break;
	case Equipment::MartialWeapons::WARHAMMER:
		return "Warhammer";
		break;
	case Equipment::MartialWeapons::WHIP:
		return "Whip";
		break;
	case Equipment::MartialWeapons::BLOWGUN:
		return "Blowgun";
		break;
	case Equipment::MartialWeapons::HANDCROSSBOW:
		return "Hand crossbow";
		break;
	case Equipment::MartialWeapons::HEAVYCROSSBOW:
		return "Heavy crossbow";
		break;
	case Equipment::MartialWeapons::LONGBOW:
		return "Longbow";
		break;
	case Equipment::MartialWeapons::NET:
		return "Net";
		break;
	default:
		return "";
		break;
	}
}