#include <stddef.h>
#include <stdio.h>
#include "string.h"
#include <stdlib.h>


int main(void)
{
   size_t len;
   char *checker;
   char *checker2;
   char *checker3;
   char *checker4;
   char haystack[100] ="Eilo Tziporim Hyu Afot meaal ha Yam";
   char needle[100] ="Hyu";

   char *str = "0bcjds";
   char str2[50]={0};
   char str3[50]="ZeHaaharon";

   printf("%lu STRELN\n",StrLen("Ma "));
   printf("%dSTRCMP\n",StrCmp("abcMani","abcZibi"));
   StrnCpy(str2,str,3);
   printf("%s - copy first n letters\n",str2);
   StrCpy(str2,str);
   printf("%s Plain copy of string\n",str2);
   printf("%d - String N Compare\n",StrnCmp("abcMani","abcZibi",2));
   printf("%d - String Case Compare\n",StrCaseCmp("abcMani","aBcZibi"));
   printf("%p\n",StrChr("Abu-Fani",'F'));
   checker=StrDup("Zagazao");
   checker2=StrCat(str2,"321654");
   checker3=StrnCat(str3,"6022avogadro",5);
   checker4=StrStr(haystack,needle);
   printf("\n%s\n",checker);
   printf("\n%s\n",checker2);   
   printf("\n%s\n",checker3);
   printf("\n%s\n",checker4);
   len = StrSpn("arlo Tziporim Hyu Afot meaal ha Yam","aar");
   printf("\nThis is the result of StrSpn - %ld\n",len);
   free(checker);
   checker = NULL;

   


   
   return 0;
}



/* Why is it like this? */
