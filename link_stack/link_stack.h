#ifndef _LINK_STACK_H
#define _LINK_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_BASE_SIZE    100
#define STACK_EXTEND_SIZE  50
#define TRUE               1
#define FALSE              0

//error type definition
#define E_BASE            -1000
#define E_MALLOC          E_BASE - 1
#define E_OUT_OF_RANGE    E_BASE - 2
#define E_ARG_NULL        E_BASE - 3

#define DYNAMIC_ALLOC     1
 

typedef int element_type;
typedef unsigned int u32;

#if DYNAMIC_ALLOC 
//dynamic allocation
typedef  struct node{
	element_type dt;
	struct node * next;
}lstack_node,* plstack_node;//node 


typedef  struct{
	plstack_node top;
	int stack_size;
}link_stack,* plink_stack;

#else
//static  allocation
typedef struct {
	element_type pdt[LIST_BASE_SIZE];
	int top;
}sequence_stack,* psequence_stack;

#endif
int init_lstack(plink_stack * lstack);
int destroy_lstack(link_stack ** lstack);
int is_empty_lstack(link_stack * lstack);
u32 deepth_lstack(link_stack *lstack);
int push_lstack(link_stack *lstack,element_type dat);
int pop_lstack(link_stack *lstack,element_type *pd);
int get_topElement_lstack(link_stack *lstack,element_type *pd);
void print_lstack(link_stack *lstack);

#endif
