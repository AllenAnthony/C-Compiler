#include "util.h"

void *checked_malloc(int len)
{
	void *p = malloc(len);
	if (!p) {
		fprintf(stderr,"\nRun out of memory!\n");
		exit(1);
	}
	return p;
}

char* String(char *s)
{
    char*  p = checked_malloc(strlen(s)+1);
	strcpy(p, s);
	return p;
}
