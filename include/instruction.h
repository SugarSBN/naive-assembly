/*
 * @Author: SuBonan
 * @Date: 2022-02-15 18:03:36
 * @LastEditTime: 2022-02-18 09:27:41
 * @FilePath: \naive-assembly\include\instruction.h
 * @Github: https://github.com/SugarSBN
 * これなに、これなに、これない、これなに、これなに、これなに、ねこ！ヾ(*´∀｀*)ﾉ
 */
#ifndef _INSTRUCTION_H
#define _INSTRUCTION_H

#include"operand.h"
#include<map>

enum Opcode {
    ADDI,   // ADDI rt, rs, imm16;  rt <- rs + imm16                    000000 = 0
    SUBI,   // SUBI rt, rs, imm16;  rt <- rs - imm16                    000001 = 1
    ANDI,   // ANDI rt, rs, imm16;  rt <- rs & imm16                    000010 = 2
    ORI,    // ORI rt, rs, imm16;   rt <- rs | imm16                    000011 = 3
    XORI,   // XORI rt, rs, imm16;  rt <- rs ^ imm16                    000100 = 4

    ADD,    // ADD rd, rs, rt;      rd <- rs + rt                       000101 = 5
    SUB,    // SUB rd, rs, rt;      rd <- rs - rt                       000110 = 6
    OR,     // OR rd, rs, rt;       rd <- rs | rt                       000111 = 7
    AND,    // AND rd, rs, rt;      rd <- rs & rt                       001000 = 8
    XOR,    // XOR rd, rs, rt;      rd <- rs ^ rt                       001001 = 9
    SLT,    // SLT rd, rs, rt;      rd <- rs < rt ? 1 : 0               001010 = 10

    MUL,    // MUL rs, rt;          [HI : LO] <- rs * rt                001011 = 11
    DIV,    // DIV rs, rt;          rs / rt = LO ...... HI              001100 = 12

    MULI,   // MULI rs, imm16;      [HI : LO] <- rs * imm16             001101 = 13
    DIVI,   // DIVI rs, imm16;      rs / imm16 = LO ...... HI           001110 = 14

    LW,     // LW rt address;       rt <- storage[address]              001111 = 15
    SW,     // SW rt address;       storage[address] <- rt              010000 = 16

    JAL,    // JAL Label;           ra <- PC + 1, PC <- (Label)         010001 = 17
    JR,     // JR rt;               PC <- rt                            010010 = 18
    LUI,    // LUI rt, imm16;       rt <- (imm16 << 16)                 010011 = 19

    RET,    // RET;                 PC <- ra                            010100 = 20
};

ostream & operator << (ostream &os, const Opcode &op);

class Instruction{
    private:
        Opcode opt;
        vector<Operand> operands;
    public:
        Instruction(){}
        
        Instruction(Opcode nopt, vector<Operand> noperands);
        
        Instruction(int bitcode, map<string, int> label_map);

        int to_bitcode(map<string, int> label_map) const;

        Opcode get_opcode() const;

        vector<Operand> get_operands() const;

        friend ostream & operator << (ostream & os, const Instruction & i);
};

#endif
