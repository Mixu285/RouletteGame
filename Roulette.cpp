#include <iostream>
#include <limits>

struct
{
    int chamberSize = 6;
    int playerHp = 1;
    int enemyHp = 1;
    int enemyNum = 1;
} options;


int GetRandomNum()
{
    return rand() % options.chamberSize;
}

void OpenOptions()
{
    std::cout << "Options" << std::endl;
    std::cout << "1.Chamber size" << std::endl;
    std::cout << "2.Player HP" << std::endl;
    std::cout << "3.Enemy HP" << std::endl;
    std::cout << "4.Number of enemies" << std::endl;
    std::cout << "5.Back" << std::endl;
    
}

void ClearScreen()
{
    std::cout << "\033[2J\033[1;1H"; //ANSI escape code, for clearing console
}

void StartGame()
{
    while(true)
    {
        int menuChoice;
        bool exit = false;
        std::cout << "Roulette game!" << std::endl;
        std::cout << "" << std::endl;
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
            std::cout << "Play!" << std::endl;
            ClearScreen();
            break;
        case 2:
            std::cout << "Options!" << std::endl;
            ClearScreen();
            OpenOptions();
            break;
        case 3:
            std::cout << "HS" << std::endl;
            ClearScreen();
            break;
        case 4:
            std::cout << "Exit" << std::endl;
            ClearScreen();
            exit = true;
            break;
        default:
            ClearScreen();
            break;
            
        }
        if(exit)
        {
            break;
        }
    }
}

int main()
{
    StartGame();
    return 0;
}

