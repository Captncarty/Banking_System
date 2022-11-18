#include "bank.h"

/**
  * new_acc - Creates a new customer account using this function
  * Returns: Customer's details
  */

void new_acc()

{
	int choice;
	FILE *ptr;

	ptr=fopen("record.dat","a+");
account_no:
	system("cls");
	printf("\t\t\t\xB2\xB2\xB2\ ADD RECORD  \xB2\xB2\xB2\xB2");
	printf("\n\n\nEnter today's date(mm/dd/yyyy):");
	scanf("%d/%d/%d",&add.deposit.month,&add.deposit.day,&add.deposit.year);
	printf("\nEnter the account number:");
	scanf("%d",&check.acc_no);
	while(fscanf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",
				&add.acc_no,add.name,&add.dob.month,&add.dob.day,&add.dob.year,&add.age,add.address,
				add.citizenship,&add.phone,add.acc_type,&add.amt,&add.deposit.month,&add.deposit.day,&add.deposit.year)!=EOF)
	{
		if (check.acc_no==add.acc_no)
		{
			printf("Account no. already in use!");
			fordelay(1000000000);
			goto account_no;
		}
	}
	add.acc_no=check.acc_no;
	printf("\nEnter the name:");
	scanf("%s",add.name);
	printf("\nEnter the date of birth(mm/dd/yyyy):");
	scanf("%d/%d/%d",&add.dob.month,&add.dob.day,&add.dob.year);
	printf("\nEnter the age:");
	scanf("%d",&add.age);
	printf("\nEnter the address:");
	scanf("%s",add.address);
	printf("\nEnter the citizenship number:");
	scanf("%s",add.citizenship);
	printf("\nEnter the phone number: ");
	scanf("%lf",&add.phone);
	printf("\nEnter the amount to deposit:$");
	scanf("%f",&add.amt);
	printf("\nType of account:\n\t#Saving\n\t#Current\n\t#Fixed1(for 1 year)\n\t#Fixed2(for 2 years)\n\t#Fixed3(for 3 years)\n\n\tEnter your choice:");
	scanf("%s",add.acc_type);

	fprintf(ptr,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",
			add.acc_no,add.name,add.dob.month,add.dob.day,add.dob.year,add.age,add.address,
			add.citizenship,add.phone,add.acc_type,add.amt,add.deposit.month,add.deposit.day,add.deposit.year);

	fclose(ptr);
	printf("\nAccount created successfully!");
add_invalid:
	printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
	scanf("%d",&main_exit);
	system("cls");
	if (main_exit==1)
		menu();
	else if(main_exit==0)
		close();
	else
	{
		printf("\nInvalid!\a");
		goto add_invalid;
	}
}
