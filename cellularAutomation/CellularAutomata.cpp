#include<iostream>
#include<time.h>
#include<cctype>
#include<cstdlib>
#include<sstream>
#include"CellularAutomata.h"
using namespace std;

// Defining a namespace for cellular automata functions
namespace CellularSpace {
    // Function to implement Rule 30 for cellular automata
    int rule30(int a, int b, int c) {
        // Rule 30 logic based on the values of a, b, and c
        if (a == 1 && b == 1 && c == 1) return 0;
        if (a == 1 && b == 1 && c == 0) return 0;
        if (a == 1 && b == 0 && c == 1) return 0;
        if (a == 1 && b == 0 && c == 0) return 1;
        if (a == 0 && b == 1 && c == 1) return 1;
        if (a == 0 && b == 1 && c == 0) return 1;
        if (a == 0 && b == 0 && c == 1) return 1;
        if (a == 0 && b == 0 && c == 0) return 0;
    }

    // Function to generate a random array of given size
    int *randomArray(int s) {
        // Allocate memory for the array
        int *arr = new int[s];
        // Populate the array with random values
        for (int i = 0; i < s; i++) {
            int r = rand() % 2;
            arr[i] = r;
        }
        // Display the generated random array
        cout << "random round 1 array: {";
        for (int i = 0; i < s; i++) {
            cout << arr[i] << " ";
        }
        cout << "}" << endl;
        return arr;
    }

    // Function to input elements from the user and create an array
    int *UserArray(int si) {
        // Allocate memory for the array
        int *arr = new int[si];
        int x;
        // Prompt the user to input elements
        cout << "Enter elements of round 1 array:" << endl;
        for (int i = 0; i < si; i++) {
            cout << "element " << i + 1 << " : ";
            cin >> x;
            arr[i] = x;
        }
        // Display the user-input array
        cout << "User round 1 array: {";
        for (int i = 0; i < si; i++) {
            cout << arr[i] << " ";
        }
        cout << "}" << endl;
        return arr;
    }

    // Function to perform cellular automaton for a given number of rounds
    void cellularAutomaton(int *arr, int r, int sizee) {
        // Display the initial array
        cout << "cellular Automation to " << r + 1 << " rounds" << endl;
        cout << "{ ";
        for (int i = 0; i < sizee; i++) {
            cout << arr[i] << " ";
        }
        cout << "} round 1" << endl;

        // Perform cellular automaton for the specified rounds
        int prev, curr, next;
        int *newArr = new int[sizee];
        int *prevArr = arr;
        for (int i = 0; i < r; i++) {
            // Apply Rule 30 to the boundary cells
            newArr[0] = rule30(prevArr[sizee - 1], prevArr[0], prevArr[1]);
            newArr[sizee - 1] = rule30(prevArr[sizee - 2], prevArr[sizee - 1], prevArr[0]);
            // Apply Rule 30 to the inner cells
            for (int j = 1; j < sizee - 1; j++) {
                prev = prevArr[j - 1];
                curr = prevArr[j];
                next = prevArr[j + 1];
                newArr[j] = rule30(prev, curr, next);
            }
            // Display the updated array for each round
            cout << "{ ";
            for (int j = 0; j < sizee; j++) {
                cout << newArr[j] << " ";
            }
            cout << "} round " << i + 2 << endl;
            // Update the previous array with the new array
            for (int j = 0; j < sizee; j++) {
                prevArr[j] = newArr[j];
            }
        }
    }

    // Function to convert string to integer
    int convToInt(string str) {
        int num = 0;
        stringstream ss{str};
        ss >> num;
        // Check for conversion failure
        if (ss.fail()) {
            cerr << "could not convert : " << str << " to integer" << endl;
            exit(ERR_CONVERT);
        }
        return num;
    }
}
