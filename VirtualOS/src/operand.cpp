/*
 * @Author: SuBonan
 * @Date: 2022-02-15 19:17:29
 * @LastEditTime: 2022-02-18 09:17:26
 * @FilePath: \naive-assembly\src\operand.cpp
 * @Github: https://github.com/SugarSBN
 * これなに、これなに、これない、これなに、これなに、これなに、ねこ！ヾ(*´∀｀*)ﾉ
 */
#include"../include/operand.h"

Operand :: Operand(){

}

Operand :: Operand(Type ntype, string nval){
    type = ntype;
    val = nval;
}

int Operand :: interprete(const Environment &e, map<string, int> label_map) const{
    int p, im;
    string reg;
    switch (type){
        case Immediate:
            return atoi(val.c_str());
        case Register:
            return e.query_register(val);
        case Address:
            p = 0;
            for (int i = 0;i < val.size();i++)  if (val[i] == '('){
                p = i;  break;
            }
            im = atoi(val.substr(0, p).c_str());
            reg = val.substr(p + 1, val.size() - p - 2);
            return e.query_storage(im + e.query_register(reg));
        case Label:
            return label_map[val];
    }
    return 0;
}

Type Operand :: get_type() const{
    return type;
}

string Operand :: get_val() const{
    return val;
} 

int Operand :: get_val_bit(map<string, int> label_map) const{
    if (type == Register)   return atoi(val.substr(1).c_str());
    if (type == Label)  return label_map[val];
    if (type == Immediate)  return atoi(val.c_str());
    if (type == Address){
        int p = 0;
        for (int i = 0;i < val.size();i++)  if (val[i] == '('){
            p = i;  break;
        }
        int res = atoi(val.substr(0, p).c_str());
        res <<= 16;
        res += atoi(val.substr(p + 2, val.size() - p - 3).c_str());
        return res;
    }
    return 0;
}

ostream & operator << (ostream & os, const Operand & op){
    os << op.val;
    return os;
}
