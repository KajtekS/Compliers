#include <iostream>
#include "lexer.h"
#include "parser.h"
#include "codegen.h"
#include "virtualmachine.h"

using namespace std;

int main() {
    string input = "2+4-8*7";
    Lexer lexer(input);
    Parser parser(lexer);
    ASTNode* ast = parser.parseExpression();

    CodeGenerator generator;
    std::vector<Instruction> code = generator.generateCode(ast);

    VirtualMachine vm;
    int result = vm.execute(code);
    cout << "Wynik: " << result << std::endl;

    return 0;
}