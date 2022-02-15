/*
 * @Author: SuBonan
 * @Date: 2022-02-15 15:58:31
 * @LastEditTime: 2022-02-15 19:55:31
 * @FilePath: \naive-assembly\main.cpp
 * @Github: https://github.com/SugarSBN
 * これなに、これなに、これない、これなに、これなに、これなに、ねこ！ヾ(*´∀｀*)ﾉ
 */
#include"include/register.h"
#include"include/environment.h"
#include"include/operand.h"
#include<iostream>

using namespace std;

int main(){
    Environment e = Environment("MIPS_32");
    e.set_register("$13", 10);
    e.set_storage(40, 110);
    Operand op = Operand(Address, "30($13)");
    cout << op.interprete(e) << endl;
    cout << e << endl;
}