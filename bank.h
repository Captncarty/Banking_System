#ifndef BANK_H
#define BANK_H

/*=================*/
/*      STDLIB     */
/*=================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*==================*/
/* GLOBAL VARIABLES */
/*==================*/
int i,j;
int main_exit;

/*==================*/
/*    STRUCTURES    */
/*==================*/

/**
 * struct date - Date of transactions
 * @month: month of transaction
 * @day: specific day in the month
 * @year: period of transaction
 */

 struct date{
	 int month,day,year;

	 };

struct {

    char name[60];
    int acc_no,age;
    char address[60];
    char citizenship[15];
    double phone;
    char acc_type[10];
    float amt;
    struct date dob;
    struct date deposit;
    struct date withdraw;

    }add,upd,check,rem,transaction;

/*==================*/
/*  Main Functions  */
/*==================*/
float interest(float t,float amount,int rate);
void fordelay(int j);
void new_acc(void);
void view_list();
void edit(void);
void transact(void);
void erase(void);
void see(void);
void close(void);
void menu(void);

/*==================*/
/* Helper functions */
/*==================*/
int _strcmp(char *s1, char *s2);

#endif /* BANK_H */
