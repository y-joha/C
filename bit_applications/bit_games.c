/*********************************
 * Author: Yohai Azoulai			
 * ******************************/

#include "WS6Ex1.h"

/* Boolian addition : bool switch for help*/
bool BoolSwitch(bool a)
{
    switch(a)
    {
        case TRUE:
        a = FALSE;
        break;
        case FALSE:
        a = TRUE;
        break;
    }
    return a;
}

    /* Printing out the number in binary */
void PrintInBinary(unsigned char n)
{
    char a = ' ';

    for(a = CHAR_BITS - 1 ; a >= 0 ; --a)
    {
        (n & (1 << a))? printf("1"): printf("0");
    }
    printf("\n"); 
}
/* Excersice 1*/
long Pow2(unsigned int a,unsigned int b)
{
    return a<<b;
}
/* Excersice 2 no loop*/
int IsPwr(unsigned int n)
{
    return (n&(n-1)) == 0? 1 : 0;
}
/* Excersice 2 With loop (basicly the whole i=i*2 bit) */
int IsPwrLoop(unsigned int n)
{
    unsigned int i;
    int pow = 0;
    for(i=1; i<=n; i=i*2, pow++);
    if(0 == i%2)
    {
        return 1;
    }

    return 0;
}

/* Excersice 3 -> creat function that adds 1 without arithmatics*/
int Add1NoArithmatic(int a)
{
    int b = 1;
    
     /*Flip all the set bits*/
    while(a & b)
    {
        a = a ^ b;
        b <<= 1;
    }
    
     /*flip the rightmost 0 bit*/
    a = a ^ b;
    return a;
}
    /* Exc 4 Find the number represented by 3 set bits */
int Check3Set(unsigned int *arr)
{
    int i = 0, count = 0;
    unsigned int tmp = 0;
    while(i < ARRSIZE)
    {    
        tmp = arr[i];
        count = 0;
        while(0 != tmp)
        {
            count += tmp & 1;
            tmp >>= 1;
            if(3 < count)break;
        }
        if(3 == count)
        {
            printf("the number %d had 3 set bits\n",arr[i]);
        }
        i++;
    }
    return 0;
}

    /* EX5 - Mirror the number using a loop (a) */
unsigned int MirrorNumber(unsigned int a)
{
    size_t i = 0; 
    char result = 0; 
    size_t iLoopStep = CHAR_BITS - 1;
  
    for(i = 0; i < iLoopStep; ++i)
    {      
        if((a & (1 << i))) 
        {
            result |= 1 << ((CHAR_BITS - 1) - i); 
        }    
    }
    return result;
}

    /* Mirror the number without the loop (b) this works for 8 bits numbers*/
unsigned int MirrorNumberNoLoop(unsigned int a)
{
    a = (((a & 0xaa) >> 1) | ((a & 0x55) << 1));
    a = (((a & 0xcc) >> 2) | ((a & 0x33) << 2));
    
    return((a >> 4) | (a << 4));
}

    /* Ex 6 - create a program that checks 2nd & 6th */
unsigned char AndFun(unsigned char a)
{
    unsigned char x = 0;
    unsigned char y = 0;

    /*masking for 2th and 6th* - 0x22 = 00100010*/
    x = a & 0x22;
    y = x >> 5;
    x >>= 1;
    return(x & y);
}

unsigned char OrFun(unsigned char a)
{
    unsigned char x = 0;
    unsigned char y = 0;

    /*using bit-masking for 2th and 6th positions*/
    x = a & 0x2;
    y = a & 0x32;
    x >>= 2;
    y >>= 5;
    return(x | y);
}

unsigned char Swap3rdWith5th(unsigned char a)
{
    unsigned char x3 = 0, y5 = 0,temp = 0;
    x3 = (a >> 2) & 0x1;
    y5 = (a >> 4) & 0x1;
    temp = x3 ^ y5;
    a = a ^ (temp << 2);
    a = a ^ (temp << 4);
    return a;
}


    /* Ex7 - give the biggest divisor of 16 of a number */
unsigned int BiggestDivOf16(unsigned int a)
{
    a >>= 4;
    a <<= 4;

    return a;
}

    /* Ex8 - Swap variables
    The limitations of use for this method is
    the bit size' meaning if i go towards the very end of the bit
    i'm in danger of "spilling" over and writing in the wrong memory */
unsigned int SwapVars(unsigned int *a,unsigned int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
    return *a;
}

    /*Ex9 part1 - Finding 1 with loop*/
int IsSetLoop(int a)
{
    unsigned int i = 0; 
    int count = 0;
    int tmp = 0;
    while(i < ((sizeof(a)*CHAR_BITS) - 1))
    {    
        tmp = a;
        count = 0;
        while(0 != tmp)
        {
            count += tmp & 1;
            tmp >>= 1;
        }
        i++;
    }
    return count;
}

    /*part 2 - without using the loop -> LUT*/
int IsSetWithoutLoop(int a)
{
    int LuTable[16] = {0, 1, 1, 2, 1, 2, 2, 3, 1,
                       2, 2, 3, 2, 3, 3, 4};
    if (0 == a)
    {
        return LuTable[0];
    }
    /* This provides me with */
    return (
    		LuTable[a & 15] + 
    		LuTable[(a >> 4) & 15] + 
    		LuTable[(a >> 8) & 15] + 
    		LuTable[(a >> 12) & 15] + 
    		LuTable[(a >> 16) & 15] + 
    		LuTable[(a >> 20) & 15] + 
    		LuTable[(a >> 24) & 15] + 
    		LuTable[(a >> 28) & 15]);
}

    /*Ex- 10 Float analysis*/
void FloatinBinary(float a)
{
    int *ptra = (int *) & a;
    int current_bit = 0;
    int i = CHAR_BITS * sizeof(a) - 1;
    for( ; i>=0; --i)
    {
        current_bit = (*ptra >> i) & 1;
        printf("%d", current_bit);
    }
}








