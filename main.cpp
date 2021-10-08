#include <iostream>

enum Operation
{                       // provide abstraction layer, allows reassignment for operators
    add='+',
    subtract='-',
    multiply='*',
    divide='/',
};

double calculate(double num1, double num2, Operation op)
{
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

auto getNumber(bool valInput)           // "valInput" for the do/while loop. Will reuse "OK" variable because it's
{                                       // reassigned before control is encountered
    double numVal;

    do {
        std::cout << "Enter number: ";  // perpetual loop to ensure that user input is numeric type
        std::cin >> numVal;
        valInput = !std::cin.fail();
        if(!valInput)
        {
            std::cin.clear();
            std::cin.ignore();
        }
    } while(!valInput);                 // runs until number is given and OK is flipped to true

    return numVal;
}

int main()
{
    double num1{ };
    double num2{ };
    char op; // "operator" is a reserved keyword, otherwise I would use that identifier
    auto calcOn{ true }; // will handle program state, while true, user can calculate again
    char contCalc{ };
    bool OK{}; // will check state of user input, true means correct input, false means incorrect


    while (calcOn)
    {
        num1 = getNumber(OK);

        std::cout << "Provide operation (+, -, *, /): ";
        std::cin >> op; // catch standard

        auto enum_op = static_cast<Operation>(op); // convert char input to Operation enum type

        num2 = getNumber(OK);

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
    std::exit(EXIT_SUCCESS);
}
