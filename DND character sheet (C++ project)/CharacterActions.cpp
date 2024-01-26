#include "CharacterActions.h"

CharacterActions::CharacterActions(CharacterDetails& character)
{
	pickSpells(spells, character);
    assignMainActions(mainActions, character);
}

CharacterActions::CharacterActions(std::ifstream& fin)
{
    int numOfSpells{ -1 };
    int numOfMainActions{ -1 };
    fin >> numOfSpells;
    if (numOfSpells > 0)
    {
        fin.ignore();
        for (int i = 0; i < numOfSpells; i++)
        {
            std::string temp;
            getline(fin, temp);
            spells.push_back(temp);
        }
    }
    fin >> numOfMainActions;
    for (int i = 0; i < numOfMainActions; i++)
    {
        std::string temp;
        fin >> temp;
        mainActions.push_back(temp);
    }
}

void CharacterActions::pickSpells(std::vector<std::string>& spells, CharacterDetails& character)
{
    CharacterDetails::Classes characterClass = character.getChosenClass();

    int spellChoice;

    switch (characterClass)
    {
    case CharacterDetails::Classes::Artificer:
    {
        std::cout << "Artificers get to pick two spells to begin with" << '\n'
            << "Please pick from the list below:" << '\n'
            << "1. Detect Magic" << '\n'
            << "2. Cure Wounds" << '\n'
            << "3. Absorb Elements" << '\n'
            << "4. False Life" << '\n'
            << "5. Feather Fall" << std::endl;
        for (int i = 0; i < 2; i++)
        {
            std::string spell;
            std::cout << "So far you have: ";
            if (!spells.empty())
            {
                for (int j = 0; j < spells.size(); j++)
                {
                    std::cout << spells.at(j) << std::endl;
                }
            }
            else
            {
                std::cout << "nothing" << std::endl;
            }

            std::cin >> spellChoice;
            switch (spellChoice)
            {
            case 1:
            {
                spell = "Detect Magic";
                spells.push_back(spell);
                break;
            }
            case 2:
            {
                spell = "Cure Wounds";
                spells.push_back(spell);
                break;
            }
            case 3:
            {
                spell = "Absorb Elements";
                spells.push_back(spell);
                break;
            }
            case 4:
            {
                spell = "False Life";
                spells.push_back(spell);
                break;
            }
            case 5:
            {
                spell = "Feather Fall";
                spells.push_back(spell);
                break;
            }
            default:
                break;
            }
        }
        break;
    }

    case CharacterDetails::Classes::Bard:
    {
        std::cout << "Bards get to pick two spells to begin with" << '\n'
            << "Please pick from the list below:" << '\n'
            << "1. Sleep" << '\n'
            << "2. Identify" << '\n'
            << "3. Cure Wounds" << '\n'
            << "4. Command" << '\n'
            << "5. Charm Person" << std::endl;
        for (int i = 0; i < 2; i++)
        {
            std::string spell;
            std::cout << "So far you have: ";
            if (!spells.empty())
            {
                for (int j = 0; j < spells.size(); j++)
                {
                    std::cout << spells.at(j) << std::endl;
                }
            }
            else
            {
                std::cout << "nothing" << std::endl;
            }
            std::cin >> spellChoice;
            switch (spellChoice)
            {
            case 1:
            {
                spell = "Sleep";
                spells.push_back(spell);
                break;
            }
            case 2:
            {
                spell = "Identify";
                spells.push_back(spell);
                break;
            }
            case 3:
            {
                spell = "Cure Wounds";
                spells.push_back(spell);
                break;
            }
            case 4:
            {
                spell = "Command";
                spells.push_back(spell);
                break;
            }
            case 5:
            {
                spell = "Charm Person";
                spells.push_back(spell);
                break;
            }
            default:
                break;
            }
        }
        break;
    }

    case CharacterDetails::Classes::Cleric:
    {
        std::cout << "Clerics get to pick two spells to begin with" << '\n'
            << "Please pick from the list below:" << '\n'
            << "1. Command" << '\n'
            << "2. Detect Magic" << '\n'
            << "3. Cure Wounds" << '\n'
            << "4. Bless" << '\n'
            << "5. Healing Word" << std::endl;
        for (int i = 0; i < 2; i++)
        {
            std::string spell;
            std::cout << "So far you have: ";
            if (!spells.empty())
            {
                for (int j = 0; j < spells.size(); j++)
                {
                    std::cout << spells.at(j) << std::endl;
                }
            }
            else
            {
                std::cout << "nothing" << std::endl;
            }
            std::cin >> spellChoice;
            switch (spellChoice)
            {
            case 1:
            {
                spell = "Command";
                spells.push_back(spell);
                break;
            }
            case 2:
            {
                spell = "Detect Magic";
                spells.push_back(spell);
                break;
            }
            case 3:
            {
                spell = "Cure Wounds";
                spells.push_back(spell);
                break;
            }
            case 4:
            {
                spell = "Bless";
                spells.push_back(spell);
                break;
            }
            case 5:
            {
                spell = "Healing Word";
                spells.push_back(spell);
                break;
            }
            default:
                break;
            }
        }
        break;
    }

    case CharacterDetails::Classes::Druid:
    {
        std::cout << "Druids get to pick two spells to begin with" << '\n'
            << "Please pick from the list below:" << '\n'
            << "1. Detect Magic" << '\n'
            << "2. Fog Cloud" << '\n'
            << "3. Thunderwave" << '\n'
            << "4. Speak with Animals" << '\n'
            << "5. Healing Word" << std::endl;
        for (int i = 0; i < 2; i++)
        {
            std::string spell;
            std::cout << "So far you have: ";
            if (!spells.empty())
            {
                for (int j = 0; j < spells.size(); j++)
                {
                    std::cout << spells.at(j) << std::endl;
                }
            }
            else
            {
                std::cout << "nothing" << std::endl;
            }
            std::cin >> spellChoice;
            switch (spellChoice)
            {
            case 1:
            {
                spell = "Detect Magic";
                spells.push_back(spell);
                break;
            }
            case 2:
            {
                spell = "Fog Cloud";
                spells.push_back(spell);
                break;
            }
            case 3:
            {
                spell = "Thunderwave";
                spells.push_back(spell);
                break;
            }
            case 4:
            {
                spell = "Speak with Animals";
                spells.push_back(spell);
                break;
            }
            case 5:
            {
                spell = "Healing Word";
                spells.push_back(spell);
                break;
            }
            default:
                break;
            }
        }
        break;
    }

    case CharacterDetails::Classes::Sorcerer:
    {
        std::cout << "Sorcerers get to pick two spells to begin with" << '\n'
            << "Please pick from the list below:" << '\n'
            << "1. Burning Hands" << '\n'
            << "2. Disguise Self" << '\n'
            << "3. False Life" << '\n'
            << "4. Shield" << '\n'
            << "5. Witch Bolt" << std::endl;
        for (int i = 0; i < 2; i++)
        {
            std::string spell;
            std::cout << "So far you have: ";
            if (!spells.empty())
            {
                for (int j = 0; j < spells.size(); j++)
                {
                    std::cout << spells.at(j) << std::endl;
                }
            }
            else
            {
                std::cout << "nothing" << std::endl;
            }
            std::cin >> spellChoice;
            switch (spellChoice)
            {
            case 1:
            {
                spell = "Burning Hands";
                spells.push_back(spell);
                break;
            }
            case 2:
            {
                spell = "Disguise Self";
                spells.push_back(spell);
                break;
            }
            case 3:
            {
                spell = "False Life";
                spells.push_back(spell);
                break;
            }
            case 4:
            {
                spell = "Shield";
                spells.push_back(spell);
                break;
            }
            case 5:
            {
                spell = "Witch Bolt";
                spells.push_back(spell);
                break;
            }
            default:
                break;
            }
        }
        break;
    }

    case CharacterDetails::Classes::Warlock:
    {
        std::cout << "Warlocks get to pick two spells to begin with" << '\n'
            << "Please pick from the list below:" << '\n'
            << "1. Hex" << '\n'
            << "2. Witch Bolt" << '\n'
            << "3. Hellish Rebuke" << '\n'
            << "4. Charm Person" << '\n'
            << "5. Cause Fear" << std::endl;
        for (int i = 0; i < 2; i++)
        {
            std::string spell;
            std::cout << "So far you have: ";
            if (!spells.empty())
            {
                for (int j = 0; j < spells.size(); j++)
                {
                    std::cout << spells.at(j) << std::endl;
                }
            }
            else
            {
                std::cout << "nothing" << std::endl;
            }
            std::cin >> spellChoice;
            switch (spellChoice)
            {
            case 1:
            {
                spell = "Hex";
                spells.push_back(spell);
                break;
            }
            case 2:
            {
                spell = "Witch Bolt";
                spells.push_back(spell);
                break;
            }
            case 3:
            {
                spell = "Hellish Rebuke";
                spells.push_back(spell);
                break;
            }
            case 4:
            {
                spell = "Charm Person";
                spells.push_back(spell);
                break;
            }
            case 5:
            {
                spell = "Cause Fear";
                spells.push_back(spell);
                break;
            }
            default:
                break;
            }
        }
        break;
    }

    case CharacterDetails::Classes::Wizard:
    {
        std::cout << "Wizards get to pick two spells to begin with" << '\n'
            << "Please pick from the list below:" << '\n'
            << "1. Witch Bolt" << '\n'
            << "2. Burning Hands" << '\n'
            << "3. Sleep" << '\n'
            << "4. Magic Missile" << '\n'
            << "5. Earth Tremor" << std::endl;
        for (int i = 0; i < 2; i++)
        {
            std::string spell;
            std::cout << "So far you have: ";
            if (!spells.empty())
            {
                for (int j = 0; j < spells.size(); j++)
                {
                    std::cout << spells.at(j) << std::endl;
                }
            }
            else
            {
                std::cout << "nothing" << std::endl;
            }
            std::cin >> spellChoice;
            switch (spellChoice)
            {
            case 1:
            {
                spell = "Witch Bolt";
                spells.push_back(spell);
                break;
            }
            case 2:
            {
                spell = "Burning Hands";
                spells.push_back(spell);
                break;
            }
            case 3:
            {
                spell = "Sleep";
                spells.push_back(spell);
                break;
            }
            case 4:
            {
                spell = "Magic Missile";
                spells.push_back(spell);
                break;
            }
            case 5:
            {
                spell = "Earth Tremor";
                spells.push_back(spell);
                break;
            }
            default:
                break;
            }
        }
        break;
    }

    default:
        std::string spell;
        spell = "none";
        spells.push_back(spell);
        break;
    }
}

void CharacterActions::assignMainActions(std::vector<std::string>& mainActions, CharacterDetails& character)
{
    CharacterDetails::Classes characterClass = character.getChosenClass();

    std::string action;
    action = "Weapon Attack";
    mainActions.push_back(action);
    action = "Drink Potion";
    mainActions.push_back(action);
    action = "Dodge";
    mainActions.push_back(action);
    action = "Disengage";
    mainActions.push_back(action);

    switch (characterClass)
    {
    case CharacterDetails::Classes::Artificer:
    {
        action = "Magical Tinkering";
        mainActions.push_back(action);
        action = "Spellcasting";
        mainActions.push_back(action);
        break;
    }
    case CharacterDetails::Classes::Bard:
    {
        action = "Spellcasting";
        mainActions.push_back(action);
        action = "Bardic Inspiration";
        mainActions.push_back(action);
        break;
    }
    case CharacterDetails::Classes::Cleric:
    {
        action = "Spellcasting";
        mainActions.push_back(action);
        break;
    }
    case CharacterDetails::Classes::Druid:
    {
        action = "Spellcasting";
        mainActions.push_back(action);
        break;
    }
    case CharacterDetails::Classes::Fighter:
    {
        action = "Second Wind";
        mainActions.push_back(action);
        break;
        break;
    }
    case CharacterDetails::Classes::Monk:
    {
        action = "Unarmed Strike";
        mainActions.push_back(action);
        break;
    }
    case CharacterDetails::Classes::Paladin:
    {
        action = "Divine Sense";
        mainActions.push_back(action);
        action = "Lay on Hands";
        mainActions.push_back(action);
        break;
    }   
    case CharacterDetails::Classes::Rogue:
    {
        action = "Sneak Attack";
        mainActions.push_back(action);
        break;
    }
    case CharacterDetails::Classes::Sorcerer:
    {
        action = "Spellcasting";
        mainActions.push_back(action);
        break;
    }
    case CharacterDetails::Classes::Warlock:
    {
        action = "Spellcasting";
        mainActions.push_back(action);
        break;
    }
    case CharacterDetails::Classes::Wizard:
    {
        action = "Spellcasting";
        mainActions.push_back(action);
        break;
    }
    default:
    {
        break;
    }
    }
    std::cout << "Your character's main actions: " << std::endl;
    for (int i = 0; i < mainActions.size(); i++)
    {
        std::cout << mainActions[i] << std::endl;
    }
    system("PAUSE");
}

void CharacterActions::save(std::ofstream& fout)
{
    fout << '\n' << spells.size();
    for (int i = 0; i < spells.size(); i++)
    {
        fout << '\n' << spells.at(i);
    }
    fout << '\n' << mainActions.size();
    for (int i = 0; i < mainActions.size(); i++)
    {
        fout << '\n' << mainActions.at(i);
    }
}

void CharacterActions::printSpells()
{
    std::cout << "Spells: " << std::endl;
    for (int i = 0; i < spells.size(); i++)
    {
        std::cout << spells.at(i) << '\n';
    }
}

void CharacterActions::printMainActions()
{
    std::cout << "Actions: " << std::endl;
    for (int i = 0; i < mainActions.size(); i++)
    {
        std::cout << mainActions.at(i) << '\n';
    }
}

