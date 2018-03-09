#include "sequence_stack.h"

int init_sqstack(psequence_stack  sqstack)
{
	if (sqstack == NULL)
		return E_ARG_NULL;
	sqstack->pdt  = (element_type *) malloc(STACK_BASE_SIZE * sizeof(element_type));
	if (sqstack->pdt == NULL)
		return E_MALLOC;
	else
	{
		sqstack->stack_max_size = STACK_BASE_SIZE;
		sqstack->top = EMPTY_TOP_SIZE;
		return TRUE;
	} 
}

int destroy_sqstack(sequence_stack * sqstack)
{
	if (sqstack == NULL || sqstack->pdt == NULL)
		return E_ARG_NULL;
	
	free(sqstack->pdt);
	sqstack->pdt = NULL;
	return TRUE;
	
}

int is_empty_sqstack(sequence_stack * sqstack)
{
	if (sqstack == NULL || sqstack->pdt == NULL)
	{
		return TRUE;
	}
	
	if(sqstack->top == EMPTY_TOP_SIZE)
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
	if(sqstack->top >= sqstack->stack_max_size - 1)
		return TRUE;
	else
		return FALSE;
}


u32 deepth_sqstack(sequence_stack *sqstack)
{
	if(sqstack == NULL || sqstack->pdt == NULL)
		return FALSE;
	return sqstack->top + 1;
}

int push_sqstack(sequence_stack *sqstack,element_type dt)
{
	if (sqstack == NULL || sqstack->pdt == NULL)
		return E_ARG_NULL;

	if (is_full_sqstack(sqstack))
	{
		element_type *ptmp;
		ptmp = (element_type *)realloc(sqstack,(sqstack->stack_max_size + STACK_EXTEND_SIZE) * sizeof(element_type));
		if (ptmp == NULL)
			return E_MALLOC;
		sqstack->pdt = ptmp;
		sqstack->stack_max_size += STACK_EXTEND_SIZE;
	}
	
	sqstack->pdt[++sqstack->top] = dt;
	return TRUE;
}

int pop_sqstack(sequence_stack *sqstack,element_type *pd)
{
	if (sqstack == NULL || sqstack->pdt == NULL || pd == NULL)
		return E_ARG_NULL;
	if (is_empty_sqstack(sqstack))
		return E_OUT_OF_RANGE;

	*pd = sqstack->pdt[sqstack->top--];
	return TRUE;
}


int get_topElement_sqstack(sequence_stack *sqstack,element_type *pd)
{
	if (sqstack == NULL || sqstack->pdt == NULL || pd == NULL)
		return E_ARG_NULL;
	if (is_empty_sqstack(sqstack))
		return E_OUT_OF_RANGE;
	
	*pd = sqstack->pdt[sqstack->top];
	return TRUE;
}



void print_sqstack(sequence_stack *sqstack)
{
	if (sqstack == NULL || sqstack->pdt == NULL)
		return;
	int i;
	for (i = 0;i <= sqstack->top;i++)
	{
		printf("%d_",sqstack->pdt[i]);
	}
	printf("\n");
}
