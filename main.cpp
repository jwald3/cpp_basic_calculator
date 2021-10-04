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

    if (op == '+') {
        result = num1 + num2;
    } else if (op == '-') {
        result = num1 - num2;
    } else if (op == '*') {
        result = num1 * num2;
    } else if (op == '/') {
        result = num1 / num2;
    } else {
        std::cout << "Invalid Operator!\n";
    }

    std::cout << result;
}
