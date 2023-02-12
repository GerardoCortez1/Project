/* 
 * File:   main.cpp
 * Author: Gerardo Cortez
 * Created on February 6, 2023, 4:30 PM
 * Purpose:  Create a game without funcitons.
 */

//System Libraries
#include <iostream>  //Input Output Library
#include <iomanip>
#include <thread> // Library to apply Sleep
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
    char seerule; // Answer of the uset wheter he/she wants to see the rules.
    char surerul; //Asking the user for the 2nd time to see the rules.
    bool startGm; //To know if the game as started ot no.
    
    //Gameboard Variables
    int enem_num = 2; // Cantidad de enemigos
    int enem1_pos = 0; // Posicion en X del enemigo 1
    int enem2_pos = 1; // Posicion en X del enemigo 2
    bool misil_status = false; // Has disparado?
    int misil_posx = 0; // Posicion en X del misil
    int misil_posy = 0; // Posicion en Y del misil
    int user_pos = 1; // Posicion en X del usuario
    char letter; // Letra presionada
    
    //Play Again Variable
    char plyAgain; // Quieres jugar de nuevo?
    

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
    cout<<endl;
    if (seerule == 'Y') {
        cout << "EXPLAIN RULES HERE" << endl;
        startGm = true;
    } else if (seerule == 'S') {
        cout << "Are you shure you don't want to see the rules (Y/N)?" << endl;
        cin>>surerul; //Asking 2nd time to see the rules.
        cout<<endl;
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
    //Display of the Game Board
        while(startGm){
        // Display gameboard
        cout<<"**********"<<endl;   // 1 fila
        cout<<"*";                  // Empezando 2 fila
        for(int i=0; i < 4; i++){
            if(i==enem1_pos){
                cout<<"<>";
            }
            else if(i==enem2_pos){
                cout<<"<>";
            } else {
                cout<<"  ";   
            }
        }
        cout<<"*"<<endl;            // Terminando 2 fila
        for(int j=0; j < 2; j++){   // Empezando 3-4 fila
            cout<<"*";
            for(int i=0; i < 4; i++){
                if(misil_status){
                    if(i==misil_posx && j==misil_posy){
                        cout<<"^ ";
                    } else {
                        cout<<"  ";
                    }
                } else {
                    cout<<"  ";
                }
            }
            cout<<"*"<<endl;
        }                           // Terminando 3-4 fila
        cout<<"*";                  // Empezando 5 fila
        for(int i=0; i < 4; i++){
            if(i==user_pos){
                cout<<"✈";
            } else {
                cout<<"  ";
            }
        }
        cout<<"*"<<endl;            // Terminando 5 fila
        cout<<"**********"<<endl;   // 6 fila
        cout<<"*A B C D *"<<endl;   // 7 fila
        cout<<"**********"<<endl;   // 8 fila
        cout<<"Enemies: "<<enem_num<<endl;   // 7 fila
        cout<<"**********"<<endl;   // 8 fila
        
        if(!misil_status) {
            cout<<"Press a letter (A/B/C/D) to select a position:"<<endl;
            cin>>letter;
            switch(letter){
                case 'A': {
                    user_pos = 0;
                    break;
                }
                case 'B': {
                    user_pos = 1;
                    break;
                }
                case 'C': {
                    user_pos = 2;
                    break;
                }
                case 'D': {
                    user_pos = 3;
                    break;
                }
            }
            misil_status = true;
            misil_posx = user_pos;
            misil_posy = 1;
        } else {
            this_thread::sleep_for(chrono::milliseconds(1000)); // Sleep 1 segundo
            if(misil_posy==0){
                if(misil_posx == enem1_pos){
                    enem1_pos = -1;
                    enem_num--;
                } else if(misil_posx == enem2_pos){
                    enem2_pos = -1;
                    enem_num--;
                }
                misil_status = false;
            }
            misil_posy--;
        }
        system("clear");
        if(enem_num == 0){
            cout<<"Congratulations! You won!"<<endl;
            cout<<"Do you want to play again? (Y/N)"<<endl;
            cin>>plyAgain;
            if(plyAgain == 'Y'){
                enem_num = 2;
                enem1_pos = 1;
                enem2_pos = 3;
            } else {
                startGm = false;
                break;
            }
        }
        system("clear");
    }


        //Display Inputs/Outputs

        //Clean up memory and files

        //Exit the Program
        return 0;
    }