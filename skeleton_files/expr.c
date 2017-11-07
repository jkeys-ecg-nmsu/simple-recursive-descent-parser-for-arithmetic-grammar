//Skeleton file
//Author: Prof. Hing Leung, PhD, New Mexico State University
//Last modified: unknown

#include "input_token.h"
#include "error.h"

int eval_expr_4(int opn1,int opr1, int opn2, int opr2);
int eval_expr_3(int opn1,int opr1, int opn2);
int eval_expr_2(int opn1,int opr1);  
int eval_expr_1(int opn1);  
int eval_expr();

int evaluate_expression() {  
   int w, val;
   if (get_token(&w)!=OpenBracket) error(-1);
   val =  eval_expr();
   if (get_token(&w)!=EOF) error(-2);
   return val;
}

int eval_expr()
/* have seen

        (

   read until we find a matching parenthesis.
   the expression enclosed is evaluated.
   return the integer value computed.
*/
{int w;
    switch (get_token(&w))
    { case OpenBracket:
           return(eval_expr_1(eval_expr()));
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
           return(eval_expr_1(w));
      case EOF:
           error(7);
    }
}

int eval_expr_1(int opn1)
/* have seen

        ( opn1

   where opn1 is an operand

   read until we find a matching parenthesis.
   the expression enclosed is evaluated.
   return the integer value computed.
*/
{int w;
    switch (get_token(&w))
    { case OpenBracket:
           error(8);
      case CloseBracket:
           return(opn1);
      case Plus:
           return(eval_expr_2(opn1,Plus));
      case Minus:
           return(eval_expr_2(opn1,Minus));
      case Mult:
           return(eval_expr_2(opn1,Mult));
      case Divide:
           return(eval_expr_2(opn1,Divide));
      case Operand:
           error(10);
      case EOF:
           error(11);
    }
}

int eval_expr_2(int opn1,int opr1)
/* have seen

        ( opn1 opr1

   where opn1 is an operand
     and opr1 is an operator

   read until we find a matching parenthesis.
   the expression enclosed is evaluated.
   return the integer value computed.
*/
{int w;
    switch (get_token(&w))
    { case OpenBracket:
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
           return(eval_expr_3(opn1,opr1,w));
      case EOF:
           error(17);
    }
}


int eval_expr_3(int opn1,int opr1, int opn2)
/* have seen

        ( opn1 opr1 opn2

   where opn1 and opn2 are operands, 
         opr1 is an operator

   read until we find a matching parenthesis.
   the expression enclosed is evaluated.
   return the integer value computed.
*/
{int w;
    switch (get_token(&w))
    { case OpenBracket:
           error(18);
      case CloseBracket:
           switch (opr1) 
           { case Plus:   return(opn1+opn2);
             case Minus:  return(opn1-opn2);
             case Mult:   return(opn1*opn2);
             case Divide: return(opn1/opn2);
           }
      case Plus:
           switch (opr1)
           { case Plus:   return(eval_expr_2(opn1+opn2,Plus));
             case Minus:  return(eval_expr_2(opn1-opn2,Plus));
             case Mult:   return(eval_expr_2(opn1*opn2,Plus));
             case Divide: return(eval_expr_2(opn1/opn2,Plus));
           }
      case Minus:
           switch (opr1)
           { case Plus:   return(eval_expr_2(opn1+opn2,Minus));
             case Minus:  return(eval_expr_2(opn1-opn2,Minus));
             case Mult:   return(eval_expr_2(opn1*opn2,Minus));
             case Divide: return(eval_expr_2(opn1/opn2,Minus));
           }
      case Mult:
           switch (opr1)
           { case Plus:   return(eval_expr_4(opn1,opr1,opn2,Mult));
             case Minus:  return(eval_expr_4(opn1,opr1,opn2,Mult));
             case Mult:   return(eval_expr_2(opn1*opn2,Mult));
             case Divide: return(eval_expr_2(opn1/opn2,Mult));
           }
      case Divide:
           switch (opr1)
           { case Plus:   return(eval_expr_4(opn1,opr1,opn2,Divide));
             case Minus:  return(eval_expr_4(opn1,opr1,opn2,Divide));
             case Mult:   return(eval_expr_2(opn1*opn2,Divide));
             case Divide: return(eval_expr_2(opn1/opn2,Divide));
           }
      case Operand:
           error(20);
      case EOF:
           error(21);
    }
}

int eval_expr_4(int opn1, int opr1, int opn2, int opr2)
/* have seen

        ( opn1 opr1 opn2 opr2

   where opn1 and opn2 are operands,
         opr1 and opr2 are operators

   read until we find a matching parenthesis.
   the expression enclosed is evaluated.
   return the integer value computed.
*/
{int w;
    switch (get_token(&w))
    { case OpenBracket:
           switch (opr2)
           {case Mult:   return(eval_expr_3(opn1,opr1,opn2*eval_expr()));
            case Divide: return(eval_expr_3(opn1,opr1,opn2/eval_expr()));
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
           { case Mult:   return(eval_expr_3(opn1,opr1,opn2*w));
             case Divide: return(eval_expr_3(opn1,opr1,opn2/w));
           }
      case EOF:
           error(27);
    }
}


