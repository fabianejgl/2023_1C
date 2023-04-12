#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

// struct PCB;
// void Ke_context_switch(PCB* pcb_0, PCB* pcb_1);

//Process Control Block de un sistema operativo para arquitectura de 16bits
struct PCB {
    int STAT;
    int P_ID;
    int PC;
    int RO;
    int R1;
    int R2;
    int R3;
    int R4;
    int R5;
    int R6;
    int R7;
    int R8;
    int R9;
    int R10;
    int R11;
    int R12;
    int R13;
    int R14;
    int R15;
    int CPU_TIME;
} PCB;

struct PCB pcb_0 = {
    .STAT = 0,
    .P_ID = 9001,
    .PC = 1009,
    .RO = 0,
    .R1 = 0,
    .R2 = 1,
    .R3 = 0,
    .R4 = 0,
    .R5 = 1,
    .R6 = 0,
    .R7 = 0,
    .R8 = 1,
    .R9 = 0,
    .R10 = 0,
    .R11 = 1,
    .R12 = 0,
    .R13 = 0,
    .R14 = 0,
    .R15 = 0,
    .CPU_TIME = 0
};

struct PCB pcb_1 = {
    .STAT = 1,
    .P_ID = 9002,
    .PC = 1010,
    .RO = 0,
    .R1 = 0,
    .R2 = 0,
    .R3 = 1,
    .R4 = 1,
    .R5 = 1,
    .R6 = 0,
    .R7 = 0,
    .R8 = 0,
    .R9 = 0,
    .R10 = 1,
    .R11 = 1,
    .R12 = 1,
    .R13 = 1,
    .R14 = 1,
    .R15 = 1,
    .CPU_TIME = 1
};

void Ke_context_switch(struct PCB* pcb_0, struct PCB* pcb_1) {
    // Código de la función Ke_context_switch
    
}