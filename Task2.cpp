// Simple Calculator;

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    double num1, num2, result;
    char operation;
    char continueChoice;
    
    cout << "==================================" << endl;
    cout << "       SIMPLE CALCULATOR          " << endl;
    cout << "==================================" << endl;
    
    do {
        cout << "\nEnter first number: ";
        while (!(cin >> num1)) {
            cout << "Invalid input! Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        cout << "Enter operator (+, -, *, /): ";
        cin >> operation;
        
        // Validate operator
        while (operation != '+' && operation != '-' && operation != '*' && operation != '/') {
            cout << "Invalid operator! Please enter +, -, *, or /: ";
            cin >> operation;
        }
        
        cout << "Enter second number: ";
        while (!(cin >> num2)) {
            cout << "Invalid input! Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        // Perform calculation
        switch (operation) {
            case '+':
                result = num1 + num2;
                cout << "\nResult: " << num1 << " + " << num2 << " = " << result << endl;
                break;
            case '-':
                result = num1 - num2;
                cout << "\nResult: " << num1 << " - " << num2 << " = " << result << endl;
                break;
            case '*':
                result = num1 * num2;
                cout << "\nResult: " << num1 << " * " << num2 << " = " << result << endl;
                break;
            case '/':
                if (num2 != 0) {
                    result = num1 / num2;
                    cout << "\nResult: " << num1 << " / " << num2 << " = " << fixed << setprecision(4) << result << endl;
                } else {
                    cout << "\n❌ Error: Cannot divide by zero!" << endl;
                }
                break;
        }
        
        cout << "\nDo you want to perform another calculation? (y/n): ";
        cin >> continueChoice;
        
    } while (continueChoice == 'y' || continueChoice == 'Y');
    
    cout << "\n==================================" << endl;
    cout << "     Thanks for using the         " << endl;
    cout << "         Calculator!              " << endl;
    cout << "==================================" << endl;
    
    return 0;
}