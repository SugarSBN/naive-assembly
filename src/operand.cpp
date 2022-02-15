/*
 * @Author: SuBonan
 * @Date: 2022-02-15 19:17:29
 * @LastEditTime: 2022-02-15 19:51:48
 * @FilePath: \naive-assembly\src\operand.cpp
 * @Github: https://github.com/SugarSBN
 * これなに、これなに、これない、これなに、これなに、これなに、ねこ！ヾ(*´∀｀*)ﾉ
 */
#include"../include/operand.h"

Operand :: Operand(Type ntype, string nval){
    type = ntype;
    val = nval;
}

int Operand :: interprete(const Environment &e) const{
    switch (type){
        case Immediate:
            return atoi(val.c_str());
        case Register:
            return e.query_register(val);
        case Address:
            int p = 0;
            for (int i = 0;i < val.size();i++)  if (val[i] == '('){
                p = i;  break;
            }
            int im = atoi(val.substr(0, p).c_str());
            string reg = val.substr(p + 1, val.size() - p - 2);
            return e.query_storage(im + e.query_register(reg));
    }
    return 0;
}