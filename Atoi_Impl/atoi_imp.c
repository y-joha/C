/*********************************
 * Author: Yohai Azoulai			
 * ******************************/

#include <stdio.h> /* printf */
#include <ctype.h> /* isdigit - isupper */
#include <assert.h> /* assert */
#include "WS1011.h" 



static int StringConverter(const char *str, int base);
static int CharPartOfBase(const char *str, int base);
static void HasLetter(char *highest_letter,int base);

/*
The behavior of this function in cyclic, but will go to 
IntToAlpha - > performs a numeric based int to string convertions 
		based on fixed values in ASCII
AlphaToInt -> Check space/ - / + signs and negativ_str =>negative_str
    \
    StringConverter(returns the number back) to AlphaToInt
        \ 
        CharPartOfBase -> check str for correct letters & numbers 
        	\		to base test in while for in StringConvert
        	\
        	HasLetter(&higest_letter) -> recives base=>initialize 
        		\				   highest num/letter for base
        		\
        		IntToAlpha -> gives as return value back the char or number 
        				to be calculated as the char for numeric convertion
        				if its the stop to prevent from the int to recive
        				values the base cant handle.

*/


char *IntToAlpha(int number, char *str, int base)
{
    int str_pos = 0, i = 0, tmp = 0;
    int negativ_check = 0, remainder = 0;
    assert(str);

    if(0 == number)
    {
        *str = '0';
        *(str + 1) = '\0';
        return str;
    }

    if(number < 0 && base == 10)
    {
        negativ_check = 1;
        number *= (-1);
    }

    while(0 != number)
    {
       remainder = number % base;
       str[str_pos] = (remainder > 9)?(remainder - 10) + 'A': remainder + '0';
       number = number / base;
       ++str_pos; 
    }

    if(negativ_check)
    {
        str[str_pos] = '-';
        ++str_pos;
    }

    str[str_pos]='\0';
    /* Flips the string after adding null terminator*/
    for(i = 0; i < str_pos/2 ; ++i)
    {
        tmp=*(str+i);
        *(str+i)=*(str+(str_pos-i-1));
        *(str+(str_pos-i-1))=tmp;
    }

    return str;
}

int AlphaToInt(const char *str,int base)
{
    int number = 0, negativ_str = 1;
    assert(str);
    while(isspace(*str)){++str;}
    if('-'==*str)
    {
        negativ_str = -1;
        ++str;
    }
    if('+'==*str)
    {
        ++str;
    }
    number = StringConverter(str,base);

    return (number*negativ_str);
}

static int StringConverter(const char *str, int base)
{
    int number=0;
    assert(str);
    while(CharPartOfBase(str,base) && *str)
    {

        number = number * (base) + ((*str > '9')?(*str - ('A' - 10)):(*str - '0'));
        ++str;
    }

    return number;
}

static int CharPartOfBase(const char *str, int base)
{
    int flag = 0;
    char highest_letter = 0;
    assert(str);
    HasLetter(&highest_letter,base);
    if(isupper(*str)||isdigit(*str))
    {
        flag=1;
    }
    if(*str>=highest_letter)
    {
        flag=0;
    }

    return flag;
}
static void HasLetter(char *highest_letter,int base)
{
    /*Bases lower than 10, will not reach base digit*/
    assert(highest_letter);
    if(base<=10)
    {
        IntToAlpha(base-1,highest_letter,10);
    }
    else
    {
       IntToAlpha(base,highest_letter,36); 
    }
}


