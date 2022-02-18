/*
 * @Author: SuBonan
 * @Date: 2022-02-17 10:27:17
 * @LastEditTime: 2022-02-18 10:19:07
 * @FilePath: \naive-assembly\src\simos.cpp
 * @Github: https://github.com/SugarSBN
 * これなに、これなに、これない、これなに、これなに、これなに、ねこ！ヾ(*´∀｀*)ﾉ
 */
#include"../include/simos.h"
#include<iomanip>
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
    cout << "----------------welcome to the experiment platform----------------" << endl;
    string s;
    while(1){
        cin >> s;
        if (s == "clear" || s == "cls"){
            system("cls");
            continue;
        }
        if (s == "state"){
            cout << e << endl;
            continue;
        }
        if (s == "exec"){
            execute_one_command();
            continue;
        }
        if (s == "reboot"){
            SimOS(path);
            continue;
        }
        if (s == "now_command"){
            cout << boots[e.query_register("PC")] << endl;
            continue;
        }
        if (s == "register"){
            cin >> s;
            cout << e.query_register(s) << endl;
            continue;
        }
        if (s == "continue"){
            for (int i = 0;i < 100000;i++)  execute_one_command();
            continue;
        }
        if (s == "insts"){
            print_insts();
            continue;
        }
        if (s == "execn"){
            int t;  cin >> t;
            while(t--)  execute_one_command();
        }
        if (s == "quit"){
            break;
        }
    }
}

Environment SimOS :: get_env() const{
    return e;
}

void SimOS :: execute_one_command(){
    Instruction inst = boots[e.query_register("PC")];
    e.set_register("PC", e.query_register("PC") + 1);
    Opcode opt = inst.get_opcode();
    vector<Operand> operands = inst.get_operands();
    vector<int> int_ope;
    for (int i = 0;i < operands.size();i++) int_ope.push_back(operands[i].interprete(e, label_map));

    
    long long tmp;
    int quotient;
    if (opt < 5){
        switch (opt){
            case ADDI:
                e.set_register(operands[0].get_val(), int_ope[1] + int_ope[2]);
                break;
            case SUBI:
                e.set_register(operands[0].get_val(), int_ope[1] - int_ope[2]);
                break;
            case ANDI:
                e.set_register(operands[0].get_val(), int_ope[1] & int_ope[2]);
                break;
            case ORI:
                e.set_register(operands[0].get_val(), int_ope[1] | int_ope[2]);
                break;
            case XORI:
                e.set_register(operands[0].get_val(), int_ope[1] ^ int_ope[2]);
                break;
        }
    }else
    if (opt < 11){
        switch (opt){
            case ADD:
                e.set_register(operands[0].get_val(), int_ope[1] + int_ope[2]);
                break;
            case SUB:
                e.set_register(operands[0].get_val(), int_ope[1] - int_ope[2]);
                break;
            case OR:
                e.set_register(operands[0].get_val(), int_ope[1] | int_ope[2]);
                break;
            case AND:
                e.set_register(operands[0].get_val(), int_ope[1] & int_ope[2]);
                break;
            case XOR:
                e.set_register(operands[0].get_val(), int_ope[1] ^ int_ope[2]);
                break;
            case SLT:
                e.set_register(operands[0].get_val(), int_ope[1] < int_ope[2] ? 1 : 0);
                break;
        }
    }else switch (opt){
        case MUL:
            tmp = 1LL * int_ope[0] * int_ope[1];
            e.set_register("LO", tmp & 0xFFFFFFFF);
            e.set_register("HI", (tmp >> 32) & (0xFFFFFFFF));
            break;
        case DIV:
            quotient = int_ope[0] / int_ope[1];
            e.set_register("LO", quotient);
            e.set_register("HI", int_ope[0] - quotient * int_ope[1]);
            break;
        case MULI:
            tmp = 1LL * int_ope[0] * int_ope[1];
            e.set_register("LO", tmp & 0xFFFFFFFF);
            e.set_register("HI", (tmp >> 32) & (0xFFFFFFFF));
            break;
        case DIVI:
            quotient = int_ope[0] / int_ope[1];
            e.set_register("LO", quotient);
            e.set_register("HI", int_ope[0] - quotient * int_ope[1]);
            break;
        case LW:
            e.set_register(operands[0].get_val(), int_ope[1]);
            break;
        case SW:
            e.set_storage(int_ope[1], int_ope[0]);
            break;
        case JAL:
            e.set_register("ra", e.query_register("PC"));
            e.set_register("PC", int_ope[0]);
            break;
        case JR:
            e.set_register("PC", int_ope[0]);
            break;
        case LUI:
            e.set_register(operands[0].get_val(), int_ope[1] << 16);
            break;
        case RET:
            e.set_register("PC", e.query_register("ra"));
            break;
    }
}

void SimOS :: print_insts() const{
    for (int i = 0;i < boots.size();i++){
        if (!labels[i].empty()){
            for (int j = 0;j < labels[i].size();j++)    cout << labels[i][j] << ":" << endl;
        }
        cout << setw(10) << i << " | " << boots[i];
        if (i == e.query_register("PC"))    cout << " <--- " << endl;
        else cout << endl;
    }
}