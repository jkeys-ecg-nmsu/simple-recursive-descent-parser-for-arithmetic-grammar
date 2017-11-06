#include <stdio.h>
#include "input_token.h"
#include "expr.h"
#include "error.h"
//#include "btree.h"

int main(int argc, char *argv[])
{
   printf("in main\n");
    BTree val;
   fpi = fopen( *++argv, "r" );
   printf("before evaluate_expression()\n");
   val =  evaluate_expression();
   //printf("after evaluate_expression(), val.left->data = %d\n", val.left->data);
   in_order_traversal(val);
   printf("\n\n");
   post_order_traversal(val);
   printf("\nresult = %d\n", eval(val) );
}
