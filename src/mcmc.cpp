/*
 * @Author: SuBonan
 * @Date: 2022-02-22 20:13:11
 * @LastEditTime: 2022-02-23 15:42:33
 * @FilePath: \naive-assembly\src\mcmc.cpp
 * @Github: https://github.com/SugarSBN
 * これなに、これなに、これない、これなに、これなに、これなに、ねこ！ヾ(*´∀｀*)ﾉ
 */
#include"../include/mcmc.h"

MCMC :: MCMC(Program p){
    tentative = p;
    std = p;
}

int MCMC :: eq() const{
    SimOS os = SimOS();
    pair<int, Environment> result1 = os.run_program(std, vector<pair<string, int> > {});
    pair<int, Environment> result2 = os.run_program(tentative, vector<pair<string, int> >{});
    if (result1.first == 1 || result2.first == 1)   return 0x3f3f3f3f;
    
    return 0;
}