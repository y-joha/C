#include <stdio.h>

int printdata(int arr[]);

int main(void)
{
	int arr[]=
		{
			sizeof(unsigned int),sizeof(int),sizeof(signed int),
			sizeof(short int),sizeof(unsigned short int),sizeof(signed short int),
			sizeof(long int),sizeof(signed long int),sizeof(unsigned long int),
			sizeof(float),sizeof(unsigned char),sizeof(char),
			sizeof(signed char),sizeof(double),sizeof(long double)
		};
	printdata(arr);
	return 0;
}

int printdata(int arr[])
	{
		while(*arr)
		{
			fprintf(stdout,"unsigned int %d\n",*arr);
			fprintf(stdout,"int %d\n",*(arr+1));
			fprintf(stdout,"signed int   %d\n",*(arr+2));
			fprintf(stdout,"short int %d\n",*(arr+3));
			fprintf(stdout,"unsigned short int %d\n",*(arr+4));
			fprintf(stdout,"signed short int %d\n",*(arr+5));
			fprintf(stdout,"long int %d\n",*(arr+6));
			fprintf(stdout,"signed long int %d\n",*(arr+7));
			fprintf(stdout,"unsigned long int %d\n",*(arr+8));
			fprintf(stdout,"float %d\n",*(arr+9));
			fprintf(stdout,"unsigned char %d\n",*(arr + 10));
			fprintf(stdout,"char %d\n",*(arr + 11));
			fprintf(stdout,"signed char %d\n",*(arr + 12));
			fprintf(stdout,"double %d\n",*(arr + 13));
			fprintf(stdout,"long double %d\n",*(arr + 14));	
			fprintf(stdout,"\nC99 does not support long long varient\nsizeof(void) puts out an error\n");
			fprintf(stdout,"Thats all folks...\n");
			break;
		}
		return 0;
	}