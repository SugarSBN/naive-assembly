/*
 * @Author: SuBonan
 * @Date: 2022-02-19 09:41:12
 * @LastEditTime: 2022-02-23 14:44:16
 * @FilePath: \naive-assembly\include\program.h
 * @Github: https://github.com/SugarSBN
 * これなに、これなに、これない、これなに、これなに、これなに、ねこ！ヾ(*´∀｀*)ﾉ
 */
#ifndef _PROGRAM_H
#define _PROGRAM_H

#include"instruction.h"
#include"environment.h"

#include<set>

class Program{
    private:
        vector<Instruction> insts;
        set<int> unused;
        double p_c, p_o, p_s, p_i, p_u;
    public:
        Program(){}
        
        Program(vector<Instruction> ninsts, map<string, int> label_map);

        void generate(const Environment &e);

        vector<Instruction> get_insts() const;

        set<int> get_unused() const;
        
        friend ostream & operator << (ostream &os, const Program &p);
};

#endif