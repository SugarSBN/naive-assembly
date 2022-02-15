/*
 * @Author: SuBonan
 * @Date: 2022-02-15 15:54:26
 * @LastEditTime: 2022-02-15 17:40:07
 * @FilePath: \naive-assembly\src\register.cpp
 * @Github: https://github.com/SugarSBN
 * これなに、これなに、これない、これなに、これなに、これなに、ねこ！ヾ(*´∀｀*)ﾉ
 */
#include"../include/register.h"

Register :: Register(string nname, int nvalue){
    name = nname;
    value = nvalue;
}

string Register :: get_name() const{
    return name;
}

int Register :: get_value() const{
    return value;
}

void Register :: set_value(int nvalue){
    value = nvalue;
}

ostream & operator << (ostream & os, const Register &r){
    os << r.name << " : " << r.value;
    return os;
}