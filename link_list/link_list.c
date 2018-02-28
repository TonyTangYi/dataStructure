#include "link_list.h"

int init_llist(plink_list * llist)
{
	if (llist == NULL)
		return E_ARG_NULL;
	*llist  = (link_list *) malloc(1 * sizeof(link_list));//head node
	if (*llist  == NULL)
	{
		return E_MALLOC;
	}
	else
	{
		(*llist)->next = NULL;
		return TRUE;
	} 
}

void destroy_llist(plink_list * llist)
{
	if (llist == NULL)
		return ;
		
	plink_list ptmp;
	while(*llist != NULL)
	{
		ptmp = (*llist)->next;
		free(*llist);
		*llist = ptmp;
	}
	*llist = NULL;
}

int is_empty_llist(link_list * llist)
{
	if (llist == NULL)
	{
		return TRUE;
	}
	
	if(llist->next == NULL)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int len_llist(link_list *llist)
{
	int llist_len = 0;	
	if(llist == NULL)
		return llist_len;
	while(llist->next != NULL)
	{
		llist_len++;
		llist = llist->next;	
	}
	return llist_len;
}

int insert_llist(link_list *llist,int position,element_type dat)
{
	if (llist == NULL)
		return E_ARG_NULL;
	if (position < 1 || position > len_llist(llist) + 1)
		return E_OUT_OF_RANGE;
	
	link_list * ptmp;
	int i;
	for (i = 0;i < position-1;i++)//find the position
	{
		llist = llist->next;
	}
	
	ptmp = (link_list *)malloc(1 * sizeof(link_list));
	if(NULL == ptmp)
		return E_MALLOC;
	
	ptmp->dt = dat;
	ptmp->next = llist->next;
	llist->next = ptmp;
	return TRUE;
}

//delete element according to the position,output the delete element value
int delete_llist(link_list *llist,int position,element_type *pd)
{
	if (llist == NULL || pd == NULL)
		return E_ARG_NULL;
	if (position < 1 || position > len_llist(llist))
		return E_OUT_OF_RANGE;
	int i;
	link_list * ptmp;
	
	for (i = 0;i < position-1;i++)//find the position
	{
		llist = llist->next;
	}
	
	ptmp = llist->next;
	*pd = ptmp->dt;
	llist->next = ptmp->next;
	free(ptmp);
	ptmp = NULL;
	return TRUE;
}

void print_llist(link_list *llist)
{
	if (llist == NULL)
		return;
	int i;
	while(llist->next != NULL)
	{	
		llist = llist->next;
		printf("%d_",llist->dt);
	}
	printf("\n");
}
