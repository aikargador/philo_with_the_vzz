
// The program in Listing 29-1 creates another thread and then joins with it.

#include <pthread.h>
#include <string.h>
#include <stdlib.h> // exit success no
#include <stdio.h>
#include <errno.h>

/* Depending on how the two threads were scheduled, the order of the first two lines of
output might be reversed. u can uncomment the sleep function to see this in action! */

static void	*threadFunc(void *arg)
{
	char	*s = (char *)arg;
	printf("%s", s);
	return (void *)strlen(s);
}

#include <unistd.h>

int	main(int argc, char *argv[])
{
	pthread_t	t1;
	void		*res;
	int			s;

	s = pthread_create(&t1, NULL, threadFunc, "Hello world\n");
	if (s)
		perror("pthread_create");
	// sleep(1);
	printf("Message from main()\n");
	s = pthread_join(t1, &res);
	if (s)
		perror("pthread_join");
	printf("Thread returned %ld\n", (long)res);
	exit(EXIT_SUCCESS);
}
