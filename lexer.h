//
// Created by Kajetan Serweciński on 14/02/2025.
//
#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <stdexcept>
using namespace std;

enum class TokenType {
    NUMBER,
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    END
};

struct Token {
    TokenType type;
    int value; // Wartość dla liczb
};

class Lexer {
public:
    Lexer(const std::string& input);
    Token getNextToken();

private:
    std::string input;
    size_t pos;
};

#endif //LEXER_H
