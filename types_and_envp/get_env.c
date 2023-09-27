#include <stdio.h>
#include <stdlib.h> /* for the use of size_t */
#include <string.h> /* for the use of string copy*/ 
#include <ctype.h>  /* this is for tolower */

/* you changed till here*/


size_t envlen(char **envp);
void copyenv(char **ptr, char **envp);
void lowerenv(char **ptr, size_t size);
void prtenv(char **ptr, size_t size);
void freee(char **ptr, size_t size);

int main(int argc,char **argv, char **envp)
{
	size_t lenenv = envlen(envp);
	size_t i = 0;
	char **buffer = NULL;
	printf("%ld \n",lenenv);
				/* pointer array malloc declarations */
				/* using envlen to meassure point arry size */
	buffer = (char **)malloc((lenenv + 1) * sizeof(char *));
	if (buffer == NULL)
		{
			return -1;
		}
				/* each string malloc declarations */
	for(i = 0; i < lenenv + 1; ++i)
	{
		*(buffer + i) = (char *)malloc((strlen(*(envp + i)) + 1) * sizeof(char));
		if (*(buffer + i) == NULL)
		{
			return -1;
		}
	}
				/* now copy data to buffer*/
	copyenv(buffer,envp);
				/* lowercase all letters buffer*/	
	lowerenv(buffer,lenenv +1);
				/* print buffer*/
	prtenv(buffer,lenenv +1 );
				/* free malloc allocations*/
	freee(buffer,lenenv + 1);
				/* verify no danglers*/
	buffer = NULL;


	printf("\n");
	printf("alll done buddy, now go save the world\n");
	(void)argc;
	(void)argv;
	free(buffer);
	return 0;
}

size_t envlen(char **envp)
{
	size_t size = 0;
	while (*++envp != NULL)
	{
		++size;
	}
	return (size);
}

void copyenv(char **ptr, char **envp)
{
	while(*envp != NULL)
	{
		strcpy(*ptr++, *envp++);
	}
}

void lowerenv(char **ptr, size_t size)
{
	size_t i = 0;
	size_t j = 0;
	for(i = 0 ; i < size ; i++)
		for(j = 0 ; *(*(ptr+ i) + j) != '\0'; j++)
		{
	  		*(*(ptr+i)+j) = tolower(*(*(ptr + i)+j));
		}
}

void prtenv(char **ptr, size_t size)
{
	size_t i = 0;
	while(i < size)
	{
		printf("%s\n",*(ptr + i));
		++i;
	}
}

void freee(char **ptr, size_t size)
{
	size_t i = 0;
	while(i < size)
	{
		free(*(ptr + i));
		++i;
	}
	free(ptr);
}
