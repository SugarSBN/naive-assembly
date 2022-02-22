/*
 * @Author: SuBonan
 * @Date: 2022-02-19 09:56:43
 * @LastEditTime: 2022-02-22 20:09:06
 * @FilePath: \naive-assembly\MCMC\src\program.cpp
 * @Github: https://github.com/SugarSBN
 * これなに、これなに、これない、これなに、これなに、これなに、ねこ！ヾ(*´∀｀*)ﾉ
 */
#include"..\\include\\program.h"
#include<ctime>

Program :: Program(vector<Instruction> ninsts, map<string, int> label_map){
    insts = ninsts;
    unused.clear();
    for (int i = 0;i < insts.size();i++)    if (insts[i].get_opcode() == JAL){
        int line = label_map[insts[i].get_operands()[0].get_val()];
        insts[i] = Instruction(JAL, vector<Operand>{Operand(Label, ".L" + to_string(line))});
    }
    p_c = 0.5 / 3;
    p_o = 0.5;
    p_s = 0.5 / 3;
    p_i = 0.5 / 3;
    p_u = 0.5 / 3;
}

ostream & operator << (ostream &os, const Program &p){
    int valid = 0;
    for (int i = 0;i < p.insts.size();i++){
        os << ".L" + to_string(valid) + ": ";
        if (!p.unused.count(i))   os << p.insts[i] << endl;
        else os << "UNUSED" << endl;
        valid++;
    }
    return os;
}

void Program :: generate(const Environment &e){
    double p = (double) rand() / RAND_MAX;
    srand((int) time (NULL));
    int i1 = rand() % insts.size();
    int i2 = rand() % insts.size();
    if (p < p_c){                       // Opcode random
        insts[i1].random_opcode();
    }else
    if (p < p_c + p_o){                 // Operand random
        if (insts[i1].get_operands().size() > 0) insts[i1].random_operand(e, insts.size());
    }else
    if (p < p_c + p_o + p_s){           // Swap random
        swap(insts[i1], insts[i2]);
    }else{                              // Instruction random
        p = (double) rand() / RAND_MAX;
        if (p < p_u){
            unused.insert(rand() % insts.size());
        }else{
            int i1 = rand() % insts.size();
            if (unused.count(i1))   unused.erase(i1);
            int optc = rand() % 21;
            if (optc < 5){
                int n = rand() % ((1 << 16) + (1 << 16) + 1) - (1 << 16);
                insts[i1] = Instruction(Opcode(optc), vector<Operand> {Operand(Register, e.random_register()), Operand(Register, e.random_register()), Operand(Immediate,to_string(n))});
            } else
            if (optc < 11){
                insts[i1] = Instruction(Opcode(optc), vector<Operand> {Operand(Register, e.random_register()), Operand(Register, e.random_register()), Operand(Register, e.random_register())});
            } else
            if (optc < 13){
                insts[i1] = Instruction(Opcode(optc), vector<Operand> {Operand(Register, e.random_register()), Operand(Register, e.random_register())});
            } else
            if (optc < 15){
                int n = rand() % ((1 << 16) + (1 << 16) + 1) - (1 << 16);
                insts[i1] = Instruction(Opcode(optc), vector<Operand> {Operand(Register, e.random_register()), Operand(Immediate, to_string(n))});
            } else
            if (optc < 17){
                insts[i1] = Instruction(Opcode(optc), vector<Operand> {Operand(Register, e.random_register()), Operand(Address, e.random_address())});
            }else{
                if (optc == 17)  insts[i1] = Instruction(Opcode(optc), vector<Operand> {Operand(Label, ".L" + to_string(rand() % insts.size()))});
                if (optc == 18)  insts[i1] = Instruction(Opcode(optc), vector<Operand> {Operand(Register, e.random_register())});
                if (optc == 19) {
                    int n = rand() % ((1 << 16) + (1 << 16) + 1) - (1 << 16);
                    insts[i1] = Instruction(Opcode(optc), vector<Operand> {Operand(Register, e.random_register()), Operand(Immediate, to_string(n))});
                }
                if (optc == 20)  insts[i1] = Instruction(Opcode(optc), vector<Operand> {});
            }
        }
    }
}