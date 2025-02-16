#ifndef VIRTUALMACHINE_H
#define VIRTUALMACHINE_H

#include "codegen.h"
#include <vector>

class VirtualMachine {
    public:
      int execute(const vector<Instruction>& code);
};

#endif //VIRTUALMACHINE_H
