/*
 * @Author: SuBonan
 * @Date: 2022-02-15 18:11:24
 * @LastEditTime: 2022-02-15 19:47:52
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
    Address
};

class Operand{
    private:
        Type type;
        string val;
    public:
        Operand(Type ntype, string nval);

        int interprete(const Environment &e) const;
};

#endif
