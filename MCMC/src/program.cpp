/*
 * @Author: SuBonan
 * @Date: 2022-02-19 09:56:43
 * @LastEditTime: 2022-02-19 10:22:03
 * @FilePath: \naive-assembly\MCMC\src\program.cpp
 * @Github: https://github.com/SugarSBN
 * これなに、これなに、これない、これなに、これなに、これなに、ねこ！ヾ(*´∀｀*)ﾉ
 */
#include"..\\include\\program.h"

Program :: Program(vector<Instruction> ninsts, map<string, int> label_map){
    insts = ninsts;
    unused.clear();
    for (int i = 0;i < insts.size();i++)    if (insts[i].get_opcode() == JAL){
        int line = label_map[insts[i].get_operands()[0].get_val()];
        insts[i] = Instruction(JAL, vector<Operand>{Operand(Label, ".L" + to_string(line))});
    }
}

ostream & operator << (ostream &os, const Program &p){
    int valid = 0;
    for (int i = 0;i < p.insts.size();i++)  if (!p.unused.count(i)){
        os << ".L" + to_string(valid) + ": ";
        os << p.insts[i] << endl;
        valid++;
    }
    return os;
}