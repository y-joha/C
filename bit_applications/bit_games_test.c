/*********************************
 * Author: Yohai Azoulai			
 * ******************************/

#include "bit_games.h" 

int main(int argc, char *argv[])
{
    int g = 215;
    float f = 15.52;
    unsigned int x = 2,y = 256;
    unsigned int *ptrx = &x,*ptry = &y;
    unsigned int arry[] = {14, 7, 11, 6, 27};
    unsigned char letter = 'k';
    printf("\nExcercise 1 :\n");
    printf("the result is %ld\n",Pow2(x,y));
    printf("**********END of Ex1**********:\n");
  
    printf("\nExcercise 2 :\n");
    printf("\nthe result is %d\n",IsPwr(x));
    printf("the result is %d\n",IsPwr(y));
    printf("the result is %d\n",IsPwrLoop(y));
    printf("**********END of Ex2**********:\n");    
 
    printf("\nExcercise 3 :\n");
    printf("\nAdd1NoArithmatic check gets the number 3 + 1 is? - %d\n", Add1NoArithmatic(3));
    printf("**********END of Ex3**********:\n");
 
    printf("\nExcercise 4 :\n");
    printf("\nCheck3Set checks for 3 set bits in a number\n"); 
    Check3Set(arry);
    printf("**********END of Ex4**********:\n");

    printf("\nExcercise 5 :\n");
    PrintInBinary(11);
    printf("\na.) revesred with loop order of bits of the number\n");
    PrintInBinary(MirrorNumber(11));
    printf("\nb.) revesred with loop order of bits of the number\n");
    PrintInBinary(MirrorNumberNoLoop(11));
    printf("**********END of Ex5**********:\n");
    
    printf("\nExcercise 6 :\n");
    printf("\nThe letter %c in binary is -\n",letter);
    PrintInBinary(letter);
    printf("Are bit 6 & 2 are lit? **%d**[0 == FALSE]\n",AndFun(letter));
    letter = 'd';
    printf("\nThe letter %c in binary is -\n",letter);
    PrintInBinary(letter);    
    printf("Are bit 6 & 2 are lit? **%d**[0 == FALSE]\n",AndFun(letter));
    PrintInBinary(letter);    
    printf("Are either one of bits 6 & 2 are lit? **%d**[0 == FALSE]\n",OrFun(letter));
    letter = 'I';
    printf("\nThe letter %c in binary is -\n",letter);
    PrintInBinary(letter); 
    printf("Are either one of bits 6 & 2 are lit? **%d**[0 == FALSE]\n",OrFun(letter));
    letter = 'd';
    printf("\nThe letter %c in binary is -\n",letter);
    PrintInBinary(letter); 
    printf("The char resulting in the switch of 3rd & 5th bit\nIs - %c\n",Swap3rdWith5th(letter));
    letter = Swap3rdWith5th(letter);
    PrintInBinary(letter);
    printf("**********END of Ex6**********:\n");
    
    printf("\nExcercise 7 :\n");
    printf("\n\nThis is biggest smaller diviosor bit\n");
    x = 389;
    printf("\nSmallest divisor of %d is %d\n",x,BiggestDivOf16(x));
    printf("**********END of Ex7**********:\n");

    printf("\nExcercise 8 :\n");
    printf("\n x - %u, y - %u \n",*ptrx,*ptry);
    SwapVars(ptrx, ptry);
    printf("\n x - %u, y - %u \n",*ptrx,*ptry);
    printf("\n x - %u\n",*ptrx);    
    printf("\n");
    printf("**********END of Ex8**********:\n");
    
    printf("\nExcercise 9 :\n");
    PrintInBinary(g);
    printf("This how many 1 are set in the number %d == %d\n",g,IsSetLoop(g));
    printf("This how many 1 are set in the number %d == %d\n",g,IsSetWithoutLoop(g));
    printf("**********END of Ex9**********:\n");
    
    printf("\nExcercise 10 :\n");
    printf("The number printed is - %f\n", f);
    FloatinBinary(f);    
    printf("\n**********END of Ex10**********:\n");


    (void)argc;
    (void)argv;
    return 0;
}
