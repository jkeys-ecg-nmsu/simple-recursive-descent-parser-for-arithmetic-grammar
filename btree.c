#include "btree.h"
#include "stdlib.h"
#include "input_token.h"
#include <stdio.h>

struct treenode  {
    int data; //if toktype == Operand, data holds the value of the operand
    //int toktype;
     struct treenode *left;
     struct treenode *right;
};

/*
int eval_children_leaves(BTree t) {
    if(isLeaf(t->left) && isLeaf(t->right)) {
      switch(t.toktype) {
	case Plus:
	  return t.left.data + t.right.data;
	case Minus:
	  return t.left.data - t.right.data;
	case Mult:
	  return t.left.data * t.right.data;
	case Divide:
	  return t.left.data / t.right.data;
      
    }
   
  
} 
*/

int eval (BTree t) {
	if(is_leaf(t)) 
		return t->data; //return data when hit any leaf of the tree, as base case

	int left = eval(t->left);   //recursively evaluate left subtree
	int right = eval(t->right); //recursively evaluate right subtree
	return calc_operands(left, t->data, right); //left and right have been evaluated, calculate operands
}

int calc_operands(int left, int opr, int right) {
    switch(opr) {
		case Plus:
		  return left + right;
		case Minus:
		  return left - right;
		case Mult:
		  return left * right;
		case Divide:
		  return left / right;
		  
    }
}

//return 1 if true, 0 if false
int is_leaf(BTree node) {
	if (node->left == NULL && node->right == NULL)
		return 1;
	else
		return 0;
}

void in_order_traversal( BTree t ) {
	if(is_leaf(t)) {
		printf("%d", t->data);
		return;
	}
	printf("(");
	in_order_traversal(t->left);
	switch(t->data) {
		case Plus: printf(" + "); break;
		case Minus: printf(" - "); break;
		case Divide: printf(" / "); break;
		case Mult: printf(" * "); break;
	}
	in_order_traversal(t->right);
	printf(")");
}


void post_order_traversal( BTree t ) {
	if(is_leaf(t)) {
		printf("%d ", t->data);
		return;
	}
		
	post_order_traversal((t->left));	
	post_order_traversal((t->right));
	
	switch(t->data) {
		case Plus: printf(" + "); break;
		case Minus: printf(" - "); break;
		case Divide: printf(" / "); break;
		case Mult: printf(" * "); break;
	}
	
}

BTree create_node_leaf(int w) {
	struct treenode *node;
	node = (struct treenode *) malloc(sizeof (struct treenode));
	node->left = NULL;
	node->right = NULL;
	node->data = w;
	return node;
}


BTree create_node_children(BTree left, int w, BTree right) {
	struct treenode *node;
	node = (struct treenode *) malloc(sizeof (struct treenode));
	node->left = left;
	node->right = right;
	node->data = w;
	return node;
}