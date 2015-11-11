#include "2014021_counter1_nonsafe.h"

void init(struct pot *c)
{
	c->val = 0;
}

void increment(struct pot *c)
{
	c->val++;
}

int get(struct pot *c)
{
	return c->val;
}