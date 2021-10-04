#include <iostream>

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

    double result{ };

    switch(op)
    {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        default:
            std::cout << "Invalid input!\n";
    }

    std::cout << result;
}
