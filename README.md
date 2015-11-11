###Running the Programs

* Run stp.c ( single-threaded counter ) :

	```
	gcc -pthread 2014021_stp.c 2014021_counter1_nonsafe.c
	```
* Run mtp_c1.c ( multi-threaded thread-unsafe counter) : 

	```
	gcc -pthread 2014021_mtp_c1.c 2014021_counter1_nonsafe.c
	```
* Run mtp_c2.c ( multi-threaded thread-safe counter using mutex_lock): 

	```
	gcc -pthread 2014021_mtp_c2.c 2014021_counter2_safe.c
	```
* Run mtp_c1_sem.c ( multi-threaded thread-unsafe counter using binary semaphores):

	```
	gcc -pthread 2014021_mtp_c1_sem.c 2014021_counter1_nonsafe.c
	```


###Graph analysis

* Analysis of multi-threaded programs using mutex locks and not using any locks in 2014021_plot1.pdf/odt
* Analysis of multi-threaded programs using semaphores in 2014021_plot2.pdf/odt
