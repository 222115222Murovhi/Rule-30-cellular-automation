#include<iostream>
#include<time.h>
#include<cctype>
#include<cstdlib>
#include"CellularAutomata.h"

using namespace std;

int main(int argc, char *argv[]){
    // Check if the correct number of command-line arguments is provided
    if(argc!=2){
        cerr << "Usage: " << argv[0] << " <size>" <<endl; // Display usage message if incorrect number of arguments
        exit(CellularSpace::ERR_ARG); // Exit with error code if incorrect arguments
    }

    // Convert the second command-line argument to an integer representing the size
    int size=CellularSpace::convToInt(argv[1]);
    string choice;
    int rounds;
    int *Array;
    bool blnContinue=true;
    srand(time(0));

    // Main loop for displaying menu and handling user input
    do{
        cout<<"Menu :\n";
        cout<<"A : rounds of automation\n";
        cout<<"B : initial array\n";
        cout<<"C : cellular Automations\n";
        cout<<"X : Exit\n";
        cout<<endl;
        cout<<"Enter your choice: ";
        cin>>choice; // Prompt user for choice

        // Handle user choices
        if((choice=="A" || choice=="a") && choice.length()==1){
            // Prompt user to enter number of rounds for cellular automaton
            cout<<"Enter number of rounds of evolution for the cellular automaton: "<<endl;
            cin>>rounds;
        }
        else if((choice=="B" || choice=="b") && choice.length()==1){
            // Handle choice for initial array options
            cout<<endl;
            string ch;
            bool p=true;
            do{
                cout<<"Options: "<<endl;
                cout<<"option A : Random generated initial array"<<endl;
                cout<<"option B : User defined initial array"<<endl;
                cout<<"Enter your choice: ";
                cin>>ch;

                // Handle sub-choices for initial array options
                if((ch=="A" || ch=="a") && ch.length()==1){
                    Array=CellularSpace::randomArray(size); // Generate random initial array
                    p=false;
                }
                else if((ch=="B" || ch=="b") && ch.length()==1){
                    Array=CellularSpace::UserArray(size); // Get user-defined initial array
                    p=false;
                }
                else{
                    cout<<"Invalid choice"<<endl;
                    p=true;
                }
            } while(p);
        }
        else if((choice=="C" || choice=="c") && choice.length()==1){
            // Perform cellular automaton with chosen options
            CellularSpace::cellularAutomaton(Array,rounds,size);
        }
        else if((choice=="X" || choice=="x") && choice.length()==1){
            // Exit the program
            cout<<endl;
            cout<<"Exiting.....";
            blnContinue=false; // Set loop flag to false to exit loop
        }
        else{
            // Handle invalid input
            cout<<endl;
            cout<<"Invalid input - enter either A, B, C, or X"<<endl;
            cout<<endl;
        }
    } while(blnContinue); // Loop until user chooses to exit

    delete[] Array; // Deallocate memory for the array
    Array=nullptr;
    return 0; // Return 0 to indicate successful program termination
}

