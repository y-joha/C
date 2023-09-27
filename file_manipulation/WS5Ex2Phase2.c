/*********************************
 * Author: Yohai Azoulai			
 * ******************************/
#include <stdio.h>
#include <string.h>
#include "WS5Ex2Phase2.h"

int OneRing(work arr[], int num, char * filename, char *usrinput)
{
    /* this needs to recive the parameters */
    int i = 0;
    for ( i = 0; i < num-1; ++i)
    {
        if(GO == arr[i].ptrComp(arr[i].mark,usrinput))
        {
            printf("%din loop\n",i );
            return arr[i].ptrFun(filename,usrinput);
        }
    }
    printf("%d after loop\n",i );
    return arr[i].ptrFun(filename,usrinput);
}

int ComperaNator(char * arr, char *usrinput)
{
    printf("%d\n",strcmp(arr,usrinput));
    return (GO == strcmp(arr,usrinput))? GO : STOP;
}

int Remover(char * filename, char *usrinput)
{
    /* need to remove & close the file */
    (void)usrinput;
    remove(filename);
    return GO;
} 

int Counter(char * filename, char *usrinput)
{
    /* this counts the current   */
    FILE *OG = fopen(filename, "r");
    int countline = 0;
    char c = fgetc(OG);

    if(NULL == OG)
    {
        printf("%s file couldnt be open\n", filename);
        return STOP;
    }

    while (c != EOF)
    {
        if('\n' == c)countline++;
        c = fgetc(OG);
    }
    printf("Num of lines : %d\n",countline);
    fclose(OG);
    OG = NULL;

    (void)usrinput;
    return GO;
}

int Exiter(char * filename, char *usrinput)
{
    /* exits the program via flag (returns 1 instead of 0) */
    (void)filename;
    (void)usrinput;
    return STOP;
}

int Beninging(char * arr, char *usrinput)
{
    size_t onlyfirstchar = 1;
    printf("%d\n",strncmp(arr,usrinput,onlyfirstchar));

    return (GO == strncmp(arr,usrinput,onlyfirstchar))? GO : STOP;
}

int App2Start(char * filename, char *usrinput)
{
    /* this just appends to begnining but after test with uniqe func Beningning*/
    char c;
    char *Tmp = "/tmp/Temp.txt";
    FILE *OG, *Temp;

    OG = fopen(filename, "r+");
    if(NULL == OG)
    {
        printf("%s file couldnt be open\n", filename);
        return STOP;
    }
    Temp = fopen(Tmp,"w+"); /* because of w+ need to use fseek end */
    if(NULL == Temp)
    {
        printf("%s file couldnt be open\n", Tmp);
        return STOP;
    }

    /* puts the string at the begining of the file*/
    fputs(usrinput, Temp);
    /* Puts the OG File into TEMP*/
    while (EOF != (c = fgetc(OG)))
    {
        fputc(c,Temp);
    }
    /* This puts the pointer 1 pos after < at begining of file */
    fseek(Temp, 1, SEEK_SET);
    if(0 != fseek(Temp, 1, SEEK_SET))
    {
        printf("%s pointer wasnt moved past < in Temp File\n", Tmp);
        return STOP;
    }
    fseek(OG, 0, SEEK_SET);
    while (EOF != (c = fgetc(Temp)))
    {
        fputc(c,OG);
    }

    fclose(OG);
    OG = NULL;
    fclose(Temp);
    remove(Tmp);
    Tmp = NULL;
    return GO;
}

int Append(char * filename, char *usrinput)
{
    /* this run after Ending ! */
    FILE *OG;
    OG = fopen(filename, "a+");
    if(NULL == OG)
    {
        printf("%s file couldnt be open\n", filename);
        return STOP;
    }
    fputs(usrinput,OG);

    fclose(OG);
    OG = NULL;
    return GO;
}
