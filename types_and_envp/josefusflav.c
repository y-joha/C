#include <stdio.h>
#include <stdlib.h>

void josephos(int *arr,int s);

int main()
{
	int size;
	int *ptarr;

	printf("Please enter a number of soldiers - \n");
	scanf("%d",&size);
	ptarr = (int *)malloc(sizeof(int) * size);

	josephos(ptarr, size);

	free(ptarr);
	ptarr = NULL;

	return 0;
}



void josephos(int *arr,int s)
{
	int i = 0,herev = 1;
	while(i < s)
	{
		*(arr + i) = i + 1;
		++i;
	}
	*(arr + s - 1) = 0;
	printf("\n");
	i=0;
	while(*(arr + i) != i)
	{
		if (*(arr + i) == -1 || *(arr + *(arr+i)) == -1)
		{
			++i;
		}
		else
		{
			herev = *(arr + *(arr+i));
			*(arr + *(arr+i)) = -1;
			*(arr + i) = herev;
			i = herev;
		}
	}
	printf("\nWHAT DID YOUUUU DO RAYMOND\n");
	printf("%d <- he is the last guy\n",i+1);
	/*while(i < s)
	{
		printf("%d  ",*(arr + i));
		i++;
	}*/
}