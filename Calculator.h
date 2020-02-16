/*
 * Calculator.h
 *
 *  Created for: GlobalLogic Basecamp
 *       Author: mukolamoroz@gmail.com
 *
 * Calculator class header.
 * 
 * As a feature stores every expression result in inbuilt memory 
 * (only if expression computed successfully)
 */

#include <string>
#include "Parser.h"
#include "Evaluator.h"

#ifndef CALCULATOR_H
#define CALCULATOR_H
#define CALC_MEM 10

class Calculator
{
public:
    Calculator();
    void calculate(std::string expr);
    float get_last_result();
    int get_last_saved_index();
private:
    float m_saved_results[CALC_MEM] = {0};
    int   m_last_saved_index; 
    Parser m_parser;
    Evaluator m_evaluator;
};

#endif