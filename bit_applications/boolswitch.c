#include <stdio.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0


bool BoolSwitch(bool a)
{
	switch(a)
	{
		case TRUE:
		a = FALSE;
		break;
		case FALSE:
		a = TRUE;
		break;
	}
	return a;
}


int main(void)
{
	bool nimi = TRUE;
	printf("The value of nimi is - %i\n",nimi);

	nimi = BoolSwitch(nimi);
	printf("The value of nimi after boolero is - %i\n",nimi);

	return 0;
}
