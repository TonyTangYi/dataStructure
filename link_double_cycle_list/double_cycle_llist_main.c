#include "link_double_cycle_list.h"

int main()
{
	int ret;
	pdclink_list head;
	
	ret = init_dcllist(&head);
	
	if(ret < 1)
		printf("init link list fail\n");
	else
		printf("init link list succeess\n");	
	
	if(is_empty_dcllist(head))
		printf("llist is empty\n");	
	
	for(ret = 1;ret < 20;ret++)
	{
		insert_dcllist(head,1,ret);
	}
	print_dcllist(head);
	
	for(ret = 100;ret < 120;ret++)
	{
		insert_dcllist(head,ret-80,ret);
	}
	
	print_address_dcllist(head,20);
	print_address_dcllist(head,21);
	print_address_dcllist(head,22);
	
	print_dcllist(head);
	
    print_address_dcllist(head,4);
	print_address_dcllist(head,5);
	print_address_dcllist(head,6);
		puts("");
	insert_dcllist(head,5,1001);
	print_dcllist(head);
	
	print_address_dcllist(head,4);
	print_address_dcllist(head,5);
	print_address_dcllist(head,6);
		puts("");
	delete_dcllist(head,6,&ret);
	
	print_address_dcllist(head,4);
	print_address_dcllist(head,5);
	print_address_dcllist(head,6);
	puts("");
	print_dcllist(head);
	
	delete_dcllist(head,1,&ret);
	print_dcllist(head);
	
	while(len_dcllist(head))
	{
		delete_dcllist(head,len_dcllist(head),&ret);
		print_dcllist(head);
	}
	destroy_dcllist(&head);
	print_dcllist(head);
	
	return 0;
}
