// Listing 29-2: Creating a thread with the detached attribute

#include <pthread.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

static void	*threadFunc(void *arg)
{
	char	*s = (char *)arg;
	printf("%s", s);
	return (void *)strlen(s);
}

int main()
{
	pthread_attr_t	attr;
	pthread_t		thr;
	int				s;

	s = pthread_attr_init(&attr);			/* Assigns default values */
	if (s)
		perror("pthread_attr_init");

	s = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
	if (s)
		perror("pthread_attr_setdetachstate");

	s = pthread_create(&thr, &attr, threadFunc, (void *) 1);
	if (s)
		perror("pthread_create");

	s = pthread_attr_destroy(&attr);		/* No longer needed */
	if (s)
		perror("pthread_attr_destroy");
}