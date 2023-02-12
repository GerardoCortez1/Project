/* 
 * File:   main.cpp
 * Author: Gerardo Cortez
 * Created on February 6, 2023, 7:00 PM
 * Purpose:  Create a game without funcitons.
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <iomanip>
#include <thread> // Library to apply Sleep
#include <ctime> // Library for time comparison.
#include <fstream>
#include <string>
#include <math.h> 
using namespace std;

//User Libraries

//Global Constants not Variables
//Science, Math, Conversions, Dimensions

//Function Prototypes

//Execution begins here at main

int main(int argc, char** argv) {
    //Set random number seed

    //Declare Variables
    //Welcome Section Variables
    string playern; // The name of the player
    char seeInst; // Answer of the uset wheter he/she wants to see the instructions.
    char sureIns; //Asking the user for the 2nd time to see the instructions.
    bool startGm; //To know if the game as started ot no.
    fstream my_file; // To read name.txt
    
    //Gameboard Variables
    const int initPos = 0; // Value of initial Position.
    int enmNum = 2; // Number of enemies
    int enm1Pos = 0; // X-position of enemy 1
    int enm2Pos = 1; // X-position of enemy 2
    bool misilSt = false; // Has disparado?
    int misil_X = initPos; // X-position of the missile
    int misil_Y = initPos; // Y-position of the missile
    int userPos = initPos; // X-position of the USER
    char letter; // Letter pressed for position
    time_t start,end;
    float difTime;
    string namerd;
    
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
    cin>>playern;
    do {
            my_file.open("name.txt", ios::out);
	} while (!my_file);
	cout << "File opened successfully!"<<endl;
	my_file << playern;
	my_file.close();
    cout << "Welcome " << playern << " good luck, have fun." << endl;
    cout << endl;

    //Explain the rules.
    while (!startGm){
    cout << "Type Y to take a look at the rules. Type S to skip." << endl;
    cin>>seeInst; // Y or N.
    cout<<endl;
    if (seeInst == 'Y') {
        cout << "*************************INSTRUCTIONS*************************\n"
                "= Shoot down the enemies by firing a missile from your plane = \n"
                "Position your plane in A, B, C, or D, by writing the letter \n"
                "of where you want to shoot, then press ENTER and \n"
                "you will fire a shot. \n \n"
                "Your Plane looks like this ✈ \n"
                "Enemies look like this <> \n \n"
                "You will win when you knock down all the enemies. \n";
        cout << "\t\t       Good luck " << playern << "!" <<endl;
        cout << "**************************************************************\n";
        cout << endl;
        startGm = true;
    } else if (seeInst == 'S') {
        cout << "Are you shure you don't want to see the rules (Y/N)?" << endl;
        cin>>sureIns; //Asking 2nd time to see the rules.
        cout<<endl;
        if (sureIns == 'N') {
            cout << "*************************INSTRUCTIONS*************************\n"
                "= Shoot down the enemies by firing a missile from your plane = \n"
                "Position your plane in A, B, C, or D, by writing the letter \n"
                "of where you want to shoot, then press ENTER and \n"
                "you will fire a shot. \n \n"
                "Your Plane looks like this ✈ \n"
                "Enemies look like this <> \n \n"
                "You will win when you knock down all the enemies. \n";
        cout << "\t\t       Good luck " << playern << "!" <<endl;
        cout << "**************************************************************\n";
        cout << endl;
            startGm = true;
        } else if (sureIns == 'Y') {
            cout << "Okay, lets continue." << endl;
            cout << endl;
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
    //Display of the Game Board
        time(&start); //Time count starts.
        while(startGm){
        // Display gameboard
        cout<<"**********"<<endl;   // 1st Row
        cout<<"*";                  // 2nd Row - Start
        for(int i=0; i < 4; i++){
            if(i==enm1Pos){
                cout<<"<>";
            }
            else if(i==enm2Pos){
                cout<<"<>";
            } else {
                cout<<"  ";   
            }
        }
        cout<<"*"<<endl;            // 2nd Row - Finish
        for(int j=0; j < 2; j++){   // 3rd and 4th Row - Start
            cout<<"*";
            for(int i=0; i < 4; i++){
                if(misilSt){
                    if(i==misil_X && j==misil_Y){
                        cout<<"^ ";
                    } else {
                        cout<<"  ";
                    }
                } else {
                    cout<<"  ";
                }
            }
            cout<<"*"<<endl;
        }                           // 3rd and 4th Row - Finsh
        cout<<"*";                  // 5th Row - Start
        for(int i=0; i < 4; i++){
        (i==userPos) ? cout<<"✈" : cout<<"  ";
        }
        cout<<"*"<<endl;            // 5th Row - Finish
        cout<<"**********"<<endl;   // 6th Row
        cout<<"*A B C D *"<<endl;   // 7th Row
        cout<<"**********"<<endl;   // 8th Row
        cout<<"Enemies: "<<enmNum<<endl;   // 9th Row
        cout<<"**********"<<endl;   // 10th Row
        
        if(!misilSt) {
            cout<<"Press a letter (A/B/C/D) to select a position:"<<endl;
            cin>>letter;
            switch(letter){
                case 'A': {
                    userPos = 0;
                    break;
                }
                case 'B': {
                    userPos = 1;
                    break;
                }
                case 'C': {
                    userPos = 2;
                    break;
                }
                case 'D': {
                    userPos = 3;
                    break;
                }
            }
            misilSt = true;
            misil_X = userPos;
            misil_Y = 1;
        } else {
            this_thread::sleep_for(chrono::milliseconds(1000)); // Sleep 1 segundo
            if(misil_Y==0){
                if(misil_X == enm1Pos){
                    enm1Pos = -1;
                    enmNum--;
                } else if(misil_X == enm2Pos){
                    enm2Pos = -1;
                    enmNum--;
                }
                misilSt = false;
            }
            misil_Y--;
        }
        system("clear");
        if(enmNum == 0){
            cout<<"Congratulations "<< playern << "! You won! 🏆"<<endl;
            cout<<"✯ ✯. • ★ * ✯. . ★ * ° °· . • °★";
            cout<<endl;
            cout<<"Would you like to play again? (Y/N)"<<endl;
            cin>>plyAgn;
            if(plyAgn == 'Y'){
                enmNum = 2;
                enm1Pos = 1;
                enm2Pos = 3;
            } else {
                startGm = false;
                my_file.open("name.txt", ios::in);
                my_file >> namerd;
                my_file.close();
                time(&end);
                difTime = difftime(end,start);
                printf("Elasped time is %.2lf seconds (aprox %i). See you soon %s", 
                        difTime, static_cast<int>(difTime),namerd.c_str() );
            }
        }
        system("clear");
    }


        //Display Inputs/Outputs

        //Clean up memory and files

        //Exit the Program
        return 0;
    }