/*
 * @Author: SuBonan
 * @Date: 2022-02-16 10:12:51
 * @LastEditTime: 2022-02-22 20:03:39
 * @FilePath: \naive-assembly\VirtualOS\src\instruction.cpp
 * @Github: https://github.com/SugarSBN
 * これなに、これなに、これない、これなに、これなに、これなに、ねこ！ヾ(*´∀｀*)ﾉ
 */
#include"../include/instruction.h"
#include<ctime>

Instruction :: Instruction(Opcode nopt, vector<Operand> noperands){
    opt = nopt;
    operands = noperands;
}

Instruction :: Instruction(int bitcode, map<string, int> label_map){
    opt = Opcode((bitcode >> 26) & (0b111111));
    if (opt < 5){
        int rt = (bitcode >> 21) & (0b11111);
        int rs = (bitcode >> 16) & (0b11111);
        int imm16 = (bitcode & 0b1111111111111111);
        operands.resize(3);
        operands[0] = Operand(Register, "$" + to_string(rt));
        operands[1] = Operand(Register, "$" + to_string(rs));
        operands[2] = Operand(Immediate, to_string(imm16));
    }else
    if (opt < 11){
        int rd = (bitcode >> 21) & (0b11111);
        int rs = (bitcode >> 16) & (0b11111);
        int rt = (bitcode >> 11) & (0b11111);
        operands.resize(3);
        operands[0] = Operand(Register, "$" + to_string(rd));
        operands[1] = Operand(Register, "$" + to_string(rs));
        operands[2] = Operand(Register, "$" + to_string(rt));
    }else
    if (opt < 13){
        int rs = (bitcode >> 21) & (0b11111);
        int rt = (bitcode >> 16) & (0b11111);
        operands.resize(2);
        operands[0] = Operand(Register, "$" + to_string(rs));
        operands[1] = Operand(Register, "$" + to_string(rt));
    }else
    if (opt < 15){
        int rs = (bitcode >> 21) & (0b11111);
        int imm16 = (bitcode >> 5) & (0b1111111111111111);
        operands.resize(2);
        operands[0] = Operand(Register, "$" + to_string(rs));
        operands[1] = Operand(Immediate, to_string(imm16));
    }else
    if (opt < 17){
        int rt = (bitcode >> 21) & (0b11111);
        int rs = (bitcode >> 16) & (0b11111);
        int imm16 = (bitcode & 0b1111111111111111);
        operands.resize(2);
        operands[0] = Operand(Register, "$" + to_string(rt));
        operands[1] = Operand(Address, to_string(imm16) + "$(" + to_string(rs) + ")");
    }else
    if (opt == 17){
        int label = (bitcode >> 22) & (0b1111111111111111);
        string lab;
        for (map<string, int> :: iterator it = label_map.begin();it != label_map.end();it++){
            if (it -> second == label){
                lab = it -> first;
                break;
            }
        }
        operands.resize(1);
        operands[0] = Operand(Label, lab);
    }else
    if (opt == 18){
        int rt = (bitcode >> 21) & (0b11111);
        operands.resize(1);
        operands[0] = Operand(Register, "$" + to_string(rt));
    }else
    if (opt == 19){
        int rt = (bitcode >> 21) & (0b11111);
        int imm16 = (bitcode >> 5) & (0b1111111111111111);
        operands.resize(2);
        operands[0] = Operand(Register, "$" + to_string(rt));
        operands[1] = Operand(Immediate, to_string(imm16));
    }else
    if (opt == 20){
        operands.clear();
    }
}

int Instruction :: to_bitcode(map<string, int> label_map) const{
    int ws, res;
    ws = 6; res = opt;
    for (int i = 0;i < operands.size();i++){
        if (operands[i].get_type() == Register){
            ws += 5;
            res = (res << 5) + operands[i].get_val_bit(label_map);
        }
        if (operands[i].get_type() == Label){
            ws += 16;
            res = (res << 16) + operands[i].get_val_bit(label_map);
        }
        if (operands[i].get_type() == Address){
            ws += 16 + 5;
            res = (res << 21) + operands[i].get_val_bit(label_map);
        }
        if (operands[i].get_type() == Immediate){
            ws += 16;
            res = (res << 16) + operands[i].get_val_bit(label_map);
        }
    }
    res <<= (32 - ws);
    return res;
}

ostream & operator << (ostream & os, const Instruction & inst){
    os << inst.opt << " ";
    for (int i = 0;i < inst.operands.size() - 1;i++)    os << inst.operands[i] << ", ";
    os << inst.operands[inst.operands.size() - 1];
    return os;
}

ostream & operator << (ostream & os, const Opcode & op){
    switch(op){
        case ADD:
            os << "ADD";
            break;
        case ADDI:
            os << "ADDI";
            break;
        case SUB:
            os << "SUB";
            break;
        case SUBI:
            os << "SUBI";
            break;
        case MUL:
            os << "MUL";
            break;
        case MULI:
            os << "MULI";
            break;
        case DIV:
            os << "DIV";
            break;
        case DIVI:
            os << "DIVI";
            break;
        case OR:
            os << "OR";
            break;
        case ORI:
            os << "ORI";
            break;
        case AND:
            os << "AND";
            break;
        case ANDI:
            os << "ANDI";
            break;
        case XOR:
            os << "XOR";
            break;
        case XORI:
            os << "XORI";
            break;
        case SLT:
            os << "SLT";
            break; 
        case LW:
            os << "LW";
            break;
        case SW:
            os << "SW";
            break;
        case JAL:
            os << "JAL";
            break;
        case JR:
            os << "JR";
            break;
        case LUI:
            os << "LUI";
            break;
        case RET:
            os << "RET";
            break;
    }
    return os;
}

Opcode Instruction :: get_opcode() const{
    return opt;
}

vector<Operand> Instruction :: get_operands() const{
    return operands;
}

void Instruction :: random_opcode(){
    Opcode new_opt;
    srand((int) time (NULL));
    if (opt < 5){
        new_opt = Opcode(rand() % 5);
    }else
    if (opt < 11){
        new_opt = Opcode(rand() % 6 + 5);
    }else
    if (opt < 13){
        new_opt = Opcode(rand() % 2 + 11);
    }else
    if (opt < 15){
        new_opt = Opcode(rand() % 2 + 13);
    }else
    if (opt < 17){
        new_opt = Opcode(rand() % 2 + 15);
    }else return;
    opt = new_opt;
}

void Instruction :: random_operand(const Environment &e, int lines_of_the_program){
    srand((int) time (NULL));
    int i = rand() % operands.size();
    if (operands[i].get_type() == Immediate){
        int n = rand() % ((1 << 16) + (1 << 16) + 1) - (1 << 16);
        operands[i] = Operand(Immediate, to_string(n));
    }else
    if (operands[i].get_type() == Register){
        operands[i] = Operand(Register, e.random_register());
    }else
    if (operands[i].get_type() == Address){
        operands[i] = Operand(Address, e.random_address());
    }else
    if (operands[i].get_type() == Label){
        int n = rand() % lines_of_the_program;
        operands[i] = Operand(Label, ".L" + to_string(n));
    }
}