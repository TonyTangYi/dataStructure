#include "link_stack.h"

int init_lstack(plink_stack * lstack)
{
	if (lstack == NULL)
		return E_ARG_NULL;
	*lstack = (plink_stack)malloc(1*sizeof(link_stack));
	if (*lstack == NULL)
		return E_MALLOC;
	(*lstack)->top = NULL;
	(*lstack)->stack_size = 0;
}

int destroy_lstack(link_stack ** lstack)
{
	if (lstack == NULL)
		return E_ARG_NULL;
	 lstack_node * tmpptr = (*lstack)->top;
	while(tmpptr != NULL)
	{
		tmpptr = (*lstack)->top->next;	
		free((*lstack)->top);
	}
	
	free(* lstack);
	*lstack = NULL;
	return TRUE;
	
}

int is_empty_lstack(link_stack * lstack)
{
	if (lstack == NULL || lstack->stack_size == 0)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

u32 deepth_lstack(link_stack *lstack)
{
	if(lstack == NULL)
		return FALSE;
	return lstack->stack_size;
}

int push_lstack(link_stack *lstack,element_type dat)
{
	if (lstack == NULL)
		return E_ARG_NULL;

	lstack_node * ptr = lstack->top;
	lstack->top = (lstack_node *)malloc(1 * sizeof(lstack_node));
	if (lstack->top == NULL)
	{
		lstack->top = ptr;
		return E_MALLOC;
	}
	
	lstack->top->dt= dat;
	lstack->top->next = ptr;
	lstack->stack_size++;
	return TRUE;
}

int pop_lstack(link_stack *lstack,element_type *pd)
{
	if (lstack == NULL || lstack->top == NULL || pd == NULL)
		return E_ARG_NULL;
	
	lstack_node * ptr = lstack->top->next;
	*pd = lstack->top->dt;
	free(lstack->top);
	lstack->top = ptr;
	lstack->stack_size--;
	return TRUE;
}


int get_topElement_lstack(link_stack *lstack,element_type *pd)
{
	if (lstack == NULL || lstack->top == NULL || pd == NULL)
		return E_ARG_NULL;

	*pd = lstack->top->dt;
	return TRUE;
}

void print_lstack(link_stack *lstack)
{
	if (lstack == NULL || lstack->top == NULL)
		return;
	int i;
	lstack_node *ptr = lstack->top;
	while(ptr != NULL)
	{
		printf("%d_",ptr->dt);
		ptr = ptr->next;
	}
	printf("\n");
}
