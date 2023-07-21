#include <stdio.h>
#include <sys/time.h>

int main()
{
	struct timeval flumper_dumper;

	gettimeofday(&flumper_dumper, NULL);
	// printf("Seconds since 1/1/1970: %lu\n",flumper_dumper.tv_sec);
	printf("Microseconds: %d\n",flumper_dumper.tv_usec);
	printf("Milliseconds: %d\n",flumper_dumper.tv_usec / 1000);
}


////////////////////////////////////////////////////////////////////////

// #include <stdio.h>
// #include <sys/time.h>
// #include <time.h>

// int main()
// {
// 	struct timeval tv;
// 	struct timezone tz;
// 	struct tm *today;
// 	int zone;

// 	gettimeofday(&tv,&tz);

// 	/* get time details */
// 	today = localtime(&tv.tv_sec);
// 	printf("It's %d:%0d:%0d.%d\n",
// 			today->tm_hour,
// 			today->tm_min,
// 			today->tm_sec,
// 			tv.tv_usec
// 		);
// }