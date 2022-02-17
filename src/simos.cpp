/*
 * @Author: SuBonan
 * @Date: 2022-02-17 10:27:17
 * @LastEditTime: 2022-02-17 12:09:56
 * @FilePath: \naive-assembly\src\simos.cpp
 * @Github: https://github.com/SugarSBN
 * これなに、これなに、これない、これなに、これなに、これなに、ねこ！ヾ(*´∀｀*)ﾉ
 */
#include"../include/simos.h"

SimOS :: SimOS(string path){
    boot_path = path;
    Parsor p = Parsor(path);
    boots = p.get_insts();
    labels = p.get_labels();
    e = Environment("MIPS_32", 512);
    label_map.clear();

    for(int i = 0;i < labels.size();i++)
        for (int j = 0;j < labels[i].size();j++)    
            label_map[labels[i][j]] = i;
}

void SimOS :: boot(){
    for (int i = 0;i < boots.size();i++)    e.set_storage(i, boots[i].to_bitcode(label_map));
    e.set_register("$7", boots.size());
    e.set_register("PC", 0);
}

Environment SimOS :: get_env() const{
    return e;
}