#ifndef _LINK_DOUBLE_CYCLE_LIST_H
#define _LINK_DOUBLE_CYCLE_LIST_H
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

typedef struct node {
	element_type dt;
	struct node * next;
	struct node * prior;
}dclink_list,* pdclink_list;


int init_dcllist(pdclink_list * head);
void destroy_dcllist(pdclink_list * head);
#endif