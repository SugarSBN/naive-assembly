/*
 * @Author: SuBonan
 * @Date: 2022-02-15 15:40:23
 * @LastEditTime: 2022-02-15 17:39:52
 * @FilePath: \naive-assembly\include\register.h
 * @Github: https://github.com/SugarSBN
 * これなに、これなに、これない、これなに、これなに、これなに、ねこ！ヾ(*´∀｀*)ﾉ
 */
#ifndef _REGISTER_H_
#define _REGISTER_H_

#include<string>
#include<iostream>
using namespace std;
class Register{
    private:
        string name;
        int value;  // 32 bit signed integer, -2147483648 ~ 2147483647 
    public:
        Register(string nname, int nvalue = 0);
        
        string get_name() const;
        
        int get_value() const;

        void set_value(int nvalue);

        friend ostream & operator << (ostream &os, const Register &r);
};

#endif
