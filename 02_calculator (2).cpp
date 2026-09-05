#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double num1, num2;
    char op;

    cout << "=============================\n";
    cout << "      MINI CALCULATOR\n";
    cout << "=============================\n";

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter operator (+ - * /): ";
    cin >> op;

    cout << "Enter second number: ";
    cin >> num2;

    cout << fixed << setprecision(2);

    switch(op) {
        case '+':
            cout << "\nResult = " << num1 + num2;
            break;
 
        case '-':
            cout << "\nResult = " << num1 - num2;
            break;

        case '*':
            cout << "\nResult = " << num1 * num2;
            break;

        case '/':
            if(num2 != 0)
                cout << "\nResult = " << num1 / num2;
            else
                cout << "\nError: Division by zero!";
            break;

        default:
            cout << "\nInvalid operator!";
    }

    cout << "\n\nThank you for using the calculator!\n";

    return 0;
}
