/* 
 * File:   main.cpp
 * Author: Gerardo Cortez
 * Created on February 12, 2023, 8:00 PM
 * Purpose:  Create a game with funcitons and Arrays.
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <iomanip>
#include <thread> // Library to apply Sleep
#include <ctime> // Library for time comparison.
#include <fstream>
#include <string>
#include <math.h> 
#include <vector> // Library to handle Vectors in C++.
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes
void display_instructions();
void get_name(string &); // Call by reference function
string wish_luck(string); //"Good Luck" - Return Function
float get_Dif_Time(time_t, time_t); // Get time difference in float
bool is_zero(int); // Function to know if the number of enemies is zero.
bool same_position(int, int); // Function to know if the missile is in the same position.
bool same_position(int, int, int, int);
void display_buttons(char[4]);
void add_pos(int [2][2], int, int, int); // 2 Dimmensioned Array
void eliminate_enemy(vector<int>&, int);

//Execution begins here at main

int main(int argc, char** argv) {
    //Set random number seed

    //Declare Variables
    //Welcome Section Variables
    static string playern; // The name of the player
    char seeInst; // Answer of the uset wheter he/she wants to see the instructions.
    char sureIns; //Asking the user for the 2nd time to see the instructions.
    bool startGm; //To know if the game as started ot no.
    fstream my_file; // To read name.txt

    //Gameboard Variables
    const int initPos = 0; // Value of initial Position.
    int enmNum = 2; // Number of enemies
    vector<int> enemies;
    enemies.push_back(0); // X-position of enemy 1
    enemies.push_back(pow(-1, 0));  // X-position of enemy 2
    bool misilSt = false; // Have you Shot?
    int posArr[2][2] = {
        {0, 0}, // Misil x,y
        {0, 0} // User x, 0
    };
    char letter; // Letter pressed for position
    time_t start, end;
    float difTime;
    int difTimI; // Variable to overload the function.
    string namerd;
    char btns[4] = {'A', 'B', 'C', 'D'}; // Array for USER position.
    char btnsnum[4] = {'1', '2', '3', '4'}; // Array for USER position - using numbers.

    //Play Again Variable
    char plyAgn; // Would you like to play again?


    //Initialize Variables
    startGm = false;

    //Map/Process the Inputs -> Outputs
    //Welcome Part
    cout << "Welcome to THE GAME" << endl;
    cout << "A game of strategy and C++" << endl;
    cout << endl;
    cout << "Please enter your name, and press ENTER" << endl;
    get_name(playern);
    do {
        my_file.open("name.txt", ios::out);
    } while (!my_file);
    cout << "File opened successfully!" << endl;
    my_file << playern;
    my_file.close();
    cout << "Welcome " << playern << " good luck, have fun." << endl;
    cout << endl;

    //Explain the instructions.
    while (!startGm) {
        cout << "Type Y to take a look at the instructions. Type S to skip." << endl;
        cin>>seeInst; // Y or S.
        cout << endl;
        if (seeInst == 'Y') {
            display_instructions(); // Display Instructions
            cout << wish_luck(playern);
            cout << "**************************************************************\n";
            cout << endl;
            startGm = true;
        } else if (seeInst == 'S') {
            cout << "Are you sure you don't want to see the instructions (Y/N)?" << endl;
            cin>>sureIns; //Asking 2nd time to see the rules.
            cout << endl;
            if (sureIns == 'N') {
                display_instructions(); // Display Instructions
                cout << wish_luck(playern);
                cout << "**************************************************************\n";
                cout << endl;
                startGm = true;
            } else if (sureIns == 'Y') {
                cout << "Okay, lets continue." << endl;
                cout << endl;
                startGm = true;
            } else {
                cout << "Error" << endl;
            }
        } else {
            cout << "Enter a valid answer" << endl;
            cout << endl;
        }
    } // Explain the rules instructions here.

    //The game starts here
    //Display of the Game Board
    time(&start); //Time count starts.
    while (startGm) {
        // Display gameboard
        cout << "**********" << endl; // 1st Row
        cout << "*"; // 2nd Row - Start
        for (int i = 0; i < 4; i++) {
            if (same_position(i, enemies[0])) {
                cout << "<>";
            } else if (same_position(i, enemies[1])) {
                cout << "<>";
            } else {
                cout << "  ";
            }
        }
        cout << "*" << endl; // 2nd Row - Finish
        for (int j = 0; j < 2; j++) { // 3rd and 4th Row - Start
            cout << "*";
            for (int i = 0; i < 4; i++) {
                if (misilSt) {
                    if (same_position(i, posArr[0][0], j, posArr[0][1])) {
                        cout << "^ ";
                    } else {
                        cout << "  ";
                    }
                } else {
                    cout << "  ";
                }
            }
            cout << "*" << endl;
        } // 3rd and 4th Row - Finsh
        cout << "*"; // 5th Row - Start
        for (int i = 0; i < 4; i++) {
            (i == posArr[1][0]) ? cout << "✈" : cout << "  ";
        }
        cout << "*" << endl; // 5th Row - Finish
        cout << "**********" << endl; // 6th Row
        display_buttons(btns); // 7th Row - Single Dimmentional Array here.
        display_buttons(btnsnum);
        cout << "**********" << endl; // 8th Row
        cout << "Enemies: " << enmNum << endl; // 9th Row
        cout << "**********" << endl; // 10th Row

        if (!misilSt) {
            cout << "Press a letter (A/B/C/D) or a numer (1/2/3/4) \n"
                    "to select a position:" << endl;
            cin>>letter;
            switch (letter) {
                case 'A':
                {
                    add_pos(posArr, 1, 0, 0);
                    break;
                }
                case 'B':
                {
                    add_pos(posArr, 1, 0, 1);
                    break;
                }
                case 'C':
                {
                    add_pos(posArr, 1, 0, 2);
                    break;
                }
                case 'D':
                {
                    add_pos(posArr, 1, 0, 3);
                    break;
                }
                case '1':
                {
                    add_pos(posArr, 1, 0, 0);
                    break;
                }
                case '2':
                {
                    add_pos(posArr, 1, 0, 1);
                    break;
                }
                case '3':
                {
                    add_pos(posArr, 1, 0, 2);
                    break;
                }
                case '4':
                {
                    add_pos(posArr, 1, 0, 3);
                    break;
                }
            }
            misilSt = true;
            add_pos(posArr, 0, 0, posArr[1][0]); // Value of USER is assigned to missile in X
            add_pos(posArr, 0, 1, 1); // Value of missile is 1.
        } else {
            this_thread::sleep_for(chrono::milliseconds(1000)); // Sleep 1 segundo
            if (posArr[0][1] == 0) {
                if (posArr[0][0] == enemies[0]) {
                    eliminate_enemy(enemies, 0);
                    enmNum--;
                } else if (posArr[0][0] == enemies[1]) {
                    eliminate_enemy(enemies, 1);
                    enmNum--;
                }
                misilSt = false;
            }
            add_pos(posArr, 0, 1, --posArr[0][1]);
        }
        system("clear");
        if (is_zero(enmNum)) {
            cout << "Congratulations " << playern << "! You won! 🏆" << endl;
            cout << "✯ ✯. • ★ * ✯. . ★ * ° °· . • °★";
            cout << endl;
            cout << "Would you like to play again? (Y/N)" << endl;
            cin>>plyAgn;
            if (plyAgn == 'Y') {
                enmNum = 2;
                enemies[0] = 1;
                enemies[1] = 3;
            } else {
                startGm = false;
                my_file.open("name.txt", ios::in);
                my_file >> namerd;
                my_file.close();
                time(&end);
                difTime = difftime(end, start);
                printf("Elasped time is %.2lf seconds (aprox %i). See you soon %s",
                        difTime, static_cast<int> (difTime), namerd.c_str());
            }
        }
        system("clear");
    }


    //Display Inputs/Outputs

    //Clean up memory and files

    //Exit the Program
    exit(0);
}

//The function that displays the Instructions

void display_instructions() {
    cout << "*************************INSTRUCTIONS*************************\n"
            "= Shoot down the enemies by firing a missile from your plane = \n"
            "Position your plane in A, B, C, or D, by writing the letter \n"
            "of where you want to shoot, then press ENTER and \n"
            "you will fire a shot. \n \n"
            "Your Plane looks like this ✈ \n"
            "Enemies look like this <> \n \n"
            "You will win when you knock down all the enemies. \n";
}

// The function that gets the player's name

void get_name(string &playern) {
    cin>>playern;
}

// The Function that wishes the USER good luck

string wish_luck(string playern = "User") {
    return "\t\t       Good luck " + playern + "!" + "\n";
} // If the argument is not valid, User will be print out. User is the value by default.

// Function go know the time difference.

float get_Dif_Time(time_t start, time_t end) {
    float difTime;
    difTime = end - start;
    return difTime;
}

// Boolean function, to know if the number of enemies is zero

bool is_zero(int num) {
    return (num == 0);
}

// Function of the missile position - Overload Functions
// 1st Function

bool same_position(int pos1, int pos2) {
    return (pos1 == pos2); // To check if the value is the same
}
// 2nd Function

bool same_position(int pos1, int pos2, int pos3, int pos4) {
    return ((pos1 == pos2) && (pos3 == pos4));
}

// Function to Display Buttons - Single Dimensioned as Function Arrays.

void display_buttons(char btns[4]) {
    cout << "*";
    for (int i = 0; i < 4; i++) {
        cout << btns[i] << " ";
    };
    cout << "*" << endl; // Argument is a single Dimensional Array
}

// Missile and User Position - Passing Arrays to and From Funcitions.

void add_pos(int posArr[2][2], int row, int col, int value) {
    posArr[row][col] = value;
}

// Funciton to elimminate enemies - Passing Vectors to and From Functions.
void eliminate_enemy(vector<int> &enemies, int num){
    enemies[num] = -1;
}