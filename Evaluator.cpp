/*
 * Evaluator.cpp
 *
 *  Created for: GlobalLogic Basecamp
 *       Author: mukolamoroz@gmail.com
 *
 * Evaluator class source.
 * 
 */ 

#include "Evaluator.h"
#include <stdexcept>

/*
 * Basic idea: get separete tokens of nums and operations
 * and search for * or \ in operation (operation priority)
 * is such operations exist then convolve pair of arguments with operation
 * to one argument.
 * After this step all operations are + or - so priority now doesn't matter so
 * we can calc them in a row
 */

float Evaluator::evaluate(std::vector<Token> tokens)
{
    float result = 0;
    
    // at indexes 0, 2, 4 and so on are numbers
    // at indexes 1, 3, 5 and so on are operations
    
    std::vector<float> nums;
    try {
        nums = get_numbers(tokens);
    }
    catch (std::exception &e) {
        throw e;
    } 
    auto ops = get_operations(tokens);

    uint i = 0;
    while (i < ops.size()) {
        if (ops[i] == '*' || ops[i] == '/') {
            // making convolutions for multiplication and division
            
            nums[i+1] = operation_result(nums[i], nums[i+1], ops[i]);
            nums.erase(nums.begin() + i);
            ops.erase(ops.begin() + i);
        }
        else
            i++;
    }

    // extra check - if all operations were * and /
    if (nums.size() == 1)
        return nums[0];

    // all operations now only + and - so we can calc them in a row
    i = 0;
    result = nums[i];
    while (i < ops.size()) {
        result = operation_result(result, nums[i+1], ops[i]);
        i++;
    }

    return result;
}

// returns only numbers from Tokens assuming that numvers on even indexes
std::vector<float> Evaluator::get_numbers(std::vector<Token> tokens)
{
    std::vector<float> res = std::vector<float>();
    for (uint i = 0; i < tokens.size(); i += 2) {
        try {
            float val = std::stof(tokens[i].m_value);
            res.push_back(val);
        }
        catch(std::exception &e) {
                throw std::invalid_argument("Problems in converting numbers! Maybe you entered too great one!");
        }
    }
    return res;
}

// returns only operations from Tokens assuming that operations on odd indexes
std::vector<char> Evaluator::get_operations(std::vector<Token> tokens)
{
    std::vector<char> res = std::vector<char>();
    for (uint i = 1; i < tokens.size(); i += 2) {
        res.push_back(tokens[i].m_value[0]);
    }
    return res;
}

float Evaluator::operation_result(float v1, float v2, char op)
{
    switch (op)
    {
        case '*':
            return v1 * v2;
        case '/':
            if (v2 == 0) 
                throw std::invalid_argument("Division by zero is not allowed!");
            return v1 / v2;
        case '+':
            return v1 + v2;
        case '-':
            return v1 - v2;
        default:
            throw std::invalid_argument("Invalid operation!");
    }
}