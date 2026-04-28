#include <iostream>
#include <iomanip>
#define _USE_MATH_DEFINES
#include <cmath>
#include <limits>
using namespace std;

class ScientificCalculator {
private:
    double num1, num2, result;
    
public:
    // Display calculator menu
    void displayMenu() {
        cout << "\n" << string(50, '=') << "\n";
        cout << "\t\tSCIENTIFIC CALCULATOR" << endl;
        cout << string(50, '=') << "\n";
        cout << "1. Addition (+)" << endl;
        cout << "2. Subtraction (-)" << endl;
        cout << "3. Multiplication (*)" << endl;
        cout << "4. Division (/)" << endl;
        cout << "5. Power (x^y)" << endl;
        cout << "6. Square Root (√x)" << endl;
        cout << "7. Sine (sin)" << endl;
        cout << "8. Cosine (cos)" << endl;
        cout << "9. Tangent (tan)" << endl;
        cout << "10. Logarithm (log10)" << endl;
        cout << "11. Natural Log (ln)" << endl;
        cout << "12. Factorial (!)" << endl;
        cout << "13. Clear Screen" << endl;
        cout << "14. Exit" << endl;
        cout << string(50, '=') << "\n";
    }
    
    // Get input with validation
    double getNumber(string prompt) {
        double num;
        cout << prompt;
        while (!(cin >> num)) {
            cout << "❌ Invalid input! Please enter a number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        return num;
    }
    
    // Basic arithmetic operations
    void addition() {
        num1 = getNumber("Enter first number: ");
        num2 = getNumber("Enter second number: ");
        result = num1 + num2;
        displayResult("+", num1, num2, result);
    }
    
    void subtraction() {
        num1 = getNumber("Enter first number: ");
        num2 = getNumber("Enter second number: ");
        result = num1 - num2;
        displayResult("-", num1, num2, result);
    }
    
    void multiplication() {
        num1 = getNumber("Enter first number: ");
        num2 = getNumber("Enter second number: ");
        result = num1 * num2;
        displayResult("*", num1, num2, result);
    }
    
    void division() {
        num1 = getNumber("Enter dividend: ");
        num2 = getNumber("Enter divisor: ");
        if (num2 == 0) {
            cout << "❌ Error: Division by zero is not allowed!" << endl;
            return;
        }
        result = num1 / num2;
        displayResult("/", num1, num2, result);
    }
    
    // Scientific operations
    void power() {
        num1 = getNumber("Enter base: ");
        num2 = getNumber("Enter exponent: ");
        result = pow(num1, num2);
        displayResult("^", num1, num2, result);
    }
    
    void squareRoot() {
        num1 = getNumber("Enter number: ");
        if (num1 < 0) {
            cout << "❌ Error: Square root of negative number is not real!" << endl;
            return;
        }
        result = sqrt(num1);
        cout << fixed << setprecision(6);
        cout << "√" << num1 << " = " << result << endl;
    }
    
    void sine() {
        num1 = getNumber("Enter angle in degrees: ");
        result = sin(num1 * M_PI / 180.0);
        cout << fixed << setprecision(6);
        cout << "sin(" << num1 << "°) = " << result << endl;
    }
    
    void cosine() {
        num1 = getNumber("Enter angle in degrees: ");
        result = cos(num1 * M_PI / 180.0);
        cout << fixed << setprecision(6);
        cout << "cos(" << num1 << "°) = " << result << endl;
    }
    
    void tangent() {
        num1 = getNumber("Enter angle in degrees: ");
        result = tan(num1 * M_PI / 180.0);
        cout << fixed << setprecision(6);
        cout << "tan(" << num1 << "°) = " << result << endl;
    }
    
    void logarithm() {
        num1 = getNumber("Enter number: ");
        if (num1 <= 0) {
            cout << "❌ Error: Logarithm of non-positive number is undefined!" << endl;
            return;
        }
        result = log10(num1);
        cout << fixed << setprecision(6);
        cout << "log₁₀(" << num1 << ") = " << result << endl;
    }
    
    void naturalLog() {
        num1 = getNumber("Enter number: ");
        if (num1 <= 0) {
            cout << "❌ Error: Natural log of non-positive number is undefined!" << endl;
            return;
        }
        result = log(num1);
        cout << fixed << setprecision(6);
        cout << "ln(" << num1 << ") = " << result << endl;
    }
    
    // Factorial function
    long long factorial(int n) {
        if (n < 0) return -1;
        if (n == 0 || n == 1) return 1;
        long long fact = 1;
        for (int i = 2; i <= n; i++) {
            fact *= i;
        }
        return fact;
    }
    
    void calculateFactorial() {
        int n = (int)getNumber("Enter non-negative integer: ");
        if (n < 0) {
            cout << "❌ Error: Factorial of negative number is undefined!" << endl;
            return;
        }
        result = factorial(n);
        cout << n << "! = " << result << endl;
    }
    
    // Display result in formatted way
    void displayResult(string operation, double a, double b, double res) {
        cout << fixed << setprecision(6);
        cout << a << " " << operation << " " << b << " = " << res << endl;
    }
    
    // Clear screen
    void clearScreen() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }
    
    // Main calculator loop
    void run() {
        int choice;
        cout << "Welcome to Scientific Calculator!" << endl;
        
        do {
            displayMenu();
            cout << "Enter your choice (1-14): ";
            
            while (!(cin >> choice) || choice < 1 || choice > 14) {
                cout << "❌ Invalid choice! Enter number between 1-14: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            
            switch (choice) {
                case 1: addition(); break;
                case 2: subtraction(); break;
                case 3: multiplication(); break;
                case 4: division(); break;
                case 5: power(); break;
                case 6: squareRoot(); break;
                case 7: sine(); break;
                case 8: cosine(); break;
                case 9: tangent(); break;
                case 10: logarithm(); break;
                case 11: naturalLog(); break;
                case 12: calculateFactorial(); break;
                case 13: clearScreen(); break;
                case 14: cout << "\n👋 Thank you for using Scientific Calculator!" << endl; break;
            }
            
            if (choice != 13 && choice != 14) {
                string cont;
                cout << "\nPress Enter to continue...";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
            }
            
        } while (choice != 14);
    }
};

int main() {
    ScientificCalculator calc;
    calc.run();
    return 0;
}