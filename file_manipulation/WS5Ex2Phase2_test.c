/*********************************
 * Author: Yohai Azoulai			
 * ******************************/
#include <stdio.h> /*printf , fgets */
#include <assert.h>
#include "WS5Ex2Phase2.h" 

work struc_array[] = 
{
    {"-remove\n", ComperaNator, Remover},
    {"-count\n", ComperaNator, Counter},
    {"-exit\n", ComperaNator, Exiter},
    {"<", Beninging, App2Start},
    {"?", ComperaNator, Append}
};

int main(int argc, char *argv[])
{
    char *filename = argv[1], usrinp[SIZE] = {'\0'};
    int flag = GO;

    assert(argv[1]);

    printf("Please enter input to program:\n");

    while(STOP != flag)
    {
        fgets(usrinp, SIZE, stdin);
        flag = OneRing(struc_array, NUM_OF_STRUCTS, filename, usrinp);
    }
    (void)argc;
    filename = NULL;
    return 0;
}
