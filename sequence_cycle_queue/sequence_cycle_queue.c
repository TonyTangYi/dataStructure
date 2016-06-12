#include "sequence_cycle_queue.h"

/*
顺序循环队列非常好地解决了假溢出，但在顺序循环队列中当条件：
rear == front
成立时，队列可能为空，也可能为满，即满队列和空队列无法区分。解决方法主要有以下几种：
       ①少用一个存储单元
       ②设置一个标志位 
       ③设置一个计数器
*/
int init_sqcycle_queue(sequence_cycle_queue * sqcycle_queue)
{
	if (sqcycle_queue == NULL)
		return E_ARG_NULL;
	sqcycle_queue->pdt  = (element_type *) malloc(QUEUE_BASE_SIZE * sizeof(element_type));
	if (sqcycle_queue->pdt == NULL)
	{
		return E_MALLOC;
	}
	else
	{
		sqcycle_queue->front = 0;
		sqcycle_queue->rear = 0;
		return TRUE;
	} 
}

int destroy_sqcycle_queue(sequence_cycle_queue * sqcycle_queue)
{
	if (sqcycle_queue == NULL || sqcycle_queue->pdt == NULL)
		return E_ARG_NULL;
	
	free(sqcycle_queue->pdt);
	sqcycle_queue->pdt = NULL;
	return TRUE;
}

int is_empty_sqcycle_queue(sequence_cycle_queue * sqcycle_queue)
{
	if (sqcycle_queue == NULL || sqcycle_queue->pdt == NULL)
	{
		return TRUE;
	}
	
	if(sqcycle_queue->front == sqcycle_queue->rear)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int is_full_sqcycle_queue(sequence_cycle_queue *sqcycle_queue)
{
	if(sqcycle_queue == NULL || sqcycle_queue->pdt == NULL)
		return FALSE;
	return ((sqcycle_queue->rear+1)%QUEUE_BASE_SIZE == sqcycle_queue->front? TRUE : FALSE);
}

int en_sqcycle_queue(sequence_cycle_queue *sqcycle_queue,element_type dt)
{
	if (sqcycle_queue == NULL || sqcycle_queue->pdt == NULL)
		return E_ARG_NULL;

	if (is_full_sqcycle_queue(sqcycle_queue))
	{
		return FALSE;
	}
	
	sqcycle_queue->pdt[sqcycle_queue->rear] = dt;
	sqcycle_queue->rear = (sqcycle_queue->rear + 1) % QUEUE_BASE_SIZE;
	return TRUE;
}


int de_sqcycle_queue(sequence_cycle_queue *sqcycle_queue,element_type *pd)
{
	if (sqcycle_queue == NULL || sqcycle_queue->pdt == NULL || pd == NULL)
		return E_ARG_NULL;
	if (is_empty_sqcycle_queue(sqcycle_queue))
	{
		return FALSE;
	}
	
	*pd = sqcycle_queue->pdt[sqcycle_queue->front];
	sqcycle_queue->front = (sqcycle_queue->front + 1) % QUEUE_BASE_SIZE;
	return TRUE;
}

int len_sqcycle_queue(sequence_cycle_queue *sqcycle_queue)
{
	if (sqcycle_queue == NULL || sqcycle_queue->pdt == NULL)
		return E_ARG_NULL;
	return (sqcycle_queue->rear + QUEUE_BASE_SIZE - sqcycle_queue->front)%QUEUE_BASE_SIZE;
}

void print_sqcycle_queue(sequence_cycle_queue *sqcycle_queue)
{
	if (sqcycle_queue == NULL || sqcycle_queue->pdt == NULL)
		return;
	int pt;
	pt = sqcycle_queue->front;
	while (pt != sqcycle_queue->rear)
	{
		printf("adress:  %p,  content:  %d\n",sqcycle_queue->pdt + pt,sqcycle_queue->pdt[pt]);
		pt = (pt + 1)%QUEUE_BASE_SIZE;
	}
	printf("\n");
	printf("\n");
}
