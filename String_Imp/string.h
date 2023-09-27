#ifndef __STRING_H__
#define __STRING_H__
#include <stddef.h>
#include "string.h"



size_t StrLen(const char *s);
int StrCmp(const char *s1,const char *s2);
char *StrCpy(char *a,char *b);
char *StrnCpy(char *a,char *b,size_t n);
int StrnCmp(const char *s1,const char *s2,size_t n);
int StrCaseCmp(const char *s1, const char *s2);
int StrnCaseCmp(const char *s1, const char *s2, size_t n);
char *StrChr(const char *s1, int c);
char *StrDup(const char *s);

char *StrCat(char *dest, const char *src);

char *StrnCat(char *dest, const char *src, size_t n);

char *StrStr(const char *haystack, const char *needle);

size_t StrSpn(const char *s, const char *accept);

/*
This is an advanced func  char *strtok(char *str, const char *delim);


*/

#endif /* __STRING_H__ */

