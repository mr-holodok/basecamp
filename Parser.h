/*
 * Parser.h
 *
 *  Created for: GlobalLogic Basecamp
 *       Author: mukolamoroz@gmail.com
 *
 * Parser class header.
 *
 * Parser perform tokenization of input 
 * (every num or operation is treated like a Token with corresponding value)
 * also Parser skips unnecessary spaces
 *
 */

#include <vector>
#include <stdint.h>
#include <string>
#include "Tokens.h"

#ifndef PARSER_H 
#define PARSER_H

class Parser
{
public:
    std::vector<Token> parse(std::string expr);
};

#endif