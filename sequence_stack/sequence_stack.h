#ifndef _SEQUENCE_STACK_H
#define _SEQUENCE_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_BASE_SIZE    100
#define STACK_EXTEND_SIZE  50
#define TRUE               1
#define FALSE              0
#define EMPTY_TOP_SIZE     (-1)

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
typedef struct {
	element_type * pdt;
	int stack_max_size;
	int top;
}sequence_stack,* psequence_stack;

#else
//static  allocation
typedef struct {
	element_type pdt[LIST_BASE_SIZE];
	int top;
}sequence_stack,* psequence_stack;

#endif

int init_sqstack(psequence_stack  sqstack);
int is_empty_sqstack(sequence_stack * sqstack);
int is_full_sqstack(sequence_stack *sqstack);
u32 deepth_sqstack(sequence_stack *sqstack);
int push_sqstack(sequence_stack *sqstack,element_type dt);
int pop_sqstack(sequence_stack *sqstack,element_type *pd);
int get_topElement_sqstack(sequence_stack *sqstack,element_type *pd);
void print_sqstack(sequence_stack *sqstack);

#endif
