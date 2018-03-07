#include "sequence_list.h"

int init_sqlist(sequence_list * sqlist)
{
	if (sqlist == NULL)
		return E_ARG_NULL;
	sqlist->pdt  = (element_type *) malloc(LIST_BASE_SIZE * sizeof(element_type));
	if (sqlist->pdt == NULL)
		return E_MALLOC;
	else
	{
		sqlist->len = 0;
		sqlist->max_size = LIST_BASE_SIZE;
		return TRUE;
	} 
}

int destroy_sqlist(sequence_list * sqlist)
{
	if (sqlist == NULL || sqlist->pdt == NULL)
		return E_ARG_NULL;
	
	free(sqlist->pdt);
	sqlist->pdt = NULL;
	sqlist->len = 0;
	sqlist->max_size = LIST_BASE_SIZE;
	return TRUE;
	
}

int is_empty_sqlist(sequence_list * sqlist)
{
	if (sqlist == NULL || sqlist->pdt == NULL)
	{
		return TRUE;
	}
	
	if(sqlist->len == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int is_full_sqlist(sequence_list *sqlist)
{
	if(sqlist == NULL || sqlist->pdt == NULL)
		return FALSE;
	if(sqlist->len == sqlist->max_size)
		return TRUE;
	else
		return FALSE;
}

int insert_sqlist(sequence_list *sqlist,int position,element_type dt)
{
	if (sqlist == NULL || sqlist->pdt == NULL)
		return E_ARG_NULL;
	if (position < 1 || position > sqlist->len + 1)
		return E_OUT_OF_RANGE;
	puts("insert_sqlist");
	if (is_full_sqlist(sqlist))
	{
		element_type *ptmp;
		ptmp = (element_type *)realloc(sqlist,(sqlist->max_size + LIST_EXTEND_SIZE) * sizeof(element_type));
		if (ptmp == NULL)
			return E_MALLOC;
		sqlist->pdt = ptmp;
		sqlist->max_size += LIST_EXTEND_SIZE;
	}
	
	int i;
	for (i = sqlist->len;i > position - 1;i--)
	{
		sqlist->pdt[i] = sqlist->pdt[i-1];
	}
	
	sqlist->pdt[position-1] = dt;
	sqlist->len++;
	return TRUE;
}

//delete element according to the position,output the delete element value
int delete_sqlist(sequence_list *sqlist,int position,element_type *pd)
{
	if (sqlist == NULL || sqlist->pdt == NULL || pd == NULL)
		return E_ARG_NULL;
	if (position < 1 || position > sqlist->len)
		return E_OUT_OF_RANGE;
	int i;
	*pd = sqlist->pdt[position-1];
	for(i = position;i < sqlist->len;i++)
	{
		sqlist->pdt[i-1] = sqlist->pdt[i];
	}
	sqlist->len--;
	return TRUE;
}

void print_sqlist(sequence_list *sqlist)
{
	if (sqlist == NULL || sqlist->pdt == NULL)
		return;
	int i;
	for (i = 0;i < sqlist->len;i++)
	{
		printf("%d_",sqlist->pdt[i]);
	}
	printf("\n");
}
