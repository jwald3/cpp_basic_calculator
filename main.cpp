#include <iostream>

double calculate(double num1, double num2, char op) {
    // handle switch statement in its own function for clarity in main function
    switch(op)
    {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        default:
            std::cout << "Invalid input!\n";
    }
}

int main()
{
    double num1{ };
    double num2{ };
    char op{}; // "operator" is a reserved keyword, otherwise I would use that identifier

    std::cout << "Enter first number: ";
    std::cin >> num1;

    std::cout << "Enter operator: ";
    std::cin >> op;

    std::cout << "Enter second number: ";
    std::cin >> num2;

    double result{calculate(num1, num2, op)};

    std::cout << result;
}
