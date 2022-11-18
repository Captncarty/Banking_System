#include "bank.h"

/**
 * main - Entry point
 * Return: Always 0 (success)
 */

int main()
{
	char pass[10],password[8]="Welcome";
	int i=0;

	printf("\n\n\t\tEnter the password to login: ");
	scanf("%s",pass);
    
	/*do
    {
    //if (pass[i]!=13&&pass[i]!=8)
        {
            printf("*");
            pass[i]=getch();
            i++;
        }
    }while (pass[i]!=13);
    pass[10]='\0';*/
    
	if (strcmp(pass,password)==0)
	{
		printf("\n\nPassword Match!\nLOADING");
		for(i=0;i<=6;i++)
		{
			fordelay(100000000);
			printf(".");
		}
			system("clear");
		menu();
	}
	else
	{
		printf("\n\nWrong password!!\a\a\a");
login_try:
		printf("\nEnter 1 to try again and 0 to exit:");
		scanf("%d",&main_exit);

		if (main_exit==1)
		{
			system("clear");
			main();
		}
		else if (main_exit==0)
		{
			system("clear");
			close();
		}
		else
		{
			printf("\nInvalid!");
			fordelay(1000000000);
			system("clear");
			goto login_try;
		}
	}
	return (0);
}
