/*
 * @Author: SuBonan
 * @Date: 2022-02-17 08:47:07
 * @LastEditTime: 2022-02-23 14:49:42
 * @FilePath: \naive-assembly\include\parsor.h
 * @Github: https://github.com/SugarSBN
 * これなに、これなに、これない、これなに、これなに、これなに、ねこ！ヾ(*´∀｀*)ﾉ
 */
#ifndef _PARSOR_H
#define _PARSOR_H
#include<fstream>
#include<vector>
#include"instruction.h"
using namespace std;
class Parsor{
    private:
        fstream file;
        vector<Instruction> insts;
        vector<vector<string> > labels;

        vector<string> parse(string s) const;
    public:
        Parsor(string path = "./boot.asm");

        vector<Instruction> get_insts() const;

        vector<vector<string> > get_labels() const;
        
        friend ostream & operator << (ostream &os, const Parsor &p);
};

#endif
