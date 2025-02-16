#include "virtualmachine.h"

int VirtualMachine::execute(const vector<Instruction>& code){
    vector<int> stack;
    for (const auto& instruction : code) {
        switch (static_cast<int>(instruction.op)) {
            case static_cast<int>(OpCode::PUSH): {
                stack.push_back(instruction.value);
                break;
            }
            case static_cast<int>(OpCode::ADD): {
                    int right = stack.back(); stack.pop_back();
                    int left = stack.back(); stack.pop_back();
                    stack.push_back(right + left);
                    break;
            }
            case static_cast<int>(OpCode::SUB): {
                int right = stack.back(); stack.pop_back();
                int left = stack.back(); stack.pop_back();
                stack.push_back(right - left);
                break;
            }
            case static_cast<int>(OpCode::MUL): {
                int right = stack.back(); stack.pop_back();
                int left = stack.back(); stack.pop_back();
                stack.push_back(right * left);
                break;
            }
            case static_cast<int>(OpCode::DIV): {
                int right = stack.back(); stack.pop_back();
                int left = stack.back(); stack.pop_back();
                stack.push_back(right / left);
                break;
            }
        }
    }
    return stack.back();
}