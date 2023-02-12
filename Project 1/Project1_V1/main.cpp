/* 
 * File:   main.cpp
 * Author: Gerardo Cortez
 * Created on February 1, 2023, 3:00 PM
 * Purpose:  Start to create a game without funcitons.
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes

//Execution begins here at main

int main(int argc, char** argv) {
    //Set random number seed

    //Declare Variables
    string playern; // The name of the player
    char seerule; // Answer of the uset wheter he/she wants to see the rules.
    char surerul; //Asking the user for the 2nd time to see the rules.
    bool startGm; //To know if the game as started ot no.

    //Initialize Variables
    startGm = false;

    //Map/Process the Inputs -> Outputs
    //Welcome Part
    cout << "Welcome to THE GAME" << endl;
    cout << "A game of strategy and C++" << endl;
    cout << endl;
    cout << "Please enter your name, and press ENTER" << endl;
    cin>>playern;
    cout << "Welcome " << playern << " good luck, have fun." << endl;
    cout << endl;

    //Explain the rules.
    while (!startGm){
    cout << "Type Y to take a look at the rules. Type S to skip." << endl;
    cin>>seerule; // Y or N.
    if (seerule == 'Y') {
        cout << "EXPLAIN RULES HERE" << endl;
        startGm = true;
    } else if (seerule == 'S') {
        cout << "Are you shure you don't want to see the rules (Y/N)?" << endl;
        cin>>surerul; //Asking 2nd time to see the rules.
        if (surerul == 'N') {
            cout << "EXPLAIN RULES HERE" << endl;
            startGm = true;
        } else if (surerul == 'Y') {
            cout << "Okay, lets continue." << endl;
            startGm = true;
        }
        else {
            cout<<"Error"<<endl;
        }
    }
    else {
        cout<<"Enter a valid answer"<<endl;
        cout<<endl;
    }
    } // Explain the rules ends here.
    
    //The game starts here
    while (startGm){
        cout<<"";
    }


        //Display Inputs/Outputs

        //Clean up memory and files

        //Exit the Program
        return 0;
    }