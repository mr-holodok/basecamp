/*
 * Tokens.h
 *
 *  Created for: GlobalLogic Basecamp
 *       Author: mukolamoroz@gmail.com
 *
 * Token struct header.
 * 
 * Tokens needed for Parser class to represent input data as meaningful data to next stages
 */

#include <stdint.h>
#include <string>

#ifndef TOKENS_H
#define TOKENS_H

// Types for NUMBERS, OPERATIONS, SAVED_RESULTS
enum Token_Type { NUM, OP, SAVED_RES };

struct Token
{
public:
    Token_Type m_type;
    std::string m_value;
    Token(Token_Type t, std::string s) : m_type(t), m_value(s) {};
};

#endif