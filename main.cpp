/*
 * main.cpp
 *
 *  Created for: GlobalLogic Basecamp
 *       Author: mukolamoroz@gmail.com
 *
 * Entry point
 * Console wrapper for calculator class
 * 
 */

#include <iostream>
#include "Calculator.h"

int main()
{
    std::cout << "* Welcome in CONSOLE CALCULATOR!" << std::endl
              << "* Calculator supports: - integer and floating-point nums [with point \".\"]" << std::endl
              << "*                      - operations like: +, -, *, /" << std::endl
              << "*                      - and previous results in form $[0-9]" << std::endl 
              << "*" << std::endl
              << "* To quit press <q>" << std::endl << std::endl;

    std::string in;
    Calculator c = Calculator();

    while (true) {
        std::cout << "> ";
        //std::cin >> in;
        std::getline(std::cin, in);
        if (in == "q") 
            break;
        try {
            c.calculate(in);
            std::cout << c.get_last_result() << std::endl
                      << "Result saved as $" << c.get_last_saved_index() << std::endl; 
        }
        catch (std::invalid_argument &e) {
            std::cout << e.what() << std::endl;
        }
    }
    return 0;
}