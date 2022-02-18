/*
 * @Author: SuBonan
 * @Date: 2022-02-15 18:11:24
 * @LastEditTime: 2022-02-18 09:17:08
 * @FilePath: \naive-assembly\include\operand.h
 * @Github: https://github.com/SugarSBN
 * これなに、これなに、これない、これなに、これなに、これなに、ねこ！ヾ(*´∀｀*)ﾉ
 */
#ifndef _OPERAND_H
#define _OPERAND_H

#include<vector>
#include<map>
#include<string>
#include"environment.h"

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

        int interprete(const Environment &e, map<string, int> label_map) const;

        Type get_type() const;

        string get_val() const;

        int get_val_bit(map<string, int> label_map) const;

        friend ostream & operator << (ostream & os, const Operand & op);
};

#endif
