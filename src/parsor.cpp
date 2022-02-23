/*
 * @Author: SuBonan
 * @Date: 2022-02-17 08:54:59
 * @LastEditTime: 2022-02-23 14:50:03
 * @FilePath: \naive-assembly\src\parsor.cpp
 * @Github: https://github.com/SugarSBN
 * これなに、これなに、これない、これなに、これなに、これなに、ねこ！ヾ(*´∀｀*)ﾉ
 */
#include"../include/parsor.h"
#include<iostream>
using namespace std;

vector<string> Parsor :: parse(string s) const{
    vector<string> res;
    for (int i = 0;i < s.size();){
        if (s[i] == ' ' || s[i] == ',' || s[i] == ';'){ i++;   continue;}
        int j;
        for (j = i + 1;j < s.size() && s[j] != ' ' && s[j] != ',' && s[j] != ';';j++);
        res.push_back(s.substr(i,j - i));
        i = j;
    }
    return res;
}

Parsor :: Parsor(string path){
    int pos = 0;
    string s;
    file.open(path.c_str());
    if (!file)  cout << "read file error!" << endl;
    vector<string> lab;
    while(getline(file, s)){
        pos++;
        vector<string> par = parse(s);
        if (par.empty())    continue;
        while(!par.empty() && par[0][par[0].size() - 1] == ':'){
            lab.push_back(par[0].substr(0, par[0].size() - 1));
            par.erase(par.begin());
        }
        if (par.empty())    continue;

        Opcode opt;
        vector<Type> operands;
        if (par[0] == "ADD") {  opt = ADD; operands = vector<Type> {Register, Register, Register}; } else
        if (par[0] == "SUB") {  opt = SUB; operands = vector<Type> {Register, Register, Register}; } else
        if (par[0] == "OR") {  opt = OR; operands = vector<Type> {Register, Register, Register}; } else
        if (par[0] == "AND") {  opt = AND; operands = vector<Type> {Register, Register, Register}; } else
        if (par[0] == "XOR") {  opt = XOR; operands = vector<Type> {Register, Register, Register}; } else
        if (par[0] == "SLT") {  opt = SLT; operands = vector<Type> {Register, Register, Register}; } else
        if (par[0] == "ADDI") {  opt = ADDI; operands = vector<Type> {Register, Register, Immediate}; } else
        if (par[0] == "SUBI") {  opt = SUBI; operands = vector<Type> {Register, Register, Immediate}; } else
        if (par[0] == "ANDI") {  opt = ANDI; operands = vector<Type> {Register, Register, Immediate}; } else
        if (par[0] == "ORI") {  opt = ORI; operands = vector<Type> {Register, Register, Immediate}; } else
        if (par[0] == "XORI") {  opt = XORI; operands = vector<Type> {Register, Register, Immediate}; } else
        if (par[0] == "MUL") {opt = MUL; operands = vector<Type> {Register, Register}; } else
        if (par[0] == "DIV") {opt = DIV; operands = vector<Type> {Register, Register}; } else
        if (par[0] == "MULI") {opt = MULI; operands = vector<Type> {Register, Immediate}; } else
        if (par[0] == "DIVI") {opt = DIVI; operands = vector<Type> {Register, Immediate}; } else
        if (par[0] == "LW") {opt = LW; operands = vector<Type> {Register, Address}; } else
        if (par[0] == "SW") {opt = SW; operands = vector<Type> {Register, Address}; } else
        if (par[0] == "JAL") {opt = JAL; operands = vector<Type> {Label}; } else
        if (par[0] == "JR") {opt = JR;  operands = vector<Type> {Register};} else
        if (par[0] == "LUI") {opt = LUI; operands = vector<Type> {Register, Immediate}; } else
        if (par[0] == "RET") {opt = RET; operands.clear();} else
        cout << "Error! line " << pos << " : Unknown Opcode." << endl;

        if (par.size() != operands.size() + 1)  cout << "Error! line " << pos << " : invalid number of operands." << endl;  

        vector<Operand> ope;
        for (int i = 0;i < operands.size();i++) ope.push_back(Operand(operands[i], par[i + 1]));
        insts.push_back(Instruction(opt, ope));
        labels.push_back(lab);
        lab.clear();
    }
}

vector<Instruction> Parsor :: get_insts() const{
    return insts;
}

vector<vector<string> > Parsor :: get_labels() const{
    return labels;
}
        
ostream & operator << (ostream &os, const Parsor &p){
    for (int i = 0;i < p.insts.size();i++){
        for (int j = 0;j < p.labels[i].size();j++)  os << p.labels[i][j] << ": ";
        os << p.insts[i] << endl;
    }    
    return os;
}