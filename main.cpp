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
*********************************************************************/

#include <iostream> // inclusion required for cin and cout
#include <iomanip>
#include <cctype>
#include <cmath>
#include <string>
#include <ctime> //enables use of time() function... ZyBooks 2.19.3
#include <limits>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> questions; // 2D vector to store question history
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
    cout << "  Welcome to the World of Math Wizards           " <<endl;
    cout << "Maths Fun Facts" <<endl;
    cout << "* From 0 to 1000, the only number that has the letter 'a' in it is one thousand." <<endl;
    cout << "* Every odd number has an 'e' in it." <<endl;
    cout << "* It is always exciting to discover cool ways in which you can use or observe Math in the world." <<endl;
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
            if (leftNum < rightNum)
                swap(leftNum, rightNum);
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

        vector<int> row = {mathLevel, leftNum, mathSymbol, rightNum, correctAns};

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
                row.push_back(i); // attempts used
                totalCorrect++;
                break;
            } else {
                if (i == MAX_ATTEMPTS) {
                    cout << " Sorry you are out of attempts" << endl;
                    cout << " The correct answer was: " << correctAns << endl;
                    row.push_back(0); // error marker
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

        questions.push_back(row);
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
      while (true)
      {
          cout << "\nDo you want to continue? (y = yes | n = no): ";
          getline(cin, userInput);

          for (char &c : userInput) c = tolower(c);

          if (userInput == "y" || userInput == "yes") {
              break;
          } else if (userInput == "n" || userInput == "no") {
              // Display summary
              cout << "\n=================== QUIZ SUMMARY ===================\n";
              cout << left << setw(10) << "Level"
                   << setw(10) << "Left"
                   << setw(10) << "Op"
                   << setw(10) << "Right"
                   << setw(10) << "Answer"
                   << setw(10) << "Result" << endl;
              cout << "----------------------------------------------------\n";

              int correctAnswers = 0;
              int incorrectAnswers = 0;

              for (const auto& row : questions) {
                 int level = row[0];
                  int l = row[1];
                  int op = row[2];
                  int r = row[3];
                  int ans = row[4];
                  int attempt = row[5];

                  cout << left << setw(10) << level
                       << setw(10) << l
                       << setw(10) << op
                       << setw(10) << r
                       << setw(10) << ans;

                  if (attempt != 0) {
                      cout << setw(10) << (attempt + " try");
                      correctAnswers++;
                  } else {
                      cout << setw(10) << "Incorrect";
                      incorrectAnswers++;
                  }

                  cout << endl;
              }

              int total = correctAnswers + incorrectAnswers;
              int average = (total > 0) ? (correctAnswers * 100 / total) : 0;

              cout << "\n----------------------------------------------------\n";
              cout << "Total Questions: " << total << endl;
              cout << "Correct Answers: " << correctAnswers << endl;
              cout << "Incorrect Answers: " << incorrectAnswers << endl;
              cout << "Score:           " << average << "%\n";
              cout << "====================================================\n";
              cout << "Thanks for playing, " << userName << "! Come back soon.\n";
              return 0;
          } else {
              cout << "Invalid input. Please enter 'y' or 'n'.\n";
          }
      }
      } // end of the do while loop
    while (userInput == "yes" || userInput == "y");


        return 0;

}
