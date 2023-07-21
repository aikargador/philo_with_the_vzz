
//Listing 30-1: Incorrectly incrementing a global variable from two threads

#include <pthread.h>
#include <string.h>
#include <stdlib.h> // exit success no
#include <stdio.h>
#include <errno.h>

static int	glob = 0;

static void	*threadFunc(void *arg)			/* loop arg times incrementing glob */
{
	int	loops;
	int	loc, j;

	loops = *((int *)arg);
	printf("loop -> %d\n", loops);
	for (j = 0; j < loops; j++) {
		// loc = glob;
		// loc++;
		// glob = loc;
		glob++;
	}
	return NULL;
}

int	main(int argc, char *argv[])
{
	pthread_t	t1, t2;
	int			loops, s;

	loops = (argc > 1) ? atoi(argv[1]) : 10000000;
	s = pthread_create(&t1, NULL, threadFunc, &loops);
	if (s)
		perror("pthread_create");
	s = pthread_create(&t2, NULL, threadFunc, &loops);
	if (s)
		perror("pthread_create");
	s = pthread_join(t1, NULL);
	if (s)
		perror("pthread_join");
	s = pthread_join(t2, NULL);
	if (s)
		perror("pthread_join");
	printf("glob => %d\n", glob);
	exit(EXIT_SUCCESS);
}