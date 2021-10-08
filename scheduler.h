/*
 *
 *
 * CS 441/541: CPU Scheduler
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>


/******************************
 * Defines
 ******************************/
#define LINELEN 256

/******************************
 * Structures
 ******************************/
 struct process
 {
   int procId;
   int cpuBurst;
   int prior;
 };

/******************************
 * Global Variables
 ******************************/
 int check = 0;
 int numProc;
 int num;
 int quan;
 char alg[8];   //enough space for the word 'priority'
 int * tTime;
 int * wTime;
 int * waitNum;
 int totalT;
 int totalW;
 float avgW;
 float avgT;

/******************************
 * Function declarations
 ******************************/
