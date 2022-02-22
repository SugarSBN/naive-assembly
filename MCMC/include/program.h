/*
 * @Author: SuBonan
 * @Date: 2022-02-19 09:41:12
 * @LastEditTime: 2022-02-22 19:52:22
 * @FilePath: \naive-assembly\MCMC\include\program.h
 * @Github: https://github.com/SugarSBN
 * これなに、これなに、これない、これなに、これなに、これなに、ねこ！ヾ(*´∀｀*)ﾉ
 */
#ifndef _PROGRAM_H
#define _PROGRAM_H

#include"..\\..\\VirtualOS\\include\\instruction.h"
#include"..\\..\\VirtualOS\\include\\environment.h"
#include<set>

class Program{
    private:
        vector<Instruction> insts;
        set<int> unused;
        double p_c, p_o, p_s, p_i, p_u;
    public:
        Program(vector<Instruction> ninsts, map<string, int> label_map);

        void generate(const Environment &e);
        
        friend ostream & operator << (ostream &os, const Program &p);
};

#endif