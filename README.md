# Math Tutor V4

<b>Table of Content</b>

- [Summary](#summary)
- [Console Output Example](#console-output-example)
- [Maintainers](#maintainers)`

## Summary

Program Version: MathTutorV3 Programmers....

Philipine Andjawo, Mujeeb Adewuyi

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

-Generate a summary table for the user after completing the questions and decided to leave by answering N or NO.

-Gives user amount of questions answered correctly and incorrectly, with number of questions asked, and also the
percentage over 100.

## Console Correct Output Example

```
#     #                        #######                               #     # #
##   ##   ##   ##### #    #       #    #    # #####  ####  #####     #     # #    #
# # # #  #  #    #   #    #       #    #    #   #   #    # #    #    #     # #    #
#  #  # #    #   #   ######       #    #    #   #   #    # #    #    #     # #    #
#     # ######   #   #    #       #    #    #   #   #    # #####      #   #  #######
#     # #    #   #   #    #       #    #    #   #   #    # #   #       # #        #
#     # #    #   #   #    #       #     ####    #    ####  #    #       #         #
***********************************************************************
                  Welcome to MathTutorV4!
***********************************************************************
  Welcome to the World of Math Wizards
Maths Fun Facts
* From 0 to 1000, the only number that has the letter 'a' in it is one thousand.
* Every odd number has an 'e' in it.
* It is always exciting to discover cool ways in which you can use or observe Math in the world.
***********************************************************************

Enter your first and last name:mujeeb phill


Hi, mujeeb phillLet's test your math skills!
[Level #1] mujeeb phill What is 4 + 3 =7

congratulations!!!! Your answer is correct

Do you want to continue? (y = yes | n = no):y

[Level #1] mujeeb phill What is 1 / 1 =0

 Well, that was incorrect!
 Fortunately, you still have 2 attempts.
[Level #1] mujeeb phill What is 1 / 1 =1

congratulations!!!! Your answer is correct

Do you want to continue? (y = yes | n = no):y

[Level #1] mujeeb phill What is 1 * 5 =5

congratulations!!!! Your answer is correct
Congratulation! You have level up!
 You are on level #2!
Your new range of play is: 20

Do you want to continue? (y = yes | n = no):y

[Level #2] mujeeb phill What is 16 * 12 =5656

 Well, that was incorrect!
 Fortunately, you still have 2 attempts.
[Level #2] mujeeb phill What is 16 * 12 =44

 Well, that was incorrect!
 Fortunately, you still have 1 attempts.
[Level #2] mujeeb phill What is 16 * 12 =343

 Sorry you are out of attempts
 The correct answer was: 192
 You are on level #1!
Your new range of play is: 10

Do you want to continue? (y = yes | n = no):y

[Level #1] mujeeb phill What is 6 + 1 =7

congratulations!!!! Your answer is correct

Do you want to continue? (y = yes | n = no):y

[Level #1] mujeeb phill What is 5 / 10 =0

congratulations!!!! Your answer is correct

Do you want to continue? (y = yes | n = no):y

[Level #1] mujeeb phill What is 10 + 9 =5

 Well, that was incorrect!
 Fortunately, you still have 2 attempts.
[Level #1] mujeeb phill What is 10 + 9 =3

 Well, that was incorrect!
 Fortunately, you still have 1 attempts.
[Level #1] mujeeb phill What is 10 + 9 =19

congratulations!!!! Your answer is correct
Congratulation! You have level up!
 You are on level #2!
Your new range of play is: 20

Do you want to continue? (y = yes | n = no):n


=================== QUIZ SUMMARY ===================
Level     | Question |       Attempts
----------------------------------------------------
  1        4 + 3 = 7         1
  1        1 / 1 = 1         2
  1        1 * 5 = 5         1
  2       16 * 12 = 192   Incorrect
  1        6 + 1 = 7         1
  1        5 / 10 = 0        1
  1       10 + 9 = 19        3

----------------------------------------------------
Total Questions: 7
Correct Answers: 6
Incorrect Answers: 1
Score: 85%
====================================================
Thanks for playing, mujeeb phill! Come back soon.

Process finished with exit code 0
```

## Console Errors Output Example

```
#     #                        #######                               #     # #
##   ##   ##   ##### #    #       #    #    # #####  ####  #####     #     # #    #
# # # #  #  #    #   #    #       #    #    #   #   #    # #    #    #     # #    #
#  #  # #    #   #   ######       #    #    #   #   #    # #    #    #     # #    #
#     # ######   #   #    #       #    #    #   #   #    # #####      #   #  #######
#     # #    #   #   #    #       #    #    #   #   #    # #   #       # #        #
#     # #    #   #   #    #       #     ####    #    ####  #    #       #         #
***********************************************************************
                  Welcome to MathTutorV4!
***********************************************************************
  Welcome to the World of Math Wizards
Maths Fun Facts
* From 0 to 1000, the only number that has the letter 'a' in it is one thousand.
* Every odd number has an 'e' in it.
* It is always exciting to discover cool ways in which you can use or observe Math in the world.
***********************************************************************

Enter your first and last name:Philipine


Hi, PhilipineLet's test your math skills!
[Level #1] Philipine What is 8 - 4 =e

Invalid input!
Please enter a number:5

 Well, that was incorrect!
 Fortunately, you still have 2 attempts.
[Level #1] Philipine What is 8 - 4 =4

Such a genuis ! Your answer is correct

Do you want to continue? (y = yes | n = no):t

Invalid input. Please enter 'y' or 'n'.

Do you want to continue? (y = yes | n = no):y

[Level #1] Philipine What is 3 - 2 =6

 Well, that was incorrect!
 Fortunately, you still have 2 attempts.
[Level #1] Philipine What is 3 - 2 =0

 Well, that was incorrect!
 Fortunately, you still have 1 attempts.
[Level #1] Philipine What is 3 - 2 =9

 Sorry you are out of attempts
 The correct answer was: 1

Do you want to continue? (y = yes | n = no):n


=================== QUIZ SUMMARY ===================
Level     | Question |  Attempts
----------------------------------------------------
  1        8 - 4 = 4       2
  1        3 - 2 = 1 Incorrect

----------------------------------------------------
Total Questions: 2
Correct Answers: 1
Incorrect Answers: 1
Score:           50%
====================================================
Thanks for playing, Philipine! Come back soon.

```

## Maintainers

[@Philipine26](https://github.com/philipine26) Philipine Andjawo
[@Yamujeeb](https://github.com/Yamujeeb) Mujeeb Adewuyi

[Back to Top](#math-tutor-v3)
