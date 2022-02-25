#include <iostream>
#include <string>
#include <time.h>

int main()
{
    // Color controls. Unused colors are commented out for now.
    const std::string colorRed("\033[0;31m");
    const std::string colorGreen("\033[1;32m");
    //const std::string colorYellow("\033[1;33m");
    //const std::string colorCyan("\033[0;36m");
    //const std::string colorMagenta("\033[0;35m");
    const std::string colorReset("\033[0m");

    srand (time(NULL));
    std::string playerOne, playerTwo, playerOneCrit = "", playerTwoCrit = "", outputString = "";
    int playerOneRoll = rand() % 20, playerTwoRoll = rand() % 20;
    
    std::cout << "Welcome to the dice rolling game. Enter Player One's name: " << std::endl;
    std::cout << ">> ";
    std::cin >> playerOne;
    std::cout << "Enter Player Two's name: " << std::endl;
    std::cout << ">> ";
    std::cin >> playerTwo;

    //playerOneRoll = 20;//Debug
    //playerTwoRoll = 1;//Debug
    
    if (playerOneRoll == 20) { playerOneCrit = "\n" + playerOne + " rolled a " + colorGreen + "Critical Success!\n" + colorReset; }
    else if (playerOneRoll == 1) { playerOneCrit = "\n" + playerOne + " rolled a " + colorRed + "Critical Failure!\n" + colorReset; }
    if (playerTwoRoll == 20) { playerTwoCrit = "\n" + playerTwo + " rolled a " + colorGreen + "Critical Success!\n" + colorReset; }
    else if (playerTwoRoll == 1) { playerTwoCrit = "\n" + playerTwo + " rolled a " + colorRed + "Critical Failure!\n" + colorReset; }
    
    if (playerOneRoll > playerTwoRoll) {
        outputString += playerOne + " rolled a " + std::to_string(playerOneRoll) + ", which beat " + playerTwo + "'s roll of " + std::to_string(playerTwoRoll) + ".\n";
    } else if (playerOneRoll < playerTwoRoll){
        outputString += playerTwo + " rolled a " + std::to_string(playerTwoRoll) + ", which beat " + playerOne + "'s roll of " + std::to_string(playerOneRoll) + ".\n";
    } else {
        outputString += playerOne + " and " + playerTwo + " both rolled " + std::to_string(playerOneRoll) + ". They have tied!\n";
    }

    outputString += playerOneCrit;
    outputString += playerTwoCrit;
    
    std::cout << outputString;
    
    //std::cout << playerOne << " rolled " << playerOneRoll << std::endl;//Debug
    //std::cout << playerTwo << " rolled " << playerTwoRoll << std::endl;//Debug
}
