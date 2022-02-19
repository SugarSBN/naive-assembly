/*
 * @Author: SuBonan
 * @Date: 2022-02-17 08:38:23
 * @LastEditTime: 2022-02-19 10:12:01
 * @FilePath: \naive-assembly\VirtualOS\include\simos.h
 * @Github: https://github.com/SugarSBN
 * これなに、これなに、これない、これなに、これなに、これなに、ねこ！ヾ(*´∀｀*)ﾉ
 */
#ifndef _SIMOS_H
#define _SIMOS_H

#include"environment.h"
#include"instruction.h"
#include"parsor.h"
#include<vector>
#include<map>

using namespace std;

class SimOS{
    private:
        Environment e;
        vector<Instruction> boots;
        vector<vector<string> > labels;
        string boot_path;
        map<string, int> label_map;

        void print_insts() const;
        
    public:
        SimOS(string path = "./boot.asm");

        void boot();

        void execute_one_command();

        vector<Instruction> get_insts() const;

        map<string, int> get_label_map() const;

        Environment get_env() const;
    
};

#endif
