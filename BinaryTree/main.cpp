/*
 *  main.cpp - Entry point for binary serch tree sorting program
 *
 *  Created for: GlobalLogic Basecamp
 *       Author: mukolamoroz@gmail.com
 *
 */

#include <iostream>
#include <sstream>
#include <string>
#include "binary_tree.h"

int main() {
    std::cout
            << "Please enter integer numbers to sort them with binary tree. Mark end of input with  < 0> (space and zero)"
            << std::endl;
    std::string input;
    getline(std::cin, input);

    //BTree<int> b_tree = BTree<int>();
    BTree<int> b_tree;
    std::stringstream input_stream(input);

    int num = -1;

    // assume that the input is correct and contains only nums and spaces
    input_stream >> num;
    while (num) { // num != 0
        b_tree.add(num);
        input_stream >> num;
    }

    std::cout << "Sorted elements: " << std::endl;
    b_tree.print();
    std::cout << std::endl;
}
