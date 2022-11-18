#include "bank.h"

/**
  * edit - update the address and phone number associated with customer account
  */

void edit(void)
{
	int choice,test=0;
	FILE *old,*newrec;
    old=fopen("record.dat","r");
	newrec=fopen("new.dat","w");

	printf("\nEnter the account no. of the customer whose info you want to change:");
	scanf("%d",&upd.acc_no);

	while(fscanf(old,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",
				&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,
				add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
	{
		if (add.acc_no==upd.acc_no)
		{
			test=1;
			printf("\nWhich information do you want to change?\n1.Address\n2.Phone\n\nEnter your choice(1 for address and 2 for phone):");
			scanf("%d",&choice);
			system("cls");
			if(choice==1)
			{
				printf("Enter the new address:");
				scanf("%s",upd.address);
				fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",
						add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,upd.address,
						add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
				system("cls");
				printf("Changes saved!");
			}
			else if(choice==2)
			{
				printf("Enter the new phone number:");
				scanf("%lf",&upd.phone);
				fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",
						add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,
						add.citizenship,upd.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
				system("cls");
				printf("Changes saved!");
			}
		}
		else
			fprintf(newrec,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",
					add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,
					add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);
	}
	fclose(old);
	fclose(newrec);
	remove("record.dat");
	rename("new.dat","record.dat");

	if(test!=1)
	{
		system("cls");
		printf("\nRecord not found!!\a\a\a");
edit_invalid:
		printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
		scanf("%d",&main_exit);
		system("cls");
		if (main_exit==1)
			menu();
		else if (main_exit==2)
			close();
		else if(main_exit==0)
			edit();
		else
		{
			printf("\nInvalid!\a");
			goto edit_invalid;
		}
	}
	else
	{
		printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
		scanf("%d",&main_exit);
		system("cls");
		if (main_exit==1)
			menu();
		else
			close();
	}
}

