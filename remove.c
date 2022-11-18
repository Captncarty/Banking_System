#include "bank.h"

/**
  * erase - delete client account
  */

void erase(void)
{
	FILE *old,*newrec;
	int test=0;
	old=fopen("record.dat","r");
	newrec=fopen("new.dat","w");
	printf("Enter the account no. of the customer you want to delete:");
	scanf("%d",&rem.acc_no);
	while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",
				&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,
				add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
	{
		if(add.acc_no!=rem.acc_no)
			fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",
					add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,
					add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
		else
		{
			test++;
			printf("\nRecord deleted successfully!\n");
		}
	}
	fclose(old);
	fclose(newrec);
	remove("record.dat");
	rename("new.dat","record.dat");
	if(test==0)
	{
		printf("\nRecord not found!!\a\a\a");
erase_invalid:
		printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
		scanf("%d",&main_exit);

		if (main_exit==1)
			menu();
		else if (main_exit==2)
			close();
		else if(main_exit==0)
			erase();
		else
		{
			printf("\nInvalid!\a");
			goto erase_invalid;
		}
	}
	else
	{
		printf("\nEnter 1 to go to the main menu and 0 to exit:");
		scanf("%d",&main_exit);
		system("clear");

		if (main_exit==1)
			menu();
		else
			close();
	}

}
