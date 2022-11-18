#include "bank.h"

void menu(void)
{
	int choice;
	system("clear");
	system("tput setaf 34");
	printf("\n\n\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM");
	printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\n\n\t\t1.Create new account\n\t\t2.Update information of existing account\n\t\t3.For transactions\n\t\t4.Check the details of existing account\n\t\t5.Removing existing account\n\t\t6.View customer's list\n\t\t7.Exit\n\n\n\n\n\t\t Enter your choice: ");
	scanf("%d",&choice);
	system("clear");

	switch(choice)
	{
		case 1:new_acc();
			   break;
		case 2:edit();
			   break;
		case 3:transact();
			   break;
		case 4:see();
			   break;
		case 5:erase();
			   break;
		case 6:view_list();
			   break;
		case 7:close();
			   break;
	}
}

