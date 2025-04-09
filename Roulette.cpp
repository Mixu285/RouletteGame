#include <iostream>
#include <limits>
#include <fstream>
#include <string>

struct
{
    int chamberSize = 6;
    int playerHp = 1;
    int enemyHp = 1;
    int enemyNum = 1;
} options;

void ReadSettingsFromFile()
{
    std::string text;
    std::ifstream optionsFile("options.txt");
    if(optionsFile.good())
    {
        optionsFile >> options.chamberSize;
        optionsFile >> options.playerHp;
        optionsFile >> options.enemyHp;
        optionsFile >> options.enemyNum;
    }
    optionsFile.close();
}

int GetRandomNum()
{
    return rand() % options.chamberSize;
}

void ClearScreen()
{
    std::cout << "\033[2J\033[1;1H"; //ANSI escape code, for clearing console
}

void OpenOptions()
{
    bool exit = false;
    while(!exit)
    {
        int menuChoice;
        std::cout << "Current options" << std::endl;
        std::cout << "Chamber size: " << options.chamberSize << std::endl;
        std::cout << "Player HP: " << options.playerHp << std::endl;
        std::cout << "Enemy HP: " << options.enemyHp << std::endl;
        std::cout << "Number of enemies: " << options.enemyNum << std::endl;
        std::cout << std::endl;
        std::cout << "Choose options" << std::endl;
        std::cout << "1.Chamber size" << std::endl;
        std::cout << "2.Player HP" << std::endl;
        std::cout << "3.Enemy HP" << std::endl;
        std::cout << "4.Number of enemies" << std::endl;
        std::cout << "5.Back" << std::endl;
        std::cin >> menuChoice;
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            ClearScreen();
            continue;
        }
        int input;
        switch (menuChoice)
        {
        case 1:
            ClearScreen();
            std::cout << "Type chamber size:" << std::endl;
            std::cin >> input;
            if(std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                ClearScreen();
                continue;
            }
            options.chamberSize = input;
            ClearScreen();
            break;
        case 2:
            ClearScreen();
            std::cout << "Type player HP:" << std::endl;
            std::cin >> input;
            if(std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                ClearScreen();
                continue;
            }
            options.playerHp = input;
            ClearScreen();
            break;
        case 3:
            ClearScreen();
            std::cout << "Type enemy HP:" << std::endl;
            std::cin >> input;
            if(std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                ClearScreen();
                continue;
            }
            options.enemyHp = input;
            ClearScreen();
            break;
        case 4:
            ClearScreen();
            std::cout << "Type number of enemies:" << std::endl;
            std::cin >> input;
            if(std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                ClearScreen();
                continue;
            }
            options.enemyNum = input;
            ClearScreen();
            break;
        case 5:
            ClearScreen();
            
            exit = true;
        default:
            ClearScreen();
            break;
        }
        std::ofstream saveFile("options.txt");
        saveFile << options.chamberSize << "\n" << options.playerHp << "\n" << options.enemyHp << "\n" << options.enemyNum;
        saveFile.close();
    }
}

void StartGame()
{
    bool exit = false;
    while(!exit)
    {
        int menuChoice;
        std::cout << "Roulette game!" << std::endl;
        std::cout << std::endl;
        std::cout << "Type number to choose:" << std::endl;
        std::cout << "1. Play" << std::endl;
        std::cout << "2. Options" << std::endl;
        std::cout << "3. Highscores" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cin >> menuChoice;
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            ClearScreen();
            continue;
        }
        switch (menuChoice)
        {
        case 1:
            ClearScreen();
            break;
        case 2:
            ClearScreen();
            OpenOptions();
            break;
        case 3:
            ClearScreen();
            break;
        case 4:
            ClearScreen();
            exit = true;
            break;
        default:
            ClearScreen();
            break;
        }
    }
}

int main()
{
    ReadSettingsFromFile();
    StartGame();
    return 0;
}

