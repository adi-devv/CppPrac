#include <iostream>
#include <limits>

using namespace std;

int main() {
    char operation;
    double num1, num2;

    cout << "Enter operator (+, -, *, /): ";
    cin >> operation;

    // Input validation for operator
    if (cin.fail() || (operation != '+' && operation != '-' && operation != '*' && operation != '/')) {
        cout << "Error: Invalid operator" << endl;
        return 1;
    }

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    // Input validation for numbers
    if (cin.fail()) {
        cout << "Error: Invalid input" << endl;
        return 1;
    }

    switch(operation) {
        case '+':
            cout << "Result: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0)
                cout << "Result: " << num1 / num2 << endl;
            else
                cout << "Error: Division by zero" << endl;
            break;
    }

    return 0;
}
