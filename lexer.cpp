#include "lexer.h"
#include <cctype>

Lexer::Lexer(const std::string& input) : input(input), pos(0) {}

Token Lexer::getNextToken() {
    while (pos < input.size() && isspace(input[pos])) {
        pos++; // Omitting blank marks
    }
    // If we ended processing input whe add special token END
    if (pos >= input.size()) {
        return {TokenType::END, 0};
    }
    //If we find new Token, we convert number from string type to int
    if (isdigit(input[pos])) {
        int value = 0;
        while (pos < input.size() && isdigit(input[pos])) {
            value = value * 10 + (input[pos] - '0');
            pos++;
        }
        return {TokenType::NUMBER, value};
    }
    //If we meet terminal sign we create special Token with value 0
    Token token;
    switch (input[pos]) {
        case '+': token.type = TokenType::PLUS; token.value = 0; break;
        case '-': token.type = TokenType::MINUS; token.value = 0; break;
        case '*': token.type = TokenType::MULTIPLY; token.value = 0; break;
        case '/': token.type = TokenType::DIVIDE; token.value = 0; break;
        default: throw runtime_error("Unexpected character: " + string(1, input[pos]));
    }
    pos++;
    return token;
}

