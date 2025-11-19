/********************************************************************
Program Version: MathTutorV3
Programmers....: Philipine Andjawo, Mujeeb Adewuyi
Section........: Section 2
Date...........: 2025.20.15
GitHub Repo: https://github.com/Philipine26/MathTutorV4.git
Description: The Math Tutor program version 4 is an ameliorate code of the version 3.
The program executed:
-Gets the user's full name using a getline
-Generates random numbers and math types
-Displays the question to the user and asks for an answer
-Give 3 chances to the user to respond to the question
-Ask the user if he is willing to continue
-Level the user up if the count of correct answer is 3. if not leveling him down
-Handling wrong answer error
-Displays whether the user's answer is the correct answer for the math question if he got the answer wrong
-Generate a summary table for the user after completing the  questions and decided to leave by answering N or NO.
-Gives user amount of questions answered correctly and incorrectly, with number of questions asked, and also the percentage over 100.
*********************************************************************/

#include <iostream> // inclusion required for cin and cout
#include <iomanip> // inclusion required for setw and other formatting functions
#include <cctype> // inclusion required for tolower function
#include <string> // inclusion required for string operations
#include <ctime> // enables use of time() function... ZyBooks 2.19.3
#include <limits> // inclusion required for numeric_limits
#include <vector> // inclusion required for vector container


using namespace std;  // Allows usage of standard library names without the std:: prefix

int main() {
    vector<vector<int> > questions; // 2D vector to store question history
    int leftNum = 0; // Left operand in math questions
    int rightNum = 0;  // Right operand in math question
    int mathType = 0; // Holds type of math operation (1-4)
    char mathSymbol = '?'; //+,-,*,/
    int correctAns; //correct answer variable
    int userAns = 0; // user answer variable
    int temp = 0;
    int totalCorrect = 0;  // Counts total correct answers
    int totalIncorrect = 0;  // Counts total incorrect answers
    int incorrectAns = 0;
    int mathLevel = 1;  // Tracks current math difficulty level
    int attempts = 0; // Tracks current attempt number for a question
    int total = 0; // Sum accumulator for various purposes
    int average = 0; // Stores calculated average
    enum MathType { MT_ADD = 1, MT_SUB = 2, MT_MUL = 3, MT_DIV = 4 };
    MathType mathtype = MT_ADD; // store the mathtype

    string userInput = "y";  // Stores user input for continuation
    string userName = "unknown"; // Stores user's name
    const int MAX_ATTEMPTS = 3; // Maximum allowed attempts for each question
    const int LEVEL_RANGE_CHANGE = 10;  // Value by which range increases per level
    int currentRange = LEVEL_RANGE_CHANGE; // Stores current range for random number generation

    srand(time(0)); // Allows for a unique seed for each program run (ZyBooks2.19.3)
    cout << "#     #                        #######                               #     # #      " << endl;
    cout << "##   ##   ##   ##### #    #       #    #    # #####  ####  #####     #     # #    # " << endl;
    cout << "# # # #  #  #    #   #    #       #    #    #   #   #    # #    #    #     # #    # " << endl;
    cout << "#  #  # #    #   #   ######       #    #    #   #   #    # #    #    #     # #    # " << endl;
    cout << "#     # ######   #   #    #       #    #    #   #   #    # #####      #   #  #######" << endl;
    cout << "#     # #    #   #   #    #       #    #    #   #   #    # #   #       # #        # " << endl;
    cout << "#     # #    #   #   #    #       #     ####    #    ####  #    #       #         #  " << endl;
    cout << "***********************************************************************" << endl;
    cout << "                  Welcome to MathTutorV4!" << endl;
    cout << "***********************************************************************" << endl;
    cout << "  Welcome to the World of Math Wizards           " << endl;
    cout << "Maths Fun Facts" << endl;
    cout << "* From 0 to 1000, the only number that has the letter 'a' in it is one thousand." << endl;
    cout << "* Every odd number has an 'e' in it." << endl;
    cout << "* It is always exciting to discover cool ways in which you can use or observe Math in the world." << endl;
    cout << "***********************************************************************" << endl;
    cout << endl;

    cout << "Enter your first and last name: ";
    getline(cin, userName); // Gets the user's full name
    cout << endl;
    cout << "Hi, " << userName << "Let's test your math skills!";
    cout << endl;

    do {
        leftNum = (rand() % currentRange) + 1; // Generates a random leftNum between 1 to the current range
        rightNum = (rand() % currentRange) + 1; // Generates a random rightNum between 1 to the current range
        mathType = static_cast<MathType>(rand() % 4 + 1); // Generates a random mathType between 1-4

        switch (mathType) // Add the switch statement to calculate per case the different operation
        {
            case 1:
                mathSymbol = '+';
                correctAns = leftNum + rightNum; // Add the two numbers
                break;

            case 2:
                mathSymbol = '-';
                if (leftNum < rightNum)
                    swap(leftNum, rightNum);
                correctAns = leftNum - rightNum; // Substract the two numbers when the first one is positive
                break;

            case 3:
                mathSymbol = '*';
                correctAns = leftNum * rightNum; // Multiply the two numbers
                break;

            case 4:
                mathSymbol = '/';
                if (rightNum == 0) {
                    rightNum = (rand() % currentRange) + 1;
                }
                correctAns = leftNum / rightNum; // Divide the two numbers
                break;

            default:
                cout << "Error! " << mathType << " is not a valid input!" << endl;
                cout << "-1" << endl;
                cout << "Please contact Philipine to fix this error" << endl;
                return -1;
        } // End of switch statement

        vector<int> row = {mathLevel, leftNum, mathSymbol, rightNum, correctAns}; // create the first vector

        for (int i = 1; i <= MAX_ATTEMPTS; i++) {
            cout << "[Level #" << mathLevel << "] " << userName
                    << " What is " << leftNum << " " << mathSymbol << " " << rightNum << " = "; // Ask the user a question

            //Loop until the user enters numeric data
            while (!(cin >> userAns)) {
                cin.clear(); // clear the cin error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore the max input, up to the '/n'
                cout << "Invalid input!" << endl;
                cout << "Please enter a number: ";
            } // end of get userAnswer while loop

            //loop to verify if the answer is correct
            if (userAns == correctAns) {
                cout << "congratulations!!!! Your answer is correct" << endl;
                row.push_back(i); // attempts used
                totalCorrect++; //Increment the total Correct
                break;
            } else {
                if (i == MAX_ATTEMPTS) {
                    cout << " Sorry you are out of attempts" << endl;
                    cout << " The correct answer was: " << correctAns << endl;
                    row.push_back(0); // error marker
                    totalIncorrect++; // Increment the total Incorrect
                    break;
                } else {
                    cout << " Well, that was incorrect! " << endl;
                    cout << " Fortunately, you still have " << MAX_ATTEMPTS - i << " attempts." << endl;
                    totalIncorrect++;
                }
            } //end of if loop to verify the user answer
        } //end of the for loop

        questions.push_back(row); // Add the row vector as attempt in the questions vector.
        if (totalCorrect == 3) {
            cout << "Congratulation! You have level up!" << endl;
            mathLevel++; // Increment the mathLevel when the user have answer 3 correct answers.
            totalCorrect = 0; // reinitialize totalCorrect
            totalIncorrect = 0; // reinitialize totalIncorrect
            currentRange += LEVEL_RANGE_CHANGE; // Add more to currentRange
            cout << " You are on level #" << mathLevel << "!" << endl;
            cout << "Your new range of play is: " << currentRange << endl;
        } // end of if loop
        else if (totalIncorrect == 3 && mathLevel > 1) {
            mathLevel--; // Decrement the mathLevel when the user have answer 3 incorrect answers,
            //and the level is higher than 1.
            totalCorrect = 0; // reinitialize totalCorrect
            totalIncorrect = 0; // reinitialize totalIncorrect
            currentRange -= LEVEL_RANGE_CHANGE; // substract more to currentRange
            cout << " You are on level #" << mathLevel << "!" << endl;
            cout << "Your new range of play is: " << currentRange << endl;
        } // end of else if loop

        getline(cin, userInput); //  clean the newline from the input buffer

        // validate y, yes, no, n
        while (true) {
            cout << "\nDo you want to continue? (y = yes | n = no): ";
            getline(cin, userInput);

            for (char &c: userInput) c = tolower(c); // lowercase the user input

            if (userInput == "y" || userInput == "yes" || userInput == "n" || userInput == "no") { // Compare the user input
                break;
            } else {
                cout << "Invalid input. Please enter 'y' or 'n'.\n"; // Handle input mistakes
            } //end of else
            //end of for
        }
    } // end of the do while loop
    while (userInput == "yes" || userInput == "y");

    //summary
    cout << "===================================" << endl;
    cout << "          " << "Overall Summary" << endl;
    cout << "===================================" << endl;
    cout << "Level" << "       Question" << "       Attempts" << endl;
    cout << "-----     ------------    ----------" << endl;

    // outputs the level, questions, and attempts
    for (int i = 0; i < questions.size(); i++) {
        mathLevel = questions.at(i).at(0);
        leftNum = questions.at(i).at(1);
        mathSymbol = static_cast<char>(questions.at(i).at(2)); // converts the stored int into a char
        rightNum = questions.at(i).at(3);
        correctAns = questions.at(i).at(4);
        attempts = questions.at(i).at(5);

        cout << " " << setw(2) << right << mathLevel << "    " << setw(3) << right << leftNum
                << " " << mathSymbol << " " << setw(3) << left << rightNum << " = " << setw(3) << right
                << correctAns << "    ";

        // output number of attempts
        if (attempts != 0) {
            cout << "    " << attempts << endl;
            totalCorrect++;
        }
        // output incorrect if 0 is stored
        else {
            cout << "Incorrect" << endl;
            totalIncorrect++;
        }
    }

    //output totals
    cout << "Total Questions: " << setw(3) << right << questions.size() << endl;
    cout << "Total Correct  : " << setw(3) << right << totalCorrect << endl;
    cout << "Total Incorrect: " << setw(3) << right << totalIncorrect << endl;
    cout << "Average Correct: " << setw(3) << right << (totalCorrect * 100) / questions.size() << "%" << endl;
    cout << "Thanks for playing, " << userName << "! Come back soon.\n";
    return 0;
}
