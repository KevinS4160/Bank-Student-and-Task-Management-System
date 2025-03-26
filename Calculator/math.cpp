#include <iostream>
using namespace std;

class Calculator {
public:
    double add(double a, double b) { return a + b; }
    double subtract(double a, double b) { return a - b; }
    double multiply(double a, double b) { return a * b; }
    double divide(double a, double b) { return (b != 0) ? a / b : 0; }
};

int main() {
    Calculator calc;
    double num1, num2;
    int choice;

    while (true) {
        cout << "\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 5) {
            cout << "Exiting...\n";
            break;
        }

        cout << "Enter two numbers: ";
        cin >> num1 >> num2;

        switch (choice) {
            case 1: cout << "Result: " << calc.add(num1, num2) << endl; break;
            case 2: cout << "Result: " << calc.subtract(num1, num2) << endl; break;
            case 3: cout << "Result: " << calc.multiply(num1, num2) << endl; break;
            case 4: 
                if (num2 != 0)
                    cout << "Result: " << calc.divide(num1, num2) << endl;
                else
                    cout << "Error! Division by zero.\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}
