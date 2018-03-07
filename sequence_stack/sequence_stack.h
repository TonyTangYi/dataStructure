#ifndef _SEQUENCE_STACK_H
#define _SEQUENCE_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIST_BASE_SIZE    100
#define LIST_EXTEND_SIZE  50
#define TRUE              1
#define FALSE             0

#define E_BASE            -1000
#define E_MALLOC          E_BASE - 1
#define E_OUT_OF_RANGE    E_BASE - 2
#define E_ARG_NULL        E_BASE - 3

#define DYNAMIC_ALLOC     1
 

typedef int element_type;

#if DYNAMIC_ALLOC 
//dynamic allocation
typedef struct {
	element_type * pdt;
	int stack_size;
	int top;
}sequence_stack,* psequence_stack;

#else
//static  allocation
typedef struct {
	element_type pdt[LIST_BASE_SIZE];
	int len;
}sequence_stack,* psequence_stack;

#endif



int init_sqlist(sequence_list * sqlist);
int is_empty_sqlist(sequence_list * sqlist);
int is_full_sqlist(sequence_list *sqlist);

#endif
