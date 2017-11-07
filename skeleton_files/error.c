//Skeleton file
//Author: Prof. Hing Leung, PhD, New Mexico State University
//Last modified: unknown


#include <stdio.h>
#include <stdlib.h>

void error( int i )
{
     fprintf(stderr, "error: %d\n", i);
     exit(i);
}