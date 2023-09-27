/*********************************
 * Author: Yohai Azoulai			
 * ******************************/

#include "WS1011.h" 
#include <stdio.h> 
#include <stdlib.h> /*for the OG atoi*/

int main()
{
    int num=58;
    int base=36;
    char str[20]={0};
    char *string="46A5";
    char *string1="351";
    IntToAlpha(num,str,base);
    printf("This is the resulting string for base %d: %s\n",base,str);


    printf("MyAtoi base 10: %d\n",AlphaToInt(string, 10));
    printf("OGatoi: %d\n",atoi(string));

    printf("MyAtoi's number is %d in base %d\n",AlphaToInt(string1, base),base);

    return 0;
}
