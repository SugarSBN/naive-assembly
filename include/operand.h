/*
 * @Author: SuBonan
 * @Date: 2022-02-15 18:11:24
 * @LastEditTime: 2022-02-16 11:35:18
 * @FilePath: \naive-assembly\include\operand.h
 * @Github: https://github.com/SugarSBN
 * これなに、これなに、これない、これなに、これなに、これなに、ねこ！ヾ(*´∀｀*)ﾉ
 */
#ifndef _OPERAND_H
#define _OPERAND_H

#include<vector>
#include<string>
#include"../include/environment.h"

using namespace std;

enum Type {
    Immediate,
    Register,
    Address,
    Label,
};

class Operand{
    private:
        Type type;
        string val;
    public:
        Operand();
        
        Operand(Type ntype, string nval);

        int interprete(const Environment &e) const;

        Type get_type() const;

        int get_val() const;

        friend ostream & operator << (ostream & os, const Operand & op);
};

#endif
