/*
 * @Author: SuBonan
 * @Date: 2022-02-15 15:58:31
 * @LastEditTime: 2022-02-16 11:48:02
 * @FilePath: \naive-assembly\main.cpp
 * @Github: https://github.com/SugarSBN
 * これなに、これなに、これない、これなに、これなに、これなに、ねこ！ヾ(*´∀｀*)ﾉ
 */
#include"include/register.h"
#include"include/environment.h"
#include"include/operand.h"
#include"include/instruction.h"
#include<iostream>
#include<bitset>

using namespace std;

int main(){
    vector<Operand> tmp;
    tmp.push_back(Operand(Register, "$3"));
    tmp.push_back(Operand(Address, "5($10)"));
    Instruction inst = Instruction(LW, tmp);
    cout << bitset<32>(inst.to_bitcode()) << endl;
}