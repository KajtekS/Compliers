//
// Created by Kajetan Serweciński on 16/02/2025.
//

#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"

struct ASTNode {
    enum Type {NUMBER, BINOP} type;
    union {
        int number;
        struct {
            ASTNode *left;
            char op;
            ASTNode *right;
        } binop;
    };

    ASTNode(int value);
    ASTNode(ASTNode *left, char op, ASTNode *right);

    void printAST(int indent = 0) const;
};

class Parser {
public:
    Parser(Lexer &lexer);
    ASTNode* parseExpression(); //Order of parsing Tokens matters, first as we know is +/- then *//, thats why there are two special functions.
    ASTNode* parseTerm();
    ASTNode* parseNumber();

private:
    Lexer &lexer;
    Token currentToken;
    void advance(); //Func which actualizes actual Token
};

#endif
