/********************************************************************
Program Version: MathTutorV3
Programmers....: Philipine Andjawo
Section........: Section 3
Date...........: 2025.10.15
GitHub Repo: https://github.com/Philipine26/MathVersion3
Description: The Math Tutor program version 3 is an ameliorate code of the version 2.
The program executed:
-Gets the user's full name using a getline
-Generates random numbers and math types
-Displays the question to the user and asks for an answer
-Give 3 chances to the user to respond to the question
-Ask the user if he is willing to continue
-Level the user up if the count of correct answer is 3. if not leveling him down
-Handling wrong answer error
-Displays whether the user's answer is the correct answer for the math question if he got the answer wrong
*********************************************************************/

#include <iostream> // inclusion required for cin and cout
#include <iomanip>
#include <cctype>
#include <cmath>
#include <string>
#include <ctime> //enables use of time() function... ZyBooks 2.19.3
#include <limits>

using namespace std;

int main() {
    int leftNum = 0;
    int rightNum = 0;
    int mathType = 0; //1,2,3,4
    char mathSymbol = '?'; //+,-,*,/
    int correctAns; //correct answer variable
    int userAns = 0; // user answer variable
    int temp = 0; //
    int totalCorrect = 0;
    int totalIncorrect = 0;
    int mathLevel = 1;
    enum MathType { MT_ADD = 1, MT_SUB = 2, MT_MUL = 3, MT_DIV = 4 };
    MathType mathtype = MT_ADD; // store the mathtype

    string userInput = "y";
    string userName = "unknown";
    const int MAX_ATTEMPTS = 3;
    const int LEVEL_RANGE_CHANGE = 10;
    int currentRange = LEVEL_RANGE_CHANGE;

    srand(time(0)); // Allows for a unique seed for each program run (ZyBooks2.19.3)
    cout << "***********************************************************************" << endl;
    cout << "oooo     oooo            o8   oooo             ooooooooooo              o8                             ooooo  oooo  ooooooo" << endl;
    cout << "8888o   888   ooooooo o888oo  888ooooo        88  888  88 oooo  oooo o888oo ooooooo  oo oooooo         888    88 o88    888o" << endl;
    cout << "88 888o8 88   ooooo888 888    888   888           888      888   888  888 888     888 888    888        888  88      88888o"  << endl;
    cout << "88  888  88 888    888 888    888   888           888      888   888  888 888     888 888                88888   88o    o888" << endl;
    cout << "o88o  8  o88o 88ooo88 8o 888o o888o o888o         o888o      888o88 8o  888o 88ooo88  o888o                888      88ooo88"  << endl;
    cout << "***********************************************************************" << endl;
    cout << " Welcome to MathTutorV3!" << endl;
    cout << "***********************************************************************" << endl;
    cout << " Parallel lines have so much in common. It's a shame they'll never meet. " << endl;
    cout << " I'd tell you a joke about infinity, but it would go on forever." << endl;
    cout << " What do you call a number that can't keep still? A roamin' numeral!" << endl;
    cout << "***********************************************************************" << endl;
    cout << endl;

    cout << "Enter your first and last name: ";
    getline(cin, userName); // Gets the user's full name
    cout << endl;
    cout << "Hi, " << userName << " can you answer this question ?";
    cout << endl;

    do {
        leftNum = (rand() % currentRange) + 1; // Generates a random leftNum between 1 to the current range
        rightNum = (rand() % currentRange) + 1; // Generates a random rightNum between 1 to the current range
        mathType = static_cast<MathType>(rand() % 4 + 1); // Generates a random mathType between 1-4

        switch (mathType) // Add the switch statement to calculate per case the different operation
        {
            case 1:
                mathSymbol = '+';
                correctAns = leftNum + rightNum;
                break;
            case 2:
                mathSymbol = '-';
                if (leftNum < rightNum) {
                    temp = leftNum;
                    leftNum = rightNum;
                    rightNum = temp;
                }
                correctAns = leftNum - rightNum;
                break;
            case 3:
                mathSymbol = '*';
                correctAns = leftNum * rightNum;
                break;
            case 4:
                mathSymbol = '/';
                if (rightNum == 0) {
                    rightNum = (rand() % currentRange) + 1;
                }
                correctAns = leftNum / rightNum;
                break;
            default:
                cout << "Error! " << mathType << " is not a valid input!" << endl;
                cout << "-1" << endl;
                cout << "Please contact Philipine to fix this error" << endl;
                return -1;
        } // End of switch statement

        for (int i = 1; i <= MAX_ATTEMPTS; i++) {
            cout << "[Level #" << mathLevel << "] " << userName
                    << " What is " << leftNum << " " << mathSymbol << " " << rightNum << " = ";

            //Loop until the user enters numeric data
            while (!(cin >> userAns)) {
                cin.clear(); // clear the cin error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the max input, up to the '/n'
                cout << "Invalid input!" << endl;
                cout << "Please enter a number: ";
            } // end of get userAnswer while loop

            //loop to verify if the answer is correct
            if (userAns == correctAns) {
                cout << "Such a genuis ! Your answer is correct" << endl;
                totalCorrect++;
                break;
            } else {
                if (i == MAX_ATTEMPTS) {
                    cout << " Sorry you are out of attempts" << endl;
                    cout << " The correct answer was: " << correctAns << endl;
                    totalIncorrect++;
                    break;
                } else
                    {
                        cout << " Well, that was incorrect! " << endl;
                        cout << " Fortunately, you still have " << MAX_ATTEMPTS -i << " attempts." << endl;
                        totalIncorrect++;
                    }
                } //end of if loop to verify the user answer
            } //end of the for loop


        if (totalCorrect == 3) {
            cout << "Congratulation! You have level up!" << endl;
            mathLevel++;
            totalCorrect = 0;
            totalIncorrect = 0;
            currentRange += LEVEL_RANGE_CHANGE;
            cout << " You are on level #" << mathLevel << "!" << endl;
            cout << "Your new range of play is: " << currentRange << endl;
        } // end of if loop
        else if (totalIncorrect == 3 && mathLevel > 1) {
            mathLevel--;
            totalCorrect = 0;
            totalIncorrect = 0;
            currentRange -= LEVEL_RANGE_CHANGE;
            cout << " You are on level #" << mathLevel << "!" << endl;
            cout << "Your new range of play is: " << currentRange << endl;
        } // end of else if loop

        getline(cin, userInput); //  clean the newline from the input buffer

        // validate y, yes, no, n
        while (true) {
            cout << " Do you want to continue ( y=yes | n=no)";
            getline(cin, userInput); // get the user Input

            for (int i = 0; i < userInput.size(); i++) {
                userInput.at(i) = tolower(userInput.at(i)); // lower the user input
            } // end of for loop
            if (userInput == "y" || userInput == "yes" || userInput == "n" || userInput == "no") {
                if (userInput == "n" || userInput == "no") {
                    cout << "End of game! " << endl;
                    cout << "Stay tuned for a new version! ";
                }
                break;
            } else {
                cout << "Invalid input, please try again..." << endl;
                cout << endl;
            } // end of if statement for the user input validation
        } // end of the inner while to validate y, yes, no, n
    } // end of the do while loop
    while (userInput == "yes" || userInput == "y");

}
