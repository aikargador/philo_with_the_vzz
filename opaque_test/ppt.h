#ifndef PPT_H
# define PPT_H


////////////////////////////////////////////////////////////////////////////
// incomplete werk here on opaque data type, cum back later!

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct mypp pp;

pp*		pp_create(int i);
int		intcrementor(pp *p);
char	charcrementor(pp *p);

#endif