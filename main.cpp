/*
 * @Author: SuBonan
 * @Date: 2022-02-19 09:49:20
 * @LastEditTime: 2022-02-23 15:27:14
 * @FilePath: \naive-assembly\main.cpp
 * @Github: https://github.com/SugarSBN
 * これなに、これなに、これない、これなに、これなに、これなに、ねこ！ヾ(*´∀｀*)ﾉ
 */
#include"./include/program.h"
#include"./include/simos.h"

int main(){
    SimOS os = SimOS();
    Program p = Program(os.get_insts(), os.get_label_map());
    cout << os.run_program(p, vector<pair<string, int> >{}).first << endl;
    
}