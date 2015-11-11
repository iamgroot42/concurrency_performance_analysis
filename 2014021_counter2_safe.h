struct sync_pot
{
	int val;
	pthread_mutex_t lock;
} ;

void sync_init(struct sync_pot *c);

void sync_increment(struct sync_pot *c);

int sync_get(struct sync_pot *c);