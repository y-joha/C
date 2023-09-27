
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define  SIZE 1024
#define  ComndArr 8

void Appenditzit(char *filename ,char *input); /* This works */

void YeshMeain(char *filename); /* This works */

int ComperaNator(char *src,char *dest); /* This works */

int Remover(char *filename); /* This works */

int Counter(char *filename); /* This works */

int Exiter(char *filename); /* This works */

int App2Start(char *filename); /* This works */


	/* Phase 1  */
	/* Requirments -> 
	a.) needs to recive name of file as parameter ("a.out  maydoff.txt")
	b.) need to use fopen & fclose on every time i contact the file
	c.) for every string entered, the prog need to append string (a+) */

	/* Phase 2  */
	/* Requirments -> add functionality for special inputs 
	   -remove - the file should be deleted(remove())
	   -count  - the program should open the file, count the number of lines
	   			 and print that number to terminal.(ftell + echo?)
	   -exit   - the program should close (test to exit run loop)
	   < @ start-the string will be appended at begining (fseek)
		implementation - array of structs
		struct contain - string and two function pointers (comparison & operation)
		etarate over the array and given the input, run comparison & run function)


	   */

int main(int argc, char *argv[])
{
	
	int i= 0,flag = 1;
	char *filename = argv[1];
	char etmi[SIZE];
	
	typedef struct 
		{
			char *arr;
			int (*ptr_compfun)(char *,char *);
			int (*ptr_oprfun)(char *);
		}dostuff;

	dostuff runstuff[] =
	{
		{"-remove\n", ComperaNator, Remover},
		{"-count\n", ComperaNator, Counter},
		{"-exit\n", ComperaNator, Exiter},
		{"<", ComperaNator, App2Start},
	};
	(void)argc;
	YeshMeain(filename);
	printf("Enter a sentance to attach:\n");
	

	fflush(stdin);
	while(0 != flag)
	{
			fgets(etmi,SIZE,stdin);

		for(i = 0;i < 4; ++i)
		{
			if(0 == runstuff[i].ptr_compfun(etmi,runstuff[i].arr))
			{
				printf("This is the result of the compare %d\n",runstuff[i].ptr_compfun(etmi,runstuff[i].arr) );
				runstuff[i].ptr_oprfun(filename);
				if (2 == i && 0 == runstuff[i].ptr_compfun(etmi,runstuff[i].arr))
				{
					flag = runstuff[i].ptr_compfun(etmi,runstuff[i].arr);
					break;
				}
			}
		}
		Appenditzit(filename, etmi);
	}


	return 0;
}

void Appenditzit(char *filename ,char *input)
{
	FILE *pyr;
	size_t members = 1;
	pyr = fopen(filename, "a");
	if (pyr == NULL)
    {
        printf("ERROR: Cannot open input file.\n");
        exit(1);
    }
	fwrite(input, strlen(input) * sizeof(*input), members, pyr);
	fclose(pyr);
}

void YeshMeain(char *filename)
{
	FILE *pyr;
	pyr = fopen(filename, "a+");
	if (pyr == NULL)
    {
        printf("ERROR: Cannot open input file.\n");
        exit(1);
    }
	fclose(pyr);
}



int ComperaNator(char *src,char *dest)
	{
		return strcmp(src,dest);
	}

int Remover(char *filename)
	{
		remove(filename);
		return 1;
	}

int Counter(char *filename)
{
    FILE *pyr = fopen(filename, "r");
    int countlines = 1;
    char c = fgetc(pyr);

    if (pyr == NULL)
    {
        printf("%s file does not found", filename);
        return 0;
    }

    while(c != EOF)
    {
        if('\n' == c)
        {
            countlines++;
        }
        c = fgetc(pyr);
    }
    printf("\nthe line number at the file is:%d\n", countlines);
    fclose(pyr);
    return 1;
}


int Exiter(char *filename)
{
	(void)filename;
	return 0;
}

int App2Start(char *filename)
{
	char arrtofill[SIZE];
	char c;
	FILE *fp1, *fp2;
/* Open two files to be merged */
	fp1 = fopen(filename, "r+");
	fp2 = fopen("tempo.txt", "w+");

	fgets(arrtofill, SIZE, stdin);

	if (fp1 == NULL && fp2 == NULL)
	{
		puts("Could not open files");
		exit(0);
	}

/*	writing the string into the Temp File */
		fputs(arrtofill, fp2);

/* Copy contents of OG into Temp File */
		 /*   Appended into Temp  */
	while ((c = fgetc(fp1)) != EOF)
		{	
			fputc(c, fp2);
			fseek(fp1,0,SEEK_SET);
			fseek(fp2,0,SEEK_SET);
		}
		fseek(fp2,1,SEEK_SET);
/* Copy contents of second file to file3.txt */
	while ((c = fgetc(fp2)) != EOF)
		{
			fputc(c,fp1);
		}

	printf("Merged User Input and given file into temporery\n");
	printf("and back into original again\n");

	fclose(fp1);
	fclose(fp2);
	fp2 = NULL;
	remove("tempo.txt");
	return 1;
}







/* 

while(1)
{
	fgets(etmi,SIZE,stdin);

	for(i=0;i<4;++i)
	{
		if(0 == runstuff[i].ptr_compfun(etmi,runstuff[i].arr));
		{
			runstuff[i].ptr_oprfun(filename);
			flag = 1;
		}
	}
	if(1 != flag)
	{
		printf("Anything else to add buddy?");
		fgets(etmi,SIZE,stdin);
		Appenditzit(argv[1], etmi);
	}
}   */
