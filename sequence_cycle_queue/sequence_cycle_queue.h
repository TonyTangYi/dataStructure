#ifndef _SEQUENCE_CYCLE_QUEUE_H
#define _SEQUENCE_CYCLE_QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUEUE_BASE_SIZE    100
#define QUEUE_EXTEND_SIZE  50
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
	int front;
	int rear;
}sequence_cycle_queue,* psequence_cycle_queue;

#else
//static  allocation
typedef struct {
	element_type pdt[QUEUE_BASE_SIZE];
	int front;
	int rear;
}sequence_cycle_queue,* psequence_cycle_queue;

#endif
int init_sqcycle_queue(sequence_cycle_queue * sqcycle_queue);
int destroy_sqcycle_queue(sequence_cycle_queue * sqcycle_queue);
int is_empty_sqcycle_queue(sequence_cycle_queue * sqcycle_queue);
int is_full_sqcycle_queue(sequence_cycle_queue *sqcycle_queue);
int en_sqcycle_queue(sequence_cycle_queue *sqcycle_queue,element_type dt);
int de_sqcycle_queue(sequence_cycle_queue *sqcycle_queue,element_type *pd);
int len_sqcycle_queue(sequence_cycle_queue *sqcycle_queue);
void print_sqcycle_queue(sequence_cycle_queue *sqcycle_queue);

#endif
