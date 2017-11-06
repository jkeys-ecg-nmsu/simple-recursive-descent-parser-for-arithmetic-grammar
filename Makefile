all: expr

expr: btree.c error.c input_token.c 
	gcc main.c expr.c input_token.c error.c btree.c -o expression
