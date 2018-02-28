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
typedef struct node {
	element_type dt;
	struct node * next;
	 
}link_list,* plink_list;

#else
//staic  allocation
typedef struct {
	element_type pdt[LIST_BASE_SIZE];
	int len;
}sequence_list,* psequence_list;

#endif

int len_llist(link_list *llist);
