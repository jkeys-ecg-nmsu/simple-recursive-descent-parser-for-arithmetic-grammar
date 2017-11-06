/* just stick the BTree code here for now */

#include "btree.h"
#include "input_token.h"
#include "error.h"

/*
typedef struct BTree  {
    int toktype;
    int value; //if toktype == Operand, value holds the value of the operand
    BTree *left;
    BTree *right;
} BTree;
*/

/*
void init_node(BTree node) {
    node.left = malloc(sizeof *BTree);
    node.right = malloc(sizeof *BTree);
    node.value = -1;
}

void set_node(BTree node, int toktype, int value) {
    node.toktype = toktype;
    node.value = value;
}
*/

BTree eval_expr_4(BTree opn1,int opr1, BTree opn2, int opr2);
BTree eval_expr_3(BTree opn1,int opr1, BTree opn2);
BTree eval_expr_2(BTree opn1,int opr1);
BTree eval_expr_1(BTree opn1);
BTree eval_expr();

BTree evaluate_expression() {
    int w;
    BTree val;
    if (get_token(&w)!=OpenBracket) error(-1);
    val =  eval_expr();
    if (get_token(&w)!=EOF) error(-2);
    return val;
}

BTree eval_expr()
/* have seen

        (

   read until we find a matching parenthesis.
   the expression enclosed is evaluated.
   return the integer value computed.
*/
{
    BTree *node = NULL;


    int w;
    switch (get_token(&w))
    { case OpenBracket:
            //set_toktype(node, OpenBracket);
            return(eval_expr_1(eval_expr())); //evaluate function, store in node data, then return
        case CloseBracket:
            error(2);
        case Plus:
            error(3);
        case Minus:
            error(4);
        case Mult:
            error(5);
        case Divide:
            error(6);
        case Operand:
            //set_toktype(node, Operand);
            return(eval_expr_1(create_node_leaf(w)));
        case EOF:
            error(7);
    }
}

BTree eval_expr_1(BTree opn1)
/* have seen

        ( opn1

   where opn1 is an operand

   read until we find a matching parenthesis.
   the expression enclosed is evaluated.
   return the integer value computed.
*/
{ int w;

    //BTree *node = NULL;
    //BTree *left = create_node_leaf(opn1); //left is always a leaf when left->toktype == Operand
    //BTree *right = create_node_empty();

    switch (get_token(&w))
    { case OpenBracket:
            error(8);
        case CloseBracket:
            return(opn1); //this is a leaf node, opn1 == left->data
        case Plus:
            //node = create_node_children(left, right, Plus);
            //set_toktype(node, Plus);
            return(eval_expr_2(opn1, Plus)); //TODO
        case Minus:
            //set_toktype(node, Minus);
            return(eval_expr_2(opn1, Minus));
        case Mult:
            //set_toktype(node, Mult);
            return(eval_expr_2(opn1, Mult));
        case Divide:
            //set_toktype(node, Divide);
            return(eval_expr_2(opn1,Divide));
        case Operand:
            error(10);
        case EOF:
            error(11);
    }
}

BTree eval_expr_2(BTree opn1,int opr1)
/* have seen

        ( opn1 opr1

   where opn1 is an operand
     and opr1 is an operator

   read until we find a matching parenthesis.
   the expression enclosed is evaluated.
   return the integer value computed.
*/
{int w;

    //BTree *left = create_node_leaf(opn1);
    //BTree *right = NULL;
    //BTree *node = NULL;

    switch (get_token(&w))
    { case OpenBracket:
            //node = create_node_empty();
            //left = create_node_leaf(opn1);

            return(eval_expr_3(opn1,opr1,eval_expr()));
        case CloseBracket:
            error(12);
        case Plus:
            error(13);
        case Minus:
            error(14);
        case Mult:
            error(15);
        case Divide:
            error(16);
        case Operand:

            return(eval_expr_3(opn1,opr1, create_node_leaf(w)));
        case EOF:
            error(17);
    }
}


BTree eval_expr_3(BTree opn1,int opr1, BTree opn2)
/* have seen

        ( opn1 opr1 opn2

   where opn1 and opn2 are operands,
         opr1 is an operator

   read until we find a matching parenthesis.
   the expression enclosed is evaluated.
   return the integer value computed.
*/
{int w;

    //BTree *node;
    //BTree *left;
    //BTree *right;

    switch (get_token(&w))
    { case OpenBracket:
            error(18);
        case CloseBracket:

            switch (opr1)
            { case Plus:   return(create_node_children(opn1, Plus, opn2));
                case Minus:  return(create_node_children(opn1, Minus, opn2));
                case Mult:   return(create_node_children(opn1, Mult, opn2));
                case Divide: return(create_node_children(opn1, Divide, opn2));
            }
        case Plus:
            switch (opr1)
            { case Plus:   return(eval_expr_2(create_node_children(opn1, Plus, opn2),Plus));
                case Minus:  return(eval_expr_2(create_node_children(opn1, Minus, opn2),Plus));
                case Mult:   return(eval_expr_2(create_node_children(opn1, Mult, opn2),Plus));
                case Divide: return(eval_expr_2(create_node_children(opn1, Divide, opn2),Plus));
            }
        case Minus:
            switch (opr1)
            { case Plus:   return(eval_expr_2(create_node_children(opn1, Plus, opn2),Minus));
                case Minus:  return(eval_expr_2(create_node_children(opn1, Minus, opn2),Minus));
                case Mult:   return(eval_expr_2(create_node_children(opn1, Mult, opn2),Minus));
                case Divide: return(eval_expr_2(create_node_children(opn1, Divide, opn2),Minus));
            }
        case Mult:
            switch (opr1)
            { case Plus:   return(eval_expr_4(opn1,opr1,opn2,Mult));
                case Minus:  return(eval_expr_4(opn1,opr1,opn2,Mult));
                case Mult:   return(eval_expr_2(create_node_children(opn1, Mult, opn2),Mult));
                case Divide: return(eval_expr_2(create_node_children(opn1, Divide, opn2),Mult));
            }
        case Divide:
            switch (opr1)
            { case Plus:   return(eval_expr_4(opn1,opr1,opn2,Divide));
                case Minus:  return(eval_expr_4(opn1,opr1,opn2,Divide));
                case Mult:   return(eval_expr_2(create_node_children(opn1, Mult, opn2),Divide));
                case Divide: return(eval_expr_2(create_node_children(opn1, Divide, opn2),Divide));
            }
        case Operand:
            error(20);
        case EOF:
            error(21);
    }
}

BTree eval_expr_4(BTree opn1, int opr1, BTree opn2, int opr2)
/* have seen

        ( opn1 opr1 opn2 opr2

   where opn1 and opn2 are operands,
         opr1 and opr2 are operators

   read until we find a matching parenthesis.
   the expression enclosed is evaluated.
   return the integer value computed.
*/
{int w;

    //BTree *node;
    //BTree *left;
    //BTree *right;

    switch (get_token(&w))
    {
        case OpenBracket:
            //left = create_node_leaf(opn1);
            //BTree *subtree_left = create_node_leaf(opn2);
            //BTree *subtree_right = eval_expr();
            //BTree *subtree = create_node_children(subtree_left, subtree_right, opr2);
            //node = create_node_children(left, subtree, opr1);
            switch (opr2)
            {case Mult:   return(eval_expr_3(opn1,opr1,create_node_children(opn2, Mult, eval_expr())));
                case Divide: return(eval_expr_3(opn1,opr1,create_node_children(opn2, Divide, eval_expr())));
            }
        case CloseBracket:
            error(22);
        case Plus:
            error(23);
        case Minus:
            error(24);
        case Mult:
            error(25);
        case Divide:
            error(26);
        case Operand:
            switch (opr2)
            {

                //left = create_node_leaf(opn1);
                //BTree *subtree_left = create_node_leaf(opn2);
                //BTree *subtree_right = create_node_leaf(*w);
                //BTree *subtree = create_node_children(subtree_left, subtree_right, opr2);
                //node = create_node_children(left, subtree, opr1);
                case Mult:
                    return(eval_expr_3(opn1,opr1, create_node_children(opn2, Mult, create_node_leaf(w))));
                case Divide:
                    return(eval_expr_3(opn1,opr1, create_node_children(opn2, Divide, create_node_leaf(w))));
            }
        case EOF:
            error(27);
    }
}



