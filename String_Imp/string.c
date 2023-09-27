#include "string.h" /* Why is it like this? */
#include <assert.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

size_t StrLen(const char *s)
{
    size_t counter = 0;
    assert(s);
    
    while('\0' != *s)
    {
        s++;
        counter++;
    }

    return counter;
}

int StrCmp(const char *s1,const char *s2)
{
	int result = 0;

	assert(s1);
	assert(s2);
	
	while (0 != *s1 && 0 != *s2)
	{		
		if(*s1 != *s2)
		{
			result = *s1 - *s2;
			return result * ((result>0) - (result<0))/result;
		}
		
		s1++;
		s2++;

	}
	/*  this was return 0 before change*/
	return result * ((result>0) - (result<0))/result;
}

char *StrCpy(char *a,char *b)
{
	while(*b != '\0')
	{
		*a = *b;
		++a;
		++b;
	}
	return a;
}

char *StrnCpy(char *a,char *b,size_t n)
{
	while(0 < n && '\0' != *b)
	{
		*a = *b;
		++a;
		++b;
		--n;
	}
	return a;
}

int StrnCmp(const char *s1,const char *s2,size_t n)
{
	int result = 0;

	assert(s1);
	assert(s2);
	
	while (0 != *s1 && 0 != *s2 && 0 < n)
	{		
		if(*s1 != *s2)
		{
			result = *s1 - *s2;
			return result/(result * ((result>0) - (result<0)));
		}
		
		++s1;
		++s2;
		--n;
	}

	return 0;
}

int StrCaseCmp(const char *s1, const char *s2)
{
	int result = 0;

	assert(s1);
	assert(s2);
	
	while (*s1 && *s2)
	{		
		if(tolower(*s1) != tolower(*s2))
		{
			result = *s1 - *s2;
			return result/(result * ((result>0) - (result<0)));
		}
		
		++s1;
		++s2;
	}

	return 0;	
}


int StrnCaseCmp(const char *s1, const char *s2, size_t n)
{
	int result = 0;

	assert(s1);
	assert(s2);
	
	while (*s1 && *s2 && 0 < n)
	{		
		if(tolower(*s1) != tolower(*s2))
		{
			result = *s1 - *s2;
			return result/(result * ((result>0) - (result<0)));
		}
		
		++s1;
		++s2;
		--n;
	}

	return 0;
}

char *StrChr(const char *s1, int c)
{
	
	assert(s1);

	
	while (*s1)
	{		
		if(*s1 == c)
		{
			return (char *)s1;
		}
		
		++s1;
	}
	return NULL;
}

char *StrDup(const char *s1)
{
	size_t size = StrLen(s1)+1;
	char *shead = NULL;
	char *s2=(char *)malloc(sizeof(char)*size);
	assert(s1 && s2);
	
	shead = s2;
	
	/*		
	while(*s1 != '\0')
	{
		*s2 = *s1;
		++s2;
		++s1;
	}*/
		
	while(*s1)
		{
			*s2 = *s1;
			++s1;
			++s2;
		}
		*s2 = '\0';

	return shead;
}

char *StrCat(char *s1, const char *s2)
{
	
	char *shead= s1;
	assert(s1 && s2);
	/* added commnt from line 189 till 196 */
	/*do
	{
		++s1;
	} while (*s1);

	while(*(s1++));
	s1--;*/
	while(*s2)
		{
			*s1 = *s2;
			++s1;
			++s2;
		}
	*s1 = '\0';
	return shead;
}

char *StrnCat(char *s1, const char *s2, size_t n)
{
	
	char *shead= s1;
	assert(s1 && s2);
	do
	{
		++s1;
	} while (*s1);

	/*while(*(s1++));
	s1--;*/
	while(*s2 && n!=0)
		{
			*s1 = *s2;
			/* removed ++s1 from this while */
			++s2;
			--n;
		}
	*s1 = '\0';
	return shead;
}

char *StrStr(const char *haystack, const char *needle)
{	
	size_t len =(assert(needle),StrLen(needle));
	assert(haystack);

	while(*haystack)
	{
		if (!StrnCmp(haystack,needle,len))
		{
			return(char *)haystack;
		}
		++haystack;
	}
	return NULL;
}



/*
{
    int i = 0, j = 0;
    char *flag;
    int shay = StrLen(haystack);
    int sneed = StrLen(needle);
    if(shay < sneed)
    {
    	printf("No can do buckaroo");
    	exit(0);
    }
	while ('\0' != *haystack|| '\0' != *needle) 
    {
        if (needle[i] != haystack[j]) 
        {
            j++;
            i = 0;
        }
        else if (haystack[j+i] == needle[i])
        {
        	i++;    
        }
    }
    if ('\0' == needle[i])
    	{
            return (char *)flag;
            exit(0);
        }
    else 
        printf("no needle here buckaroo");
        return 0;
}

	size_t size = StrLen(needle);
	const char *where;
	while (*haystack)
	{
		where = haystack;
		if(StrnCmp(needle,haystack,size) && *needle)
		{
			return where;
		}
		else
			haystack++;
		while(*needle != *haystack)
		{
			++haystack;
		}
		char *hathala = haystack
		
			while(*needle)
			{
				if(*needle == *haystack)
				{
					haystack++;
					needle++;					
				}

			}
			return hathala;
			exit(0);	
		
	}
	printf("Thats an empty haystack Umbre");
	return haystack;
}
*/
size_t StrSpn(const char *s, const char *accept)
{
	size_t efo = 0;
	assert(s && accept);
	
	while(*s)
		{
			if (StrChr(accept,*s++))
			{
				efo++;
			}
			else
			{
			return efo;
			}
	
		}
	return efo;
}