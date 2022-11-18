#include "bank.h"

/**
  * interest - rate of interest
  * @t: time
  * @amount: initial ammount
  * @rate: value
  */

float interest(float t,float amount,int rate)
{
	float SI;
	SI = (rate * t * amount) / 100.0;
	return (SI);
}

/**
  * fordelay - sequencing
  * @j: intger to print
  */

void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}

/**
  * close - remarks
  */

void close(void)
{
    printf("\n\n\n\nThis C Mini Project is developed by Code, Audited, debugged and made applicable in LINUX env by ME!");
}


