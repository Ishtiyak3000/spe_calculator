#include <iostream>
#include "calculator.h"

int main() {
    int choice;
    double num1, num2;

    while (true) {
        std::cout << "\n===== CALCULATOR MENU =====\n";
        std::cout << "1. Square Root\n";
        std::cout << "2. Factorial\n";
        std::cout << "3. Natural Logarithm\n";
        std::cout << "4. Power Function\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 5) {
            std::cout << "Exiting program...\n";
            break;
        }

        try {
            switch (choice) {
                case 1:
                    std::cout << "Enter a number: ";
                    std::cin >> num1;
                    std::cout << "√" << num1 << " = " << squareRoot(num1) << "\n";
                    break;
                case 2:
                    int n;
                    std::cout << "Enter an integer: ";
                    std::cin >> n;
                    std::cout << n << "! = " << factorial(n) << "\n";
                    break;
                case 3:
                    std::cout << "Enter a number: ";
                    std::cin >> num1;
                    std::cout << "ln(" << num1 << ") = " << naturalLog(num1) << "\n";
                    break;
                case 4:
                    std::cout << "Enter base and exponent: ";
                    std::cin >> num1 >> num2;
                    std::cout << num1 << "^" << num2 << " = " << power(num1, num2) << "\n";
                    break;
                default:
                    std::cout << "Invalid choice! Please try again.\n";
            }
        } catch (const std::exception &e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    return 0;
}
