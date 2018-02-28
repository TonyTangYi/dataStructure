#include "link_list.h"

int main()
{
	int ret;
	plink_list linklist;
	
	ret = init_llist(&linklist);
	
	if(ret < 1)
		printf("init link list fail\n");
	else
		printf("init link list succeess\n");	
	
	if(is_empty_llist(linklist))
		printf("llist is empty\n");	
	
	for(ret = 1;ret < 20;ret++)
	{
		insert_llist(linklist,1,ret);
	}
	print_llist(linklist);
	
	for(ret = 100;ret < 120;ret++)
	{
		insert_llist(linklist,ret-80,ret);
	}
	
	print_llist(linklist);
	
	insert_llist(linklist,5,1001);
	print_llist(linklist);
	
	delete_llist(linklist,6,&ret);
	print_llist(linklist);
	
	delete_llist(linklist,1,&ret);
	print_llist(linklist);
	
	while(len_llist(linklist))
	{
		delete_llist(linklist,len_llist(linklist),&ret);
		print_llist(linklist);
	}
	destroy_llist(&linklist);
	print_llist(linklist);
	
	return 0;
}
