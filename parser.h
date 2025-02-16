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
};

class Parser {
  public:
    Parser(Lexer &lexer);
    ASTNode* parseExpression();
    ASTNode* parseTerm();
    ASTNode* parseNumber();

  private:
    Lexer &lexer;
};

#endif
