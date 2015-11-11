//Please read README.md before running

#include<stdio.h>
#include<time.h>
#include"2014021_counter1_nonsafe.h"

struct pot x;
clock_t start,end;
double time_used,average;

void main()
{
	int j,t,i,l;
	printf("Enter number of iterations\n");
	scanf("%d",&l);
	printf("Enter number upto which you want to count\n");
	scanf("%d",&t);
	average=0;
	for(j=0;j<l;j++)
	{
		init(&x);
		start=clock();
		for(i=0;i<t;i++) increment(&x);		
		end=clock();
		time_used=((double)(end-start))/CLOCKS_PER_SEC;
		average+=time_used;
	}
	average/=l;
	//Printing all of them together to avoid counting the time taken for 'printf'
	printf("Average time taken : %lf\n",average);
}