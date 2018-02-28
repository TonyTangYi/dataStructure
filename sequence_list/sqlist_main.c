#include "sequence_list.h"

int main()
{
	int ret;
	sequence_list slist;
	
	ret = init_sqlist(&slist);
	
	if(ret < 1)
		printf("init sequence list fail\n");
	else
		printf("init sequence list succeess\n");	
	
	if(is_empty_sqlist(&slist))
		printf("sqlist is empty\n");
	if(is_full_sqlist(&slist))
		printf("sqlist is not full\n");
	
	
	for(ret = 1;ret < 20;ret++)
	{
		insert_sqlist(&slist,1,ret);
	}
	print_sqlist(&slist);
	
	for(ret = 100;ret < 120;ret++)
	{
		insert_sqlist(&slist,ret-80,ret);
	}
	
	print_sqlist(&slist);
	insert_sqlist(&slist,5,1001);
	print_sqlist(&slist);
	
	delete_sqlist(&slist,6,&ret);
	print_sqlist(&slist);
	
	delete_sqlist(&slist,1,&ret);
	print_sqlist(&slist);
	
	while(slist.len)
	{
		delete_sqlist(&slist,slist.len,&ret);
		print_sqlist(&slist);
	}
	delete_sqlist(&slist,slist.len,&ret);
	print_sqlist(&slist);
	return 0;
}
