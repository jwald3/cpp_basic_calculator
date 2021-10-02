#include <iostream>


int main() {

    std::cout << "Enter first number: ";
    double num1{ };
    std::cin >> num1;

    std::cout << "Enter second number: ";
    double num2{ };
    std::cin >> num2;

    std::cout << num1 << " + " << num2 << " = " << num1 + num2 << '\n';
    return 0;
}
