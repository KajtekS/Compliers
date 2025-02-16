#include "parser.h"
#include <stdexcept>
#include <iostream>

ASTNode::ASTNode(int value) : type(NUMBER), number(value) {}
ASTNode::ASTNode(ASTNode* left, char op, ASTNode* right) : type(BINOP) {
  binop.left = left;
  binop.op = op;
  binop.right = right;
}
Parser::Parser(Lexer &lexer) : lexer(lexer) {}

ASTNode *Parser::parseExpression() {
  ASTNode* node = parseTerm();
  while (true) {
    Token token = lexer.getNextToken();
    if (token.type == TokenType::PLUS || token.type == TokenType::MINUS) {
      char op = token.type == TokenType::PLUS ? '+' : '-';
      node = new ASTNode(node, op, parseTerm());
    } else {
      break;
    }
  }
}

ASTNode *Parser::parseTerm() {
  ASTNode*  node = parseNumber();
  while (true) {
    Token token = lexer.getNextToken();
    if (token.type == TokenType::MULTIPLY || token.type == TokenType::DIVIDE) {
      char op = token.type == TokenType::MULTIPLY ? '*' : '/';
      node = new ASTNode(node, op, parseNumber());
    } else {
      break;
    }
  }
}

ASTNode* Parser::parseNumber() {
  Token token = lexer.getNextToken();
  if (token.type == TokenType::NUMBER) {
    return new ASTNode(token.value);
  } else {
    throw std::runtime_error("Błąd składnikowy");
  }
}
