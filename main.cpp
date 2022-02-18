/*
 * @Author: SuBonan
 * @Date: 2022-02-15 15:58:31
 * @LastEditTime: 2022-02-18 09:43:00
 * @FilePath: \naive-assembly\main.cpp
 * @Github: https://github.com/SugarSBN
 * これなに、これなに、これない、これなに、これなに、これなに、ねこ！ヾ(*´∀｀*)ﾉ
 */
#include"include/register.h"
#include"include/environment.h"
#include"include/operand.h"
#include"include/instruction.h"
#include"include/parsor.h"
#include"include/simos.h"
#include<iostream>
#include<bitset>

using namespace std;

int main(){
    SimOS os = SimOS("./boot.asm");
    os.boot();
}