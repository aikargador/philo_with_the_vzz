#include "ppt.h"

typedef struct mypp {
	int i;
	char c;
} pp;

pp* pp_create(int i)
{
	pp *p = (pp *)malloc(sizeof(i));
	return p;
}

int		intcrementor(pp *p)
{
	if (p->i < 2147483647)
		p->i++;
	else
		p->i = -2147483648;
	return (p->i);
}

char	charcrementor(pp *p)
{
	if (p->c != 'z' && p->c != 'Z')
		p->c++;
	else if (p->c == 'z')
		p->c = 'a';
	else if (p->c == 'Z')
		p->c = 'A';
	return (p->c);
}