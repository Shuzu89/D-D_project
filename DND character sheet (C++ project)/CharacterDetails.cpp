#include <random>
#include "CharacterDetails.h"

CharacterDetails::CharacterDetails() //Default Constructor
{
	std::cout << "You have chose to create a new character!" << '\n'
		<< "Please enter the required information below:" << '\n' << std::endl;

	std::cout << "What is your character's first name?: ";
	std::cin >> firstName;
	std::cout << std::endl;

	std::cout << "What is your character's last name?: ";
	std::cin >> lastName;
	std::cout << std::endl;

	raceSelect(race);

	classSelect(chosenClass, strChosenClass);

	for (int i = 0; i < 6; i++)
	{
		stats[i] = rollStat(stats[i]);
	}

	calcModifiers(modifiers, stats);

	system("CLS");
	std::cout << "The stats you rolled with their modifiers in (): " << '\n'
		<< " " << '\n'
		<< "Strength: " << stats[0] << "(" << modifiers[0] << ")" << '\n'
		<< "Dexterity: " << stats[1] << "(" << modifiers[1] << ")" << '\n'
		<< "Constitution: " << stats[2] << "(" << modifiers[2] << ")" << '\n'
		<< "Wisdom: " << stats[3] << "(" << modifiers[3] << ")" << '\n'
		<< "Intelligence: " << stats[4] << "(" << modifiers[4] << ")" << '\n'
		<< "Charisma: " << stats[5] << "(" << modifiers[5] << ")" << std::endl;
	system("PAUSE");


}

CharacterDetails::CharacterDetails(std::string firstName, std::string lastName, int stats, Classes chosenClass, std::string strChosenClass) //Conversion constrcutor
	:firstName{ firstName }, lastName{ lastName }, chosenClass{chosenClass}, stats{ stats }, strChosenClass{strChosenClass}
{
}

CharacterDetails::CharacterDetails(std::ifstream& fin)
{

	fin >> firstName >> lastName >> race >> strChosenClass;
	int temp;
	fin >> temp;
	chosenClass = static_cast<Classes>(temp);
	for (int i = 0; i < 6; i++)
	{
		fin >> stats[i];
	}
	for (int i = 0; i < 6; i++)
	{
		fin >> modifiers[i];
	}
}

int CharacterDetails::rollStat(int& stats) //rolls stats for character
{
	for (int i = 0; i < 6; i++)
	{
		int allRolls[4];

		for (int j = 0; j < 4; j++)
		{
			std::random_device seed;
			std::default_random_engine e(seed());
			std::uniform_int_distribution diceRoll(1, 6);
			allRolls[j] = diceRoll(e);
		}

		std::sort(allRolls, allRolls + 4, std::greater<int>());

		int biggestRolls[3];
		for (int j = 0; j < 3; j++)
		{
			biggestRolls[j] = allRolls[j];
		}

		stats = biggestRolls[0] + biggestRolls[1] + biggestRolls[2];
		return stats;
	}
}

void CharacterDetails::calcModifiers(int modifiers[], int stats[]) //calculates modifiers
{

	for (int i = 0; i < 6; i++)
	{
		switch (stats[i])
		{
		case 1:
		{
			modifiers[i] = -5;
			break;
		}
		case 2:
		{
			modifiers[i] = -4;
			break;
		}
		case 3:
		{
			modifiers[i] = -4;
			break;
		}
		case 4:
		{
			modifiers[i] = -3;
			break;
		}
		case 5:
		{
			modifiers[i] = -5;
			break;
		}
		case 6:
		{
			modifiers[i] = -2;
			break;
		}
		case 7:
		{
			modifiers[i] = -2;
			break;
		}
		case 8:
		{
			modifiers[i] = -1;
			break;
		}
		case 9:
		{
			modifiers[i] = -1;
			break;
		}
		case 10:
		{
			modifiers[i] = 0;
			break;
		}
		case 11:
		{
			modifiers[i] = 0;
			break;
		}
		case 12:
		{
			modifiers[i] = +1;
			break;
		}
		case 13:
		{
			modifiers[i] = +1;
			break;
		}
		case 14:
		{
			modifiers[i] = +2;
			break;
		}
		case 15:
		{
			modifiers[i] = +2;
			break;
		}
		case 16:
		{
			modifiers[i] = +3;
			break;
		}
		case 17:
		{
			modifiers[i] = +3;
			break;
		}
		case 18:
		{
			modifiers[i] = +4;
			break;
		}
		case 19:
		{
			modifiers[i] = +4;
			break;
		}
		case 20:
		{
			modifiers[i] = +5;
			break;
		}
		case 21:
		{
			modifiers[i] = +5;
			break;
		}
		case 22:
		{
			modifiers[i] = +6;
			break;
		}
		case 23:
		{
			modifiers[i] = +6;
			break;
		}
		case 24:
		{
			modifiers[i] = +7;
			break;
		}
		case 25:
		{
			modifiers[i] = +7;
			break;
		}
		case 26:
		{
			modifiers[i] = +8;
			break;
		}
		case 27:
		{
			modifiers[i] = +8;
			break;
		}
		case 28:
		{
			modifiers[i] = +9;
			break;
		}
		case 29:
		{
			modifiers[i] = +9;
			break;
		}
		case 30:
		{
			modifiers[i] = +10;
			break;
		}
		default:
			break;
		}
	}
}

void CharacterDetails::classSelect(Classes& chosenClass, std::string& strChosenClass)
{
	system("CLS");

	std::cout << "Please choose a class from the following list:" << '\n'
		<< "1. Artificer" << '\n'
		<< "2. Barbarian" << '\n'
		<< "3. Bard" << '\n'
		<< "4. Cleric" << '\n'
		<< "5. Monk" << '\n'
		<< "6. Ranger" << '\n'
		<< "7. Wizard" << '\n'
		<< "8. Warlock" << '\n'
		<< "9. Sorcerer" << '\n'
		<< "10. Druid" << '\n'
		<< "11. Fighter" << '\n'
		<< "12. Paladin" << '\n'
		<< "13. Rogue" << std::endl;

	int userInput{};
	std::cin >> userInput;

	switch (userInput)
	{
	case 1:
	{
		strChosenClass = "Artificer";
		break;
	}
	case 2:
	{
		strChosenClass = "Barbarian";
		break;
	}
	case 3:
	{
		strChosenClass = "Bard";
		break;
	}
	case 4:
	{
		strChosenClass = "Cleric";
		break;
	}
	case 5:
	{
		strChosenClass = "Monk";
		break;
	}
	case 6:
	{
		strChosenClass = "Ranger";
		break;
	}
	case 7:
	{
		strChosenClass = "Wizard";
		break;
	}
	case 8:
	{
		strChosenClass = "Warlcok";
		break;
	}
	case 9:
	{
		strChosenClass = "Sorcerer";
		break;
	}
	case 10:
	{
		strChosenClass = "Druid";
		break;
	}
	case 11:
	{
		strChosenClass = "Fighter";
		break;
	}
	case 12:
	{
		strChosenClass = "Paladin";
		break;
	}
	case 13:
	{
		strChosenClass = "Rogue";
		break;
	}
	default:
		break;
	}

	chosenClass = ((CharacterDetails::Classes)(userInput - 1));
}

void CharacterDetails::raceSelect(std::string& race)
{
	system("CLS");

	std::cout << "Please select a race for your character from the list below:" << '\n'
		<< "1. Dragonborn" << '\n'
		<< "2. Dwarf" << '\n'
		<< "3. Elf" << '\n'
		<< "4. Gnome" << '\n'
		<< "5. Half-Elf" << '\n'
		<< "6. Half-Orc" << '\n'
		<< "7. Halfling" << '\n'
		<< "8. Human" << '\n'
		<< "9. Tiefling" << std::endl;

	int raceChoice;
	std::cin >> raceChoice;
	switch (raceChoice)
	{
	case 1:
	{
		race = "Dragonborn";
		break;
	}
	case 2:
	{
		race = "Dwarf";
		break;
	}
	case 3:
	{
		race = "Elf";
		break;
	}
	case 4:
	{
		race = "Gnome";
		break;
	}
	case 5:
	{
		race = "Half-Elf";
		break;
	}
	case 6:
	{
		race = "Half-Orc";
		break;
	}
	case 7:
	{
		race = "Halfling";
		break;
	}
	case 8:
	{
		race = "Human";
		break;
	}
	case 9:
	{
		race = "Tiefling";
		break;
	}
	default:
		break;
	}
}

void CharacterDetails::save(std::ofstream& fout)
{
	fout << firstName << '\n'
		<< lastName << '\n'
		<< race << '\n'
		<< getStrChosenClass() << '\n'
		<< static_cast<int>(chosenClass) << '\n'
		<< stats[0] << '\n' 
		<< stats[1] << '\n' 
		<< stats[2] << '\n' 
		<< stats[3] << '\n' 
		<< stats[4] << '\n' 
		<< stats[5] << '\n' 
		<< modifiers[0] << '\n'
		<< modifiers[1] << '\n'
		<< modifiers[2] << '\n'
		<< modifiers[3] << '\n'
		<< modifiers[4] << '\n'
		<< modifiers[5] << std::endl;
}

bool CharacterDetails::nameCheck(std::string currFirstName)
{
	if (currFirstName == firstName)
	{
		std::cout << "Character found" << std::endl;
		system("PAUSE");
		return true;
	}
	else
	{
		std::cout << "Character not found" << std::endl;
		system("PAUSE");
		return false;
	}
}

void CharacterDetails::print()
{
	std::cout << firstName <<  " " << lastName << std::endl;
}

void CharacterDetails::addModifiers(int rolledValue)
{

	std::cout << "Strength: " << rolledValue + modifiers[0] << '\n'
		<< "Dexterity: " << rolledValue + modifiers[1] << '\n'
		<< "Constitution: " << rolledValue + modifiers[2] << '\n'
		<< "Wisdom: " << rolledValue + modifiers[3] << '\n'
		<< "Intelligence: " << rolledValue + modifiers[4] << '\n'
		<< "Charisma: " << rolledValue + modifiers[5] << std::endl;

}

CharacterDetails::Classes CharacterDetails::getChosenClass() const
{
	return chosenClass;
}

std::string CharacterDetails::getStrChosenClass() const
{
	return strChosenClass;
}

void CharacterDetails::printStatsModifiers()
{
	std::cout << "Stats with their modifiers in (): " << '\n'
		<< "Strength: " << stats[0] << "(" << modifiers[0] << ")" << '\n'
		<< "Dexterity: " << stats[1] << "(" << modifiers[1] << ")" << '\n'
		<< "Constitution: " << stats[2] << "(" << modifiers[2] << ")" << '\n'
		<< "Wisdom: " << stats[3] << "(" << modifiers[3] << ")" << '\n'
		<< "Intelligence: " << stats[4] << "(" << modifiers[4] << ")" << '\n'
		<< "Charisma: " << stats[5] << "(" << modifiers[5] << ")" << std::endl;
}

void CharacterDetails::printRace()
{
	std::cout << "Character's Race: " << race << std::endl;
}

