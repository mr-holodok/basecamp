/*
 * Parser.cpp
 *
 *  Created for: GlobalLogic Basecamp
 *       Author: mukolamoroz@gmail.com
 *
 * Parser class source code.
 *
 * Parser perform tokenization of input 
 * (every num or operation is treated like a Token with corresponding value)
 * also Parser skips unnecessary spaces
 * 
 * Some notes:
 *  * integer and floating-point numbers are allowed
 *  * parser also checks syntax correctness and performs pure error notification
 *  * floating point values have such pattern [0-9]([0-9])*.([0-9])*
 *  * numbers can be signed (minus) so it is legal to write > 1 - -2
 *
 *  Parser is an example of a Finite State Machine
 * 
 */

#include <string>
#include <stdexcept>
#include "Parser.h"
#include "Tokens.h"

bool is_op(char ch) 
{
    if (ch == '*' || ch == '/' || ch == '+' || ch == '-')
        return true;
    return false;
}

std::vector<Token> Parser::parse(std::string expr)
{
    uint pos = 0;
    auto ch = expr[pos];
    enum State { START, NUM, SIGN_NUM, FLOAT, SAVED_RES, OP_EXPECTED };
    State s = State::START;
    std::vector<Token> tokens;
    uint start_pos;

    while (pos != expr.length()) {
        switch (s)
        {
        case START:
            if (isdigit(ch)) {
                start_pos = pos;
                s = NUM;
                pos--; 
                // kind of look up to avoid missing 1-char number as the last symbol 
            }
            else if (ch == '-') {
                start_pos = pos;
                s = SIGN_NUM;
            }
            else if (ch == '$') {
                s = SAVED_RES;
            }
            else if (!isspace(ch)) {
                throw std::invalid_argument("Unexpected symbol at pos " + std::to_string(pos+1));
            }
            break;

        case SAVED_RES:
            if (isdigit(ch)) {
                s = OP_EXPECTED;
                tokens.push_back(Token(Token_Type::SAVED_RES, std::string(1, ch)));
            }
            else 
                throw std::invalid_argument("Unexpected symbol at pos " + std::to_string(pos+1));
            break;

        case OP_EXPECTED:
            if (is_op(ch)) {
                s = START;
                tokens.push_back(Token(Token_Type::OP, std::string(1, ch)));
            }
            else if (!isspace(ch))
                throw std::invalid_argument("Unexpected symbol at pos " + std::to_string(pos+1));
            break;

        case SIGN_NUM:
            if (isdigit(ch)) {
                s = State::NUM;
                pos--;
                // also lookup, to avoid missing -1 as last symbols
            }
            else
                throw std::invalid_argument("Unexpected symbol at pos " + std::to_string(pos+1));
            break;

        case NUM:
            if (ch == '.') 
                s = State::FLOAT;
            else if (is_op(ch)) {
                s = State::START;
                tokens.push_back(Token(Token_Type::NUM, std::string(expr.substr(start_pos, pos-start_pos))));
                tokens.push_back(Token(Token_Type::OP, std::string(1, ch)));
            }
            else if (isdigit(ch) && pos == expr.length() - 1) 
                tokens.push_back(Token(Token_Type::NUM, std::string(expr.substr(start_pos, pos-start_pos+1))));
            else if (isspace(ch)) {
                s = State::OP_EXPECTED;
                tokens.push_back(Token(Token_Type::NUM, std::string(expr.substr(start_pos, pos-start_pos))));
            }
            else if (!isdigit(ch))
                throw std::invalid_argument("Unexpected symbol at pos " + std::to_string(pos+1));
            break;

        case FLOAT:
            if (is_op(ch)) {
                s = State::START;
                tokens.push_back(Token(Token_Type::NUM, std::string(expr.substr(start_pos, pos-start_pos))));
                tokens.push_back(Token(Token_Type::OP, std::string(1, ch)));
            }
            else if (isdigit(ch) && pos == expr.length() - 1)
                tokens.push_back(Token(Token_Type::NUM, std::string(expr.substr(start_pos, pos-start_pos+1))));
            else if (isspace(ch)) {
                s = State::OP_EXPECTED;
                tokens.push_back(Token(Token_Type::NUM, std::string(expr.substr(start_pos, pos-start_pos))));
            }
            else if (!isdigit(ch))
                throw std::invalid_argument("Unexpected symbol at pos " + std::to_string(pos+1));
            break;
        }

        pos++;
        ch = expr[pos];
    }

    // these are exit states - means that if last state is one of them = it is ok, no syntax errors
    if ( ! (s == State::OP_EXPECTED || s == State::NUM || s == State::FLOAT) )
        throw std::invalid_argument("Syntax error! Check syntax at the end!");

    return tokens;
}