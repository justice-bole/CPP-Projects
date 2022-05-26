#include <iostream>
#include <ctime> //used to get system time to seed rand

void PrintIntroduction(int Difficulty)
{
    std::cout <<"                  :o-       /o.                         \n";
    std::cout <<"                 :MMMh-  `+NMMm`                        \n";
    std::cout <<"                `mMMMMMNmMMMMMMs                        \n";
    std::cout <<"                +MMMMMMMMMMMMMMM.                       \n";
    std::cout <<"                mMMMMMMMMMMMMMMMs                       \n";
    std::cout <<"               :MMMMMMMMMMMMMMMMN`                      \n";
    std::cout <<"               yMMMMMMMMMMMMMMMMM+                      \n";
    std::cout <<"               dNMMMMMMMMMMMMMMMNs                      \n";
    std::cout <<"                  `.--:::::::-.`                        \n";
    std::cout <<"             `.                   `.                    \n";
    std::cout <<"      .:+shmNMMMmhyso++////++osydNMMMNdys+:.            \n";
    std::cout <<" `/ydMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNds:        \n";
    std::cout <<" omMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMd-       \n";
    std::cout <<"   .:+shdNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNmdyo/-`         \n";
    std::cout <<"       `:-.---:/++oosssyyyysssoo+//:-..-:/:             \n";
    std::cout <<"     -yMMMMMN..Nmhhyyyys+oyyyyyhdmh  hMMMMMNs:          \n";
    std::cout <<"   /dMMMMMMMMm./mMMMMMy`  :mMMMMMh. `NMMMMMMMMms-       \n";
    std::cout <<"`+mMMMMMMMMMMMN- `-:-`      .::-`  /dMMMMMMMMMMMMm+`    \n";
    std::cout <<"   `-:+oydNMMMMMo               `oNMMMMMMmhyo/:-.`      \n";
    std::cout <<"           `/mMMMd-           `sNMMMMd/-                \n";
    std::cout <<"          -yMMMMMMMs`        +NMMMMMMMNho-              \n";
    std::cout <<"         /hNMMMMMMMMNs.    .dMMMMMMMMdyo:-`             \n";
    std::cout <<"            `:sdMMMMMMMh: -NMMMMMdo:`                   \n";
    std::cout <<"                `:ohMMMMs-NMMMm+.                       \n";
    std::cout <<"                     :oh.mMMh:                          \n";
    std::cout <<"                        /Mm:                            \n";
    std::cout <<"                        sy`                             \n";
    std::cout <<"                        -                               \n";
    std::cout << "You are a secret agent breaking into a level " << Difficulty << " secure server room\n";
    std::cout << "You need to enter the correct codes to continue...\n\n";
}

bool PlayGame(int Difficulty)
{
    //PrintIntroduction(Difficulty);

   // declare 3 no. code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeB + CodeA + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // print sum and product to terminal
    std::cout << "> There are three numbers in the code\n";
    std::cout << "> The codes add up to: " << CodeSum;
    std::cout << "\n> The codes multiply to give: " << CodeProduct << std::endl;

    //Gets 3 digit code from player
    int GuessA, GuessB, GuessC;
    std::cout << "\nEnter the three digit code: ";
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Checks if player code is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nAccess Granted! But there are still more codes to crack!\n";
        return true;
    }
    else
    {
        std::cout << "\nAccess Denied! You'll have to try again.\n";
        return false;
    }
}

int main()
{
    srand(time(NULL)); //creates new random sequence based on the time of day
    int LevelDifficulty = 1;
    int const MaxLevel = 5;

    while (LevelDifficulty <= MaxLevel) // loop game until all levels are completed
{
    bool bLevelComplete = PlayGame(LevelDifficulty);
    std::cin.clear(); //clears any errors
    std::cin.ignore(); //discards the buffer

    if (bLevelComplete)
    {
        ++LevelDifficulty;
    }
    
}    
    std::cout<<"\nYou did it! You cracked every code!\n";
    return 0;
}