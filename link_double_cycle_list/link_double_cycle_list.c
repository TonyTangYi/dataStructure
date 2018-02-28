#include "link_double_cycle_list.h"

int init_dcllist(pdclink_list * head)
{
	if (head == NULL)
		return E_ARG_NULL;
	*head  = (dclink_list *) malloc(1 * sizeof(dclink_list));//head node
	if (*head  == NULL)
	{
		return E_MALLOC;
	}
	else
	{
		(*head)->next = (*head)->prior = *head;
		return TRUE;
	} 
}

void destroy_dcllist(pdclink_list * head)
{
	if (head == NULL)
		return;
		
	pdclink_list pfree = (*head)->next;
	pdclink_list pmove;
	
	while(pfree != *head)
	{
		pmove = pfree->next;
		free(pfree);
		pfree = pmove;
	}
	
	free(*head);//finally free head node
	*head = NULL;
}

int is_empty_dcllist(dclink_list * head)
{
	if (head == NULL)
	{
		return TRUE;
	}
	
	if(head->next == head && head->prior == head)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

int len_dcllist(dclink_list *head)
{
	int llist_len = 0;	
	if(head == NULL)
		return llist_len;
	dclink_list * ptmp = head;
	while(ptmp->next != head)
	{
		llist_len++;
		ptmp = ptmp->next;	
	}
	return llist_len;
}

int insert_dcllist(dclink_list *head,int position,element_type dat)
{
	if (head == NULL)
		return E_ARG_NULL;
	if (position < 1 || position > len_dcllist(head) + 1)
		return E_OUT_OF_RANGE;
	
	dclink_list * ptmp, * phead;
	phead = head;
	int i;
	for (i = 0;i < position-1;i++)//find the position
	{
		phead = phead->next;
	}
	
	ptmp = (dclink_list *)malloc(1 * sizeof(dclink_list));
	if(NULL == ptmp)
		return E_MALLOC;
	
	ptmp->dt = dat;
	
	phead->next->prior = ptmp;
	ptmp->next  = phead->next;
	ptmp->prior = phead;
	phead->next = ptmp;

	return TRUE;
}

//delete element according to the position,output the delete element value
int delete_dcllist(dclink_list *head,int position,element_type *pd)
{
	if (head == NULL || pd == NULL)
		return E_ARG_NULL;
	if (position < 1 || position > len_dcllist(head))
		return E_OUT_OF_RANGE;
	int i;
	dclink_list * ptmp;
	
	for (i = 0;i < position-1;i++)//find the position
	{
		head = head->next;
	}
	ptmp=head->next;
	*pd = ptmp->dt;
	ptmp->next->prior = head;
    head->next = ptmp->next;
	free(ptmp);
	ptmp = NULL;
	return TRUE;
}

void print_dcllist(dclink_list *head)
{
	if (head == NULL)
		return;
	int i;
	dclink_list * ptmp = head;
	while(ptmp->next != head)
	{	
		ptmp = ptmp->next;
		printf("%d_",ptmp->dt);
	}
	printf("\n");
}


void print_address_dcllist(dclink_list *head,int position)
{
	if (head == NULL)
		return;
	if (position < 1 || position > len_dcllist(head))
		return;
	int i;
	for (i = 0;i < position;i++)//find the position
	{
		head = head->next;
	}
	printf("prior adress: %p,own adress: %p,next address: %p,value: %d\n",head->prior,head,head->next,head->dt);
}