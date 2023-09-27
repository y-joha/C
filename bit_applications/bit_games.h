/*********************************
 * Author: Yohai Azoulai			
 * ******************************/

#ifndef __BIT_GAMES_H__
#define __BIT_GAMES_H__

#include <stdio.h>
#include <stdbool.h>

#define FLOATSIZEARR 32
#define ARRSIZE 5
#define CHAR_BITS 8
#define TRUE 1
#define FALSE 0


void PrintInBinary(unsigned char n);
int BoolSwitch(bool a);
long Pow2(unsigned int a,unsigned int b);
int IsPwr(unsigned int n);
int IsPwrLoop(unsigned int n);
int Add1NoArithmatic(int a);
int Check3Set(unsigned int *arr);
unsigned int MirrorNumber(unsigned int a);
unsigned int MirrorNumberNoLoop(unsigned int a);
unsigned char AndFun(unsigned char a);
unsigned char OrFun(unsigned char a);
unsigned char Swap3rdWith5th(unsigned char a);
unsigned int BiggestDivOf16(unsigned int);
unsigned int SwapVars(unsigned int *a,unsigned int *b);
int IsSetLoop(int a);
int IsSetWithoutLoop(int a);
void FloatinBinary(float n);










#endif 
