#ifndef _LINK_QUEUE_H
#define _LINK_QUEUE_H

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

typedef struct _link_queue_node  {
	element_type dt;
	struct _link_queue_node * next;
}link_queue_node,* plink_queue_node;

#if DYNAMIC_ALLOC 
//dynamic allocation
typedef struct {
	plink_queue_node front;
	plink_queue_node rear;
}link_queue,* plink_queue;

#else
//static  allocation
typedef struct {
	element_type pdt[QUEUE_BASE_SIZE];
	int front;
	int rear;
}link_queue,* plink_queue;

#endif
int init_link_queue(link_queue ** lqueue);
int destroy_link_queue(link_queue ** lqueue);
int is_empty_link_queue(link_queue * lqueue);
int en_link_queue(link_queue *lqueue,element_type dat);
int de_link_queue(link_queue *lqueue,element_type *pd);
int len_link_queue(link_queue *lqueue);
void print_link_queue(link_queue *lqueue);

#endif
