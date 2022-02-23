/*
 * @Author: SuBonan
 * @Date: 2022-02-22 20:12:13
 * @LastEditTime: 2022-02-23 15:34:50
 * @FilePath: \naive-assembly\include\mcmc.h
 * @Github: https://github.com/SugarSBN
 * これなに、これなに、これない、これなに、これなに、これなに、ねこ！ヾ(*´∀｀*)ﾉ
 */
#ifndef _MCMC_H
#define _MCMC_H
#include"program.h"
#include"simos.h"

class MCMC{
    private:
        Program std;
        Program tentative;
    public:
        MCMC(){};
        MCMC(Program p);
        
        int eq() const;
};

#endif
