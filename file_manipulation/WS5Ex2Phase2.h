/*********************************
 * Author: Yohai Azoulai			
 * ******************************/

#ifndef __WS5EX2PHASE2_H__
#define __WS5EX2PHASE2_H__

#define SIZE 1024
#define NUM_OF_STRUCTS 5

enum RUNSTAT {GO, STOP};

typedef struct
{
    char mark[SIZE];
    int (*ptrComp)(char *, char*);
    int (*ptrFun)(char *, char*);
}work;

/* the functions to run   */ 
int OneRing(work arr[], int num, char * filename, char *usrinput);
int ComperaNator(char * arr, char *usrinput);
int Beninging(char * arr, char *usrinput);
int Remover(char * filename, char *usrinput); 
int Counter(char * filename, char *usrinput);
int Exiter(char * filename, char *usrinput);
int App2Start(char * filename, char *usrinput);
int Append(char * filename, char *usrinput);

#endif 
