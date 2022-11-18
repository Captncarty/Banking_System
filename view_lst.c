#include "bank.h"

/**
  * view_list - Displays a list of items
  * Description: allows access to the customer's banking information
  * Return: A list
  */

void view_list()
{
	FILE *view;
	view=fopen("record.dat","r");
	int test=0;
    
	system("clear");
    printf("\nACC. NO.\tNAME\t\t\tADDRESS\t\t\tPHONE\n");

	while(fscanf(view,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",
				&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,
				add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
	{
		printf("\n%6d\t %10s\t\t\t%10s\t\t%.0lf",add.acc_no,add.name,add.address,add.phone);
		test++;
	}
	
	fclose(view);
	if (test == 0)
	{
		system("clear");
		printf("\nNO RECORDS!!\n");
	}

view_list_invalid:
	printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
	scanf("%d",&main_exit);
	system("clear");
	if (main_exit==1)
		menu();
	else if(main_exit==0)
		close();
	else
	{
		printf("\nInvalid!\a");
		goto view_list_invalid;
	}
}

