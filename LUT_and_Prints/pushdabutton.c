#include <stdio.h>
int system(const char *command);
void SwitchFun();
void empty();
void APressed();
void TPressed();
void IfsFun();
void LUTFun();



    /* Excs 1 unsing a switch case */
int main(void)
{
	system("stty -echo -icanon");
	
	SwitchFun();
	IfsFun();
	LUTFun();
	
	system("stty echo icanon");
	return 0;
}

void SwitchFun()
{
	char test;
	printf("Hey Buddy, Push da Button\n");
	while((test = getchar()) != 27 )
	{
		switch(test)
		{
			case 'A':
			printf("A Was Pressed :D\n");
			break;
			case 'T':
			printf("T Was Pressed :D\n");
			break;
			case 'a':
			printf("Pressed lower case A but ok :D\n");
			break;
			case 't':
			printf("Pressed lower case T but ok :D\n");
			break;
		}
	}
}

	/* using ifs */

void IfsFun()
{
	char test;
	printf("Gib Letr plz\n");
	while((test = getchar()) != 27 )
	{
		if('A' == test || 'a' == test)
		{
			printf("A-Pressed\n");
		}
		else if('T' == test || 't' == test)
		{
			printf("T-Pressed\n");
		}
	}
	printf("Thank you for playing our game\nSalamat\n");
}
	
	
	/* using LUT's */
void LUTFun()
{
	int i=0;
	int c=' ';
	void (*p[128])();
	for(i = 0; i < 128; ++i)
	{
		p[i] = empty;
	}
	p[65]=APressed;
	p[84]=TPressed;
	
	while((c = getchar())!= 27)
	{
		(*p[c])();
	}
}

void TPressed()
{
	printf("You pressed T\n");
}
void APressed()
{
	printf("You pressed A\n");
}
void empty(){}
