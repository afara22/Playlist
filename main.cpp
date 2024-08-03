#include <iostream>
#include "IntList.h"

using namespace std;

void Menu() {
    cout << "o - output list" << endl;
    cout << "pf - popfront" << endl;
    cout << "pb - popback" << endl;
    cout << "af - pushfront" << endl;
    cout << "ab - pushback" << endl;
    cout << "r - printreverse" << endl;
    cout << "q" << endl;
}


int main() {

    IntList grades;
    string userInput;

    Menu();

    cin >> userInput;
    while (userInput != "q") {
        cout << endl;
        if (userInput == "o"){
            cout << grades;
        }
        if (userInput == "af") {
            int i;
            cout << "what is the grade: ";
            cin >> i;
            grades.push_front(i);
        }
        if (userInput == "ab") {
            int j;
            cout << "What is the grade: ";
            cin >> j;
            grades.push_back(j);
        }
        if (userInput == "pf") {
            grades.pop_front();
        }
        if (userInput == "pb") {
            grades.pop_back();
        }
        if (userInput == "r") {
            grades.printReverse();
        }

        cout << endl;
        Menu();
        cin >> userInput;
    }

    return 0;
}