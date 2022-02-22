/*
 * @Author: SuBonan
 * @Date: 2022-02-19 09:49:20
 * @LastEditTime: 2022-02-22 20:09:20
 * @FilePath: \naive-assembly\MCMC\main.cpp
 * @Github: https://github.com/SugarSBN
 * これなに、これなに、これない、これなに、これなに、これなに、ねこ！ヾ(*´∀｀*)ﾉ
 */
#include"./include/program.h"
#include"../VirtualOS/include/simos.h"

int main(){
    SimOS os = SimOS("../VirtualOS/boot.asm");
    Program p = Program(os.get_insts(), os.get_label_map());
    cout << p << endl;
    
}