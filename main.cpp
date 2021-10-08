#include <iostream>

enum Operation
{                       // provide abstraction layer, allows reassignment for operators
    add='+',
    subtract='-',
    multiply='*',
    divide='/',
};

double calculate(double num1, double num2, Operation op) {
    // handle switch statement in its own function for clarity in main function
    switch(op)
    {
        case add:
            return num1 + num2;
        case subtract:
            return num1 - num2;
        case multiply:
            return num1 * num2;
        case divide:
            return num1 / num2;
        default:
            std::cout << "Invalid input!\n";
            std::exit(EXIT_FAILURE);
    }
}

int main()
{
    double num1{ };
    double num2{ };
    char op; // "operator" is a reserved keyword, otherwise I would use that identifier
    auto calcOn{ true }; // will handle program state, while true, user can calculate again
    char contCalc{ };
    bool OK; // will check state of user input, true means correct input, false means incorrect


    while (calcOn) {
        // calculator will run until user ends it
        do {
            std::cout << "Enter first number: ";    // perpetual loop to ensure that user input is numeric type
            std::cin >> num1;
            OK = !std::cin.fail();
            if(!OK) {
                std::cin.clear();
                std::cin.ignore();
            }
        } while(!OK);                               // runs until number is given and OK is flipped to true


        std::cout << "Provide operation (+, -, *, /): ";
        std::cin >> op; // catch standard

        auto enum_op = static_cast<Operation>(op); // convert char input to Operation enum type

        do {
            std::cout << "Enter second number: ";
            std::cin >> num2;
            OK = !std::cin.fail();
            if(!OK) {
                std::cin.clear();
                std::cin.ignore();
            }
        } while(!OK);

        auto result{calculate(num1, num2, enum_op)};

        std::cout << result << '\n';
        contCalc = '\0'; // reset (otherwise program won't let you change the option later)

        while (contCalc != 'n' && contCalc != 'y') {
            // handles incorrect input, keeps asking until y or n is entered
            std::cout << "Calculate again? (y for yes, n for no)";
            std::cin >> contCalc;
        }

        if (contCalc == 'n') {
            // end program by toggling
            calcOn = false;
        }
    }

    std::cout << "Have a nice day!";
}
