#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
    This is the source code of a console-based project that I developed.
    The project simulates the classic Rock–Paper–Scissors game, where the user plays against the computer.
    The main objective of this project is to practice core programming concepts such as
    conditional statements, loops, functions, and basic input/output handling in a console environment.
*/



struct Wresult
{
    int PlayerWin = 0;
    int ComputerWin = 0;
    int Draw = 0;
};

int Number_Of_Rounds()
{ // To Read Number Of Rounds From User
    int number;
    cout << "Enter a Number of Rounds: ";
    cin >> number;

    return number;
}

int Random_Numbers(int from, int to)
{ // To Create a Random Numbers

    int Randomnumber = rand() % (to - from + 1) + from;
    return Randomnumber;
}

string Tabs(int number_of_tabs)
{
    switch (number_of_tabs)
    {
    case 1:
        return "Stone";
        break;
    case 2:
        return "Paper";
        break;
    case 3:
        return "Scissors";
        break;
    }
}

string Check_Round_Results(int number_of_tabs, int computer)
{

    if (number_of_tabs == computer)
    {
        return "No Winner";
    }
    else if (number_of_tabs == 1 && computer == 2 || number_of_tabs == 2 && computer == 3 || number_of_tabs == 3 && computer == 1)
    {

        return "Computer Winner";
    }
    else
    {

        return "player Winner";
    }
}

string CheckWinner(Wresult &result)
{
    if (result.PlayerWin > result.ComputerWin)
    {
        return "Player Win";
    }
    else if (result.PlayerWin < result.ComputerWin)
    {

        return "Computer Win";
    }
    else
    {
        return "No Winner";
    }
}

void ShowGameOverScreen(int WNumber)
{
    cout << "\n\t\t\t----------------------------------------\n";
    cout << "\t\t\t                Game Over                 \n";
    cout << "\t\t\t------------------------------------------\n";
    cout << "\t\t\t[ Game Results ]\n";
    cout << "\t\t\tGame Round : " << WNumber << "\n\n\n";
}

void ShowFinalGameResults(Wresult result)
{
    cout << "\t\tPlayer  won times : " << result.PlayerWin << "\n";
    cout << "\t\tComputer won times : " << result.ComputerWin << "\n";
    cout << "\t\tDraw times : " << result.Draw << "\n";
    cout << "\t\tFinal Winner : " << CheckWinner(result) << "\n";
    cout << "\t\t----------------------------------------\n";
    cout << endl;
}

void PlayRound(Wresult &result)
{
    int NumberOfTabs, Computer;

    cout << "\nYour Choice: [1]: Stone, [2]: Paper, [3]: Scissors ? \n";
    cin >> NumberOfTabs;
    Computer = Random_Numbers(1, 3);

    cout << "\nPlayer Choice : " << Tabs(NumberOfTabs) << endl;
    cout << "Computer Choice : " << Tabs(Computer) << endl;
    cout << "Round Winner : " << Check_Round_Results(NumberOfTabs, Computer);

    if (Check_Round_Results(NumberOfTabs, Computer) == "No Winner")
    {
        system("color 0E");
        result.Draw++;
    }
    else if (Check_Round_Results(NumberOfTabs, Computer) == "Computer Winner")
    {
        cout << "\a";
        system("color 4F");
        result.ComputerWin++;
    }
    else if (Check_Round_Results(NumberOfTabs, Computer) == "player Winner")
    {
        system("color 2F");
        result.PlayerWin++;
    }
    cout << "\n";
}

void StartGame()
{
    Wresult result;
    string PlayAgain;
    short RNumber = Number_Of_Rounds();
    bool GameOn = true;

    do
    {
        for (int i = 0; i < RNumber; i++)
        {
            cout << "\nRound [ " << i + 1 << " ] begins:\n";
            PlayRound(result);
        }
        GameOn = false;
    } while (GameOn == true);

    ShowGameOverScreen(RNumber);
    ShowFinalGameResults(result);

    cout << "\t\tDo you want to play again? Y/N?\n";
    cin >> PlayAgain;
    if (PlayAgain == "Y" ||  "y")
    {
        system("CLS");
        system("color 07");
        StartGame();
    }
    cout << endl;
}

int main()
{

    srand((unsigned)time(NULL));
    StartGame();
    return 0;
}

/*
           _____      _               _____             
         / ____|    | |             |  __ \            
        | (___   __ _| | ___ _ __   | |  | | _____   __
        \___ \ / _` | |/ / | '__|   | |  | |/ _ \ \ / /
        ____) | (_| |   <| | |      | |__| |  __/\ V / 
       |_____/ \__,_|_|\_\_|_|      |_____/ \___| \_/  
 
*/