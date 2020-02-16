/*
 * Evaluator.h
 *
 *  Created for: GlobalLogic Basecamp
 *       Author: mukolamoroz@gmail.com
 *
 * Evaluator class header.
 * 
 * Evaluates the result of passed Tokens
 * Has operation priority
 */ 

#include <vector>
#include "Tokens.h"

#ifndef EVALUATOR_H
#define EVALUATOR_H

class Evaluator 
{
public:
    float evaluate(std::vector<Token> tokens);
private:
    std::vector<float> get_numbers(std::vector<Token> tokens);
    std::vector<char> get_operations(std::vector<Token> tokens);
    float operation_result(float v1, float v2, char op);
};

#endif