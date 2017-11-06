#include <limits.h> //for INT_MIN

#ifndef BTREE_H
#define BTREE_H

typedef struct treenode *BTree;
//const int DEFAULT_VALUE = INT_MIN;

//void init_node(BTree *node);

int calc_operands(int left, int opr, int right);

int eval(BTree t);

//void set_toktype(BTree *node, int toktype);

BTree create_node_leaf(int w);

BTree create_node_empty();

//BTree create_node_children_operand(BTree *left, int w, BTree *right); 

BTree create_node_children(BTree left, int w, BTree right);

void in_order_traversal( BTree t );

void post_order_traversal( BTree t );

void set_node(BTree node, int w);

BTree get_left(BTree node);

BTree get_right(BTree node);

int data(BTree node);

void set_left(BTree node, BTree left);

void set_right(BTree node, BTree right);

void set_data(BTree node, int w);

//return 1 if true, 0 if false
int is_empty(BTree node);

//return 1 if true, 0 if false
int is_leaf(BTree node);

#endif
