#include "link_queue.h"

int main()
{
	int ret;
	int a = 80;
	plink_queue lqueue;
	
	ret = init_link_queue(&lqueue);
	
	if(ret < 1)
		printf("init link queue fail\n");
	else
		printf("init link queue succeess\n");	
	
	if(is_empty_link_queue(lqueue))
		printf("lqueue is empty\n");

	for(ret = 1;ret < 20;ret++)
	{
		en_link_queue(lqueue,ret);
	}
	print_link_queue(lqueue);
	printf("the queue len is %d\n",len_link_queue(lqueue));
	
	for(ret = 100;ret < 120;ret++)
	{
		en_link_queue(lqueue,ret);
	}
	
	print_link_queue(lqueue);
	printf("the queue len is %d\n",len_link_queue(lqueue));
	
	en_link_queue(lqueue,1001);
	print_link_queue(lqueue);
	printf("the queue len is %d\n",len_link_queue(lqueue));
	
	de_link_queue(lqueue,&ret);
	print_link_queue(lqueue);
	printf("the queue len is %d\n",len_link_queue(lqueue));
	
	while(a--)
		de_link_queue(lqueue,&ret);
	print_link_queue(lqueue);
	printf("the queue len is %d\n",len_link_queue(lqueue));
	return 0;
}
