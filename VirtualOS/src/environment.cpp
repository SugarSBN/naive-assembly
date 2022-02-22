/*
 * @Author: SuBonan
 * @Date: 2022-02-15 16:13:20
 * @LastEditTime: 2022-02-22 20:01:41
 * @FilePath: \naive-assembly\VirtualOS\src\environment.cpp
 * @Github: https://github.com/SugarSBN
 * これなに、これなに、これない、これなに、これなに、これなに、ねこ！ヾ(*´∀｀*)ﾉ
 */
#include"../include/environment.h"
#include<ctime>
Environment :: Environment(string nname, int storage_size){
    name = nname;
    if (nname == "") return;
    if (nname == "MIPS_32"){
        general_registers.clear();
        general_registers.push_back(Register("zero"));
        general_registers.push_back(Register("at"));
        for (int i = 0;i < 2;i++) general_registers.push_back(Register((string)"v" + (char)('0' + i)));
        for (int i = 0;i < 4;i++) general_registers.push_back(Register((string)"a" + (char)('0' + i)));
        for (int i = 0;i < 8;i++) general_registers.push_back(Register((string)"t" + (char)('0' + i)));
        for (int i = 0;i < 8;i++) general_registers.push_back(Register((string)"s" + (char)('0' + i)));
        for (int i = 0;i < 2;i++) general_registers.push_back(Register((string)"t" + (char)('8' + i)));
        for (int i = 0;i < 2;i++) general_registers.push_back(Register((string)"$t" + (char)('0' + i)));
        general_registers.push_back(Register("gp"));
        general_registers.push_back(Register("sp"));
        general_registers.push_back(Register("fp"));
        general_registers.push_back(Register("ra"));

        special_registers.push_back(Register("PC"));
        special_registers.push_back(Register("HI"));
        special_registers.push_back(Register("LO"));

        storage.clear();
        storage.resize(storage_size);
    }
}

void Environment :: reset(){
    Environment(name);
}

pair<int, int> Environment :: num_of_registers() const{
    return make_pair(general_registers.size(), special_registers.size());
}

string to_hex(int num, bool fixed = false){
    char s[32];
    if (num < 0)    s[0] = '1'; else s[0] = '0';
    int p = 31;
    if (num < 0)    num = -num;
    while(p != 0){
        if (num & 1)    s[p] = '1'; else s[p] = '0';
        num >>= 1;
        p--;
    }
    if (s[0] == '1'){
        for (int i = 1;i < 32;i++)  if (s[i] == '1')    s[i] = '0'; else s[i] = '1';
        if (s[31] == '0') s[31] = '1';  else s[31] = '0';
    }
    string res = "";
    for (int i = 0;i < 32;i += 4){
        int tmp = 0;
        for (int j = i;j < i + 4;j++)   tmp = tmp * 2 + s[j] - '0';
        if (tmp < 10)   res += '0' + tmp;
        if (tmp == 10)  res += 'A';
        if (tmp == 11)  res += 'B';
        if (tmp == 12)  res += 'C';
        if (tmp == 13)  res += 'D';
        if (tmp == 14)  res += 'E';
        if (tmp == 15)  res += 'F';
    }
    return res;
}

int Environment :: query_register(string name) const {
    pair<int, int> size = num_of_registers();
    int n = atoi(name.substr(1).c_str());
    if (name[0] == '$' && 0 <= n && n < 32) return general_registers[n].get_value();
    for (int i = 0;i < size.first;i++)  if (general_registers[i].get_name() == name) return general_registers[i].get_value();
    for (int i = 0;i < size.second;i++) if (special_registers[i].get_name() == name) return special_registers[i].get_value();
    string excep = "No register named ";
    excep += name;
    excep += " !\n";
    throw excep;
}

void Environment :: set_register(string name, int value){
    pair<int, int> size = num_of_registers();
    int n = atoi(name.substr(1).c_str());
    if (name[0] == '$' && 0 <= n && n < 32) {
        general_registers[n].set_value(value); 
        return;
    }
    for (int i = 0;i < size.first;i++)  if (general_registers[i].get_name() == name) {
        general_registers[i].set_value(value);
        return;
    }
    for (int i = 0;i < size.second;i++) if (special_registers[i].get_name() == name) {
        special_registers[i].set_value(value);
        return;
    }
    string excep = "No register named ";
    excep += name;
    excep += " !\n";
    throw excep;
}

int Environment :: query_storage(int address) const{
    if (address < storage.size() && address >= 0)   return  storage[address];
    string excep = "0x" + to_hex(address);
    excep += " is an invalid address!\n";
    throw excep; 
}

void Environment :: set_storage(int address, int value){
    if (address < storage.size() && address >= 0){
        storage[address] = value;
        return;
    }
    string excep = "0x" + to_hex(address);
    excep += " is an invalid address!\n";
    throw excep; 
}

ostream & operator << (ostream & os, const Environment & e){
    os << "General Registers: " << endl;
    for (int i = 0;i < e.general_registers.size();i++)  os << "$" << i << ", " << e.general_registers[i] << endl;
    os << "-------------------------------------------------------------------------" << endl;
    os << "Special Registers: " << endl;
    for (int i = 0;i < e.special_registers.size();i++)  os << "$" << i << ", " << e.special_registers[i] << endl;
    os << "-------------------------------------------------------------------------" << endl;
    os << "Size of storage = " << e.storage.size() << " * 32bit" << endl;
    for (int i = 0;i < e.storage.size() / 8;i++){
        os << "0x" << to_hex(i * 8) << " : ";
        for (int j = 0;j < 8;j++){
            string tmp = to_hex(e.storage[i * 8 + j]);
            os << tmp[6] << tmp[7] << " " << tmp[4] << tmp[5] << " " << tmp[2] << tmp[3] << " " << tmp[0] << tmp[1] << " | ";
        }
        os << endl;
    }
    return os;
}

string Environment :: random_register() const{
    srand((int) time (NULL));
    int n = rand() % (general_registers.size() + special_registers.size());
    if (n < general_registers.size())   return "$" + to_string(n);
    else return special_registers[n - general_registers.size()].get_name();
}

string Environment :: random_address() const{
    srand((int) time (NULL));
    int n = rand() % storage.size();
    return to_string(n) + "(" + random_register() + ")";
}