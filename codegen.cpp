#include "codegen.h"

vector <Instruction> CodeGenerator::generateCode(ASTNode* node){
    vector <Instruction> code;
    generateCodeHelper(node, code);
    return code;
};

void CodeGenerator::generateCodeHelper(ASTNode* node, vector <Instruction>& code){
  if(node->type == ASTNode::NUMBER){
      code.push_back(Instruction(OpCode::PUSH, node->number));
  } else if (node->type == ASTNode::BINOP) {
      generateCodeHelper(node->binop.left, code);
      generateCodeHelper(node->binop.right, code);
      switch (node->binop.op) {
          case '+' : code.push_back(Instruction(OpCode::ADD, 0)); break;
          case '-' : code.push_back(Instruction(OpCode::SUB, 0)); break;
          case '*' : code.push_back(Instruction(OpCode::MUL, 0)); break;
          case '/' : code.push_back(Instruction(OpCode::DIV, 0)); break;
      }
  }
}
