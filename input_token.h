
/********************** token ******************************/

#ifndef INPUT_TOKEN_H
#define INPUT_TOKEN_H

#include <stdio.h>

FILE *fpi;
                                        /*
#define EOF         -1                  */
#define OpenBracket  0 
#define CloseBracket 1
#define Plus         2
#define Minus        3
#define Mult         4
#define Divide       5
#define Operand      6

int get_token(int *w);
/* returns eight possible integer values as defined above.
   In case the token is Operand, get_token also returns the
   operand value in *w. Otherwise, *w is not defined.
*/

#endif