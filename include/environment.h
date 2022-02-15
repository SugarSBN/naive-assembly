/*
 * @Author: SuBonan
 * @Date: 2022-02-15 15:40:16
 * @LastEditTime: 2022-02-15 19:48:24
 * @FilePath: \naive-assembly\include\environment.h
 * @Github: https://github.com/SugarSBN
 * これなに、これなに、これない、これなに、これなに、これなに、ねこ！ヾ(*´∀｀*)ﾉ
 */
#ifndef _ENVIRONMENT_H_
#define _ENVIRONMENT_H_

#include"register.h"
#include<vector>

class Environment{
    private:
        vector<Register> general_registers, special_registers;
        vector<int> storage;
        string name;
    public:
        Environment(string nname = "", int storage_size = 512);

        void reset();

        pair<int, int> num_of_registers() const;

        int query_register(string name) const;

        int query_storage(int address) const ;

        void set_register(string name, int value);

        void set_storage(int address, int value);

        friend ostream & operator << (ostream & os, const Environment & e);
};

#endif
