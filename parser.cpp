#include "parser.h"
#include <stdexcept>
#include <iostream>

ASTNode::ASTNode(int value) : type(NUMBER), number(value) {}
ASTNode::ASTNode(ASTNode* left, char op, ASTNode* right) : type(BINOP) {
    binop.left = left;
    binop.op = op;
    binop.right = right;
}

Parser::Parser(Lexer &lexer) : lexer(lexer) {
    currentToken = lexer.getNextToken();  // Start position
}

void Parser::advance() {
    currentToken = lexer.getNextToken();  // Actualization of token
}

ASTNode* Parser::parseExpression() {
    ASTNode* node = parseTerm();

    while (currentToken.type == TokenType::PLUS || currentToken.type == TokenType::MINUS) {
        char op = currentToken.type == TokenType::PLUS ? '+' : '-';
        advance();  // after processing we actualize our token in parsetree
        node = new ASTNode(node, op, parseTerm());
    }
    return node;
}

ASTNode* Parser::parseTerm() {
    ASTNode* node = parseNumber();

    while (currentToken.type == TokenType::MULTIPLY || currentToken.type == TokenType::DIVIDE) {
        char op = currentToken.type == TokenType::MULTIPLY ? '*' : '/';
        advance();
        node = new ASTNode(node, op, parseNumber());
    }
    return node;
}

ASTNode* Parser::parseNumber() {
    if (currentToken.type == TokenType::NUMBER) {
        int value = currentToken.value;
        advance();
        return new ASTNode(value);
    } else {
        throw std::runtime_error("Syntax Error");
    }
}

//This func is not needed, but really improves debugging the program
void ASTNode::printAST(int indent) const {
    for (int i = 0; i < indent; i++) {
        std::cout << "  ";
    }

    if (type == NUMBER) {
        std::cout << "NUMBER(" << number << ")" << std::endl;
    } else if (type == BINOP) {
        std::cout << "BINOP(" << binop.op << ")" << std::endl;
        binop.left->printAST(indent + 1);
        binop.right->printAST(indent + 1);
    }
}
