#include <iostream>
#include <limits>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>

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
        std::cout << "Current options:" << std::endl;
        std::cout << "Chamber size: " << options.chamberSize << std::endl;
        std::cout << "Player HP: " << options.playerHp << std::endl;
        std::cout << "Enemy HP: " << options.enemyHp << std::endl;
        std::cout << "Number of enemies: " << options.enemyNum << std::endl;
        std::cout << std::endl;
        std::cout << "Choose options:" << std::endl;
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

int GetRandomBulletInChamber()
{
    std::srand(std::time(nullptr));
    return std::rand() % options.chamberSize + 1;
}

void PlayGame()
{
    bool exit = false;
    int roundNum = 1;
    int currentPlayer = 1;
    int chamberPosition = 1;
    int bulletPosition = GetRandomBulletInChamber();
    int playerHp = options.playerHp;
    int points = 0;
    std::vector<int> enemiesHp(options.enemyNum, options.enemyHp);

    while(!exit)
    {
        int gameChoice;
        std::cout << "Round " << roundNum << "!" <<std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        ClearScreen();
        std::cout << "Your points: " << points << std::endl;
        std::cout << "Your HP: " << playerHp << std::endl;
        //std::cout << "Your Highscore: " << points << std::endl; //TODO HIGHSCORE
        std::cout << "Total players: " << options.enemyNum << std::endl;
        if(currentPlayer == 1)
        {
            std::cout << "Current player: " << "you (1)" << std::endl;
            std::cout << "Choose option:" << std::endl;
            std::cout << "1. Shoot at yourself"<< std::endl;
            std::cout << "2. Shoot at opponent"<< std::endl;
            std::cout << "3. Spin chamber"<< std::endl;
            std::cout << "4. Give up (go back to menu)"<< std::endl;
            std::cin >> gameChoice;
            if(std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                ClearScreen();
                continue;
            }
            switch(gameChoice)
            {
                case 1:
                    ClearScreen();
                    std::cout << "You are shooting at yourself!"<< std::endl;
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    if(chamberPosition == bulletPosition)
                    {
                        std::cout << "You shot yourself!"<< std::endl;
                        playerHp--;
                        if(playerHp <= 0)
                        {
                            std::cout << "You are dead!"<< std::endl;
                            std::cout << "Press enter to go back to menu"<< std::endl;
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cin.get();
                            exit = true;
                        }
                        else
                        {
                            std::cout << "You lose 1HP!"<< std::endl;
                            std::cout << "Current HP = " << playerHp << std::endl;
                            std::this_thread::sleep_for(std::chrono::seconds(2));
                        }
                    }
                    else
                    {
                        std::cout << "You are safe!"<< std::endl;
                        std::cout << "For now..."<< std::endl;
                        std::cout << "Get get +1 point"<< std::endl;
                        points++;
                        std::cout << "Current points: " << points << std::endl;
                        std::this_thread::sleep_for(std::chrono::seconds(2));
                    }
                    chamberPosition++;
                    roundNum++;
                    ClearScreen();
                    break;
                case 4:
                    ClearScreen();
                    exit = true;
                default:
                    ClearScreen();
                    break;
            }
        }
        else
        {
            std::cout << "Current player: " << options.enemyNum << std::endl;
        }


    }
}


void MainMenu()
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
            PlayGame();
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
    MainMenu();
    return 0;
}

