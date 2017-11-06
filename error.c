
#include <stdio.h>
#include <stdlib.h>

void error( int i )
{
	printf("\nERROR CALLED %d\n", i);
     fprintf(stderr, "error: %d\n", i);
     exit(i);
}
