#include "sequence_stack.h"

int init_sqstack(psequence_stack  sqstack)
{
	if (sqstack == NULL)
		return E_ARG_NULL;
	*sqstack  = (sequence_stack *) malloc(1 * sizeof(sequence_stack));
	if (sqstack->pdt == NULL)
		return E_MALLOC;
	else
	{
		sqstack->len = 0;
		sqstack->max_size = LIST_BASE_SIZE;
		return TRUE;
	} 
}

int destroy_sqstack(sequence_stack * sqstack)
{
	if (sqstack == NULL || sqstack->pdt == NULL)
		return E_ARG_NULL;
	
	free(sqstack->pdt);
	sqstack->pdt = NULL;
	sqstack->len = 0;
	sqstack->max_size = LIST_BASE_SIZE;
	return TRUE;
	
}

int is_empty_sqstack(sequence_stack * sqstack)
{
	if (sqstack == NULL || sqstack->pdt == NULL)
	{
		return TRUE;
	}
	
	if(sqstack->len == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int is_full_sqstack(sequence_stack *sqstack)
{
	if(sqstack == NULL || sqstack->pdt == NULL)
		return FALSE;
	if(sqstack->len == sqstack->max_size)
		return TRUE;
	else
		return FALSE;
}

int insert_sqstack(sequence_stack *sqstack,int position,element_type dt)
{
	if (sqstack == NULL || sqstack->pdt == NULL)
		return E_ARG_NULL;
	if (position < 1 || position > sqstack->len + 1)
		return E_OUT_OF_RANGE;
	puts("insert_sqstack");
	if (is_full_sqstack(sqstack))
	{
		element_type *ptmp;
		ptmp = (element_type *)realloc(sqstack,(sqstack->max_size + LIST_EXTEND_SIZE) * sizeof(element_type));
		if (ptmp == NULL)
			return E_MALLOC;
		sqstack->pdt = ptmp;
		sqstack->max_size += LIST_EXTEND_SIZE;
	}
	
	int i;
	for (i = sqstack->len;i > position - 1;i--)
	{
		sqstack->pdt[i] = sqstack->pdt[i-1];
	}
	
	sqstack->pdt[position-1] = dt;
	sqstack->len++;
	return TRUE;
}

//delete element according to the position,output the delete element value
int delete_sqstack(sequence_stack *sqstack,int position,element_type *pd)
{
	if (sqstack == NULL || sqstack->pdt == NULL || pd == NULL)
		return E_ARG_NULL;
	if (position < 1 || position > sqstack->len)
		return E_OUT_OF_RANGE;
	int i;
	*pd = sqstack->pdt[position-1];
	for(i = position;i < sqstack->len;i++)
	{
		sqstack->pdt[i-1] = sqstack->pdt[i];
	}
	sqstack->len--;
	return TRUE;
}

void print_sqstack(sequence_stack *sqstack)
{
	if (sqstack == NULL || sqstack->pdt == NULL)
		return;
	int i;
	for (i = 0;i < sqstack->len;i++)
	{
		printf("%d_",sqstack->pdt[i]);
	}
	printf("\n");
}
