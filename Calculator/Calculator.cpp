/*
 * Calculator.cpp
 *
 *  Created for: GlobalLogic Basecamp
 *       Author: mukolamoroz@gmail.com
 *
 * Calculator class source.
 * 
 * As a feature stores every expression result in inbuilt memory 
 * (only if expression computed successfully)
 */

#include "Calculator.h"
#include <iostream>

Calculator::Calculator() 
{
    m_last_saved_index = -1;   
    m_parser = Parser();
    m_evaluator = Evaluator();
}

void Calculator::calculate(std::string expr) 
{
    std::vector<Token> tokens = m_parser.parse(expr);  
    
    // preparation : transform '$?' saved results to float nums
    for (uint i = 0; i < tokens.size() ; i += 2) {
        if (tokens[i].m_type == Token_Type::SAVED_RES) {
            int saved = tokens[i].m_value[0] - '0'; 
            if (m_last_saved_index < saved)
                throw std::invalid_argument("$" + tokens[i].m_value + " result is empty!");
            tokens[i].m_type = Token_Type::NUM;
            tokens[i].m_value = std::to_string(m_saved_results[saved]);
        }
    }
    
    float res;
    try {
        res = m_evaluator.evaluate(tokens);
    }
    catch (std::invalid_argument &e) {
        throw e;
    }

    m_last_saved_index++;
    m_saved_results[m_last_saved_index % (sizeof(m_saved_results) / sizeof(m_saved_results[0]))] = res;
}

float Calculator::get_last_result()
{
    return m_saved_results[m_last_saved_index % CALC_MEM]; 
}

int Calculator::get_last_saved_index()
{
    return m_last_saved_index % CALC_MEM;
}