//
//  main.cpp
//  Calculator_in_Console
//
//  Created by Biro Laszlo on 12.06.22.
//

#include <iostream>
#include <cmath>
#include <iomanip>

auto iPut() { auto in = 0.0; std::cin >> in; return in; }
void miPut( double* n1, double* n2) { std::cout << "number1: "; *n1 = iPut(); std::cout << "number2: "; *n2 = iPut(); }

void oMenu()
{
    std::cout << "Welcome to my console calculator program." << std::endl << "Take a look around." << std::endl;
    std::cout << "Choose a menu below." << std::endl;
    std::cout << "1 • Summation" << "\t\t" << "7 • Summation in Binary" << std::endl
              << "2 • Subtraction" << "\t\t" << "8 • Summation in HEX" << std::endl
              << "3 • Divison" << "\t\t\t" << "0 • Exit" << std::endl
              << "4 • Multiplication" << std::endl
              << "5 • Squaring" << std::endl
              << "6 • Radical subtraction" << std::endl;
    std::cout << "x : ";
}

auto cSum(double n1, double n2) { return n1 + n2; }
auto cSub(double n1, double n2) { return n1 - n2; }
auto cDiv(double n1, double n2) { return n1 / n2; }
auto cMul(double n1, double n2) { return n1 * n2; }
auto cSqu(double n1, double n2) { return pow(n1, n2); }
auto cRSub(double n1) { return sqrt(n1); }


auto sCalculation(int* input)
{
    auto result = 0.0;
    double n1 = 0.0;
    double n2 = 0.0;
    
    if (*input > 0 && *input < 6)
    {
//    Multiple input handler
        miPut(&n1, &n2);
    }
    else if (*input == 6)
    {
        std::cout << "number: ";
        n1 = iPut();
    }
    
    switch (*input) {
        case 1: result = cSum(n1, n2);
            break;
        case 2: result = cSub(n1, n2);
            break;
        case 3: result = cDiv(n1, n2);
            break;
        case 4: result = cMul(n1, n2);
            break;
        case 5: result = cSqu(n1, n2);
            break;
        case 6: result = cRSub(n1);
            break;
        case 0: return result;
            break;
        default: std::cout << "Not a menu number." << std::endl;
            break;
    }
    
    
    
    return result;
}

void fMenu(int* input)
{
    auto result = 0;
    if (*input < 7 && *input > 0)
    {
//        Simple Calculation
        result = sCalculation(input);
    }
    else if (*input > 6 && *input < 9)
    {
//        Binary Calculation
//        result = bCalculation(input);
    }
    else if (*input == 0)
    {
        return;
    }
    else
    {
        std::cout << "Not a menu number, try again." << std::endl;
        return;
    }
    
    std::cout << "result: " << result << std::endl;
    std::cout << "continue? \n0 • no\n1 • yes\nx : ";
    std::cin >> *input;
    
}

int main()
{
    int in;
    do {
//        Output Menu
        oMenu();
//        Input handler
        in = iPut();
//        Functions handler function
        fMenu(&in);
    } while (in);
    return 0;
}
