#include "link_queue.h"

int init_link_queue(link_queue ** plqueue)
{
	if (plqueue == NULL)
		return E_ARG_NULL;
	*plqueue = (link_queue *) malloc(1 * sizeof(link_queue));
	if (*plqueue == NULL)
	{
		return E_MALLOC;
	}
	else
	{
		(*plqueue)->front = (*plqueue)->rear = NULL;
		return TRUE;
	} 
}

int destroy_link_queue(link_queue ** lqueue)
{
	if (*lqueue == NULL)
		return E_ARG_NULL;
	
	link_queue_node *ptmp = (*lqueue)->front;
	while(ptmp)
	{
		free(ptmp);
		ptmp = ptmp->next;
	}
	free(*lqueue);
	return TRUE;
}

int is_empty_link_queue(link_queue * lqueue)
{
	if (lqueue == NULL)
	{
		return TRUE;
	}
	
	return (lqueue->front == NULL ?  TRUE : FALSE);
}

//enqueue
int en_link_queue(link_queue *lqueue,element_type dat)
{
	if (lqueue == NULL)
		return E_ARG_NULL;

	link_queue_node *ptmp;
	ptmp = (link_queue_node *)malloc(1 * sizeof(link_queue_node));
	if (ptmp == NULL)
	{
		return E_MALLOC;
	}
	
	if (is_empty_link_queue(lqueue))
	{
		lqueue->front = lqueue->rear = ptmp;
	}
	
	ptmp->dt = dat;
	lqueue->rear->next = ptmp;
	ptmp->next = NULL;
	lqueue->rear = ptmp;

	return TRUE;
}

//dequeue
int de_link_queue(link_queue *lqueue,element_type *pd)
{
	if (lqueue == NULL || pd == NULL)
		return E_ARG_NULL;
	
	if (is_empty_link_queue(lqueue))
	{
		return FALSE;
	}
	
	link_queue_node *ptmp = lqueue->front;
	*pd = lqueue->front->dt;
	lqueue->front = lqueue->front->next;
	free(ptmp);	
	
	if (lqueue->front == NULL)
	{
		printf("this is the last node\n");
		lqueue->rear = NULL;
	}
	
	return TRUE;
}

int len_link_queue(link_queue *lqueue)
{
	if (lqueue == NULL)
		return E_ARG_NULL;
	
	link_queue_node *ptmp = lqueue->front;
	int count = 0;
	while(ptmp)
	{
		count++;
		ptmp = ptmp->next; 
	}
	return count;
}

void print_link_queue(link_queue *lqueue)
{
	if (lqueue == NULL)
		return;
	
	link_queue_node *ptmp = lqueue->front;
	while (ptmp)
	{
		printf("adress:  %p,  content:  %d\n",ptmp,ptmp->dt);
		ptmp = ptmp->next; 
	}
	printf("\n");
	printf("\n");
}
