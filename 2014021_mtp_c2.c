//Please read README.md before running

#include<stdio.h>
#include<sys/time.h>
#include<assert.h>
#include<pthread.h>
#include"2014021_counter2_safe.h"

struct sync_pot x;
double av, time_used;
long double value;

void *counter(void* y)
{
	int *limi=(int*)y;
	int limit=*limi;
	int i=0;
	for (i=0;i<limit;i++)
	{	
		sync_increment(&x);
	}	
	return NULL;
}

void main(int argc,char* argv[])
{
	int i,j,t,k,l,m,yoda,limu,lim,seed,str,etr;
	printf("Enter number of iterations\n");
	scanf("%d",&l);
	printf("Enter number upto which you want to count\n");
	scanf("%d",&seed);
	printf("Enter minimum number of threads\n");
	scanf("%d",&str);
	printf("Enter maximum number of threads\n");
	scanf("%d",&etr);
	assert(etr>=str);
	double records[etr+1-str];
	for(i=0;i<etr+1-str;i++)
	{
		records[i]=0;
	}
	pthread_t p[etr];
	for(m=str;m<=etr;m++)
	{
		//Number of iterations for averaging :
		for(yoda=0;yoda<l;yoda++)
		{
			struct timeval start,end;
			sync_init(&x);
			value=0;
			lim=seed;
			limu=lim/m;
			gettimeofday(&start,NULL);			
			//Create 'm-1' threads
			for(j=0;j<m-1;j++)
			{
				k=pthread_create(&p[j],NULL,counter,(void*)&limu);
				lim-=limu;
			}
			//Remainder added to the last thread:
			k=pthread_create(&p[m-1],NULL,counter,(void*)&lim);

			//Wait for those 'm' threads to finish:
			for(j=0;j<m;j++)
			{
				pthread_join(p[j],NULL);
			}
			gettimeofday(&end,NULL);
			records[m-str]+=((end.tv_sec-start.tv_sec)*1000000 + end.tv_usec-start.tv_usec)/1000000.0;
			value+=sync_get(&x);
		}	
		printf("Final value (average) of counter for %d threads : %d\n",m,sync_get(&x));
	}
	for(j=0;j<etr+1-str;j++)
	{
		printf("Average time taken for %d threads : %lf\n",j+str,records[j]/l);
	}
}