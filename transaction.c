#include "bank.h"

/**
  * transact - to deposit and make withdraws
  */

void transact(void)
{
	int choice,test=0;
	FILE *old,*newrec;
	old=fopen("record.dat","r");
	newrec=fopen("new.dat","w");

	printf("Enter the account no. of the customer:");
	scanf("%d",&transaction.acc_no);
	while (fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",
				&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,
				add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
	{
		if(add.acc_no==transaction.acc_no)
		{
			test=1;
			if(strcasecmp(add.acc_type,"fixed1")==0||strcasecmp(add.acc_type,"fixed2")==0||strcasecmp(add.acc_type,"fixed3")==0)
			{
				printf("\a\a\a\n\nYOU CANNOT DEPOSIT OR WITHDRAW CASH IN FIXED ACCOUNTS!!!!!");
				fordelay(1000000000);
				system("cls");
				menu();
			}
			printf("\n\nDo you want to\n1.Deposit\n2.Withdraw?\n\nEnter your choice(1 for deposit and 2 for withdraw):");
			scanf("%d",&choice);
			if (choice==1)
			{
				printf("Enter the amount you want to deposit:$ ");
				scanf("%f",&transaction.amt);
				add.amt+=transaction.amt;
				fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",
						add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,
						add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
				printf("\n\nDeposited successfully!");
			}
			else
			{
				printf("Enter the amount you want to withdraw:$ ");
				scanf("%f",&transaction.amt);
				add.amt-=transaction.amt;
				fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",
						add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,
						add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
				printf("\n\nWithdrawn successfully!");
			}
		}
		else
		{
			fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",
					add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,
					add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
		}
	}
	fclose(old);
	fclose(newrec);
	remove("record.dat");
	rename("new.dat","record.dat");
	if(test!=1)
	{
		printf("\n\nRecord not found!!");
transact_invalid:
		printf("\n\n\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
		scanf("%d",&main_exit);
		system("cls");

		if (main_exit==0)
			transact();
		else if (main_exit==1)
			menu();
		else if (main_exit==2)
			close();
		else
		{
			printf("\nInvalid!");
			goto transact_invalid;
		}
	}
	else
	{
		printf("\nEnter 1 to go to the main menu and 0 to exit:");
		scanf("%d",&main_exit);
		system("cls");
		if (main_exit==1)
			menu();
		else
			close();
	}
}
