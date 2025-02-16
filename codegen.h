#ifndef CODEGEN_H
#define CODEGEN_H

#include "parser.h"
#include <vector>

enum class OpCode {
    PUSH,
    ADD,
    SUB,
    MUL,
    DIV
};

struct Instruction {
  OpCode op;
  int value;

    Instruction(OpCode opcode, int val) : op(opcode), value(val) {} // Konstruktor
};

class CodeGenerator {
  public:
      vector<Instruction> generateCode(ASTNode* node);
  private:
      void generateCodeHelper(ASTNode* node, vector<Instruction>& code);
};

#endif //CODEGEN_H
