XOR $1, $1, $1;
XOR $2, $2, $2;
XOR $3, $3, $3;
ADDI $3, $3, 5;
Label1:
    ADDI $2, $2, 1;
    ADD  $1, $1, $2;
    SLT $4, $2, $3;
    XORI $4, $4, 1;
    ADD $4, $4, PC;
    ADDI $4, $4, 2;
    JR $4;
JAL Label1;

Label2:
    JAL Label2;