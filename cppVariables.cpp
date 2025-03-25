#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operation;
    string name;
    
    cout << "Anong pangalan mo muna: ";
    cin >> name;
    cout << "Enter ka ng equation (ito format: a + b): ";
    cin >> num1 >> operation >> num2;

    if (operation == '+' ) {
        cout << "Result: " << num1 + num2 << endl;
    }
    else if (operation == '-' ) {
        cout << "Result: " << num1 - num2 << endl;
    }
    else if (operation == '*' || operation == 'x' || operation == 'X') {
        cout << "Result: " << num1 * num2 << endl;
    }
    else if (operation == '/') {
        if (num2 == 0) {
            cout << "Error: Division by zero!" << endl;
        }
        else {
            cout << "Result: " << num1 / num2 << endl;
        }
    }
    else {
        cout << "Gago bawal yan hahaha. +, * , -, at / lang pwede.\nBobo mo " + name << endl;
    }

    return 0;
}
