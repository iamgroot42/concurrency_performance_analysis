#include <pthread.h>
#include "2014021_counter2_safe.h"	

void sync_init(struct sync_pot *c)
{
	c->val = 0;
	pthread_mutex_init(&c->lock,NULL);
}

void sync_increment(struct sync_pot *c)
{
	pthread_mutex_lock(&c->lock);
	c->val++;
	pthread_mutex_unlock(&c->lock);
}

int sync_get(struct sync_pot *c)
{
	pthread_mutex_lock(&c->lock);
	int x=c->val;
	pthread_mutex_unlock(&c->lock);
	return x;
}