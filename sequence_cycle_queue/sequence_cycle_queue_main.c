#include "sequence_cycle_queue.h"

int main()
{
	int ret;
	sequence_cycle_queue sqcycle_queue;
	
	ret = init_sqcycle_queue(&sqcycle_queue);
	
	if(ret < 1)
		printf("init sequence cycle queue fail\n");
	else
		printf("init sequence cycle queue succeess\n");	
	
	if(is_empty_sqcycle_queue(&sqcycle_queue))
		printf("sqcycle_queue is empty\n");
	if(is_full_sqcycle_queue(&sqcycle_queue))
		printf("sqcycle_queue is not full\n");
	
	
	for(ret = 1;ret < 20;ret++)
	{
		en_sqcycle_queue(&sqcycle_queue,ret);
	}
	print_sqcycle_queue(&sqcycle_queue);
	printf("the queue len is %d\n",len_sqcycle_queue(&sqcycle_queue));
	
	for(ret = 100;ret < 120;ret++)
	{
		en_sqcycle_queue(&sqcycle_queue,ret);
	}
	
	print_sqcycle_queue(&sqcycle_queue);
	printf("the queue len is %d\n",len_sqcycle_queue(&sqcycle_queue));
	
	en_sqcycle_queue(&sqcycle_queue,1001);
	print_sqcycle_queue(&sqcycle_queue);
	printf("the queue len is %d\n",len_sqcycle_queue(&sqcycle_queue));
	
	de_sqcycle_queue(&sqcycle_queue,&ret);
	print_sqcycle_queue(&sqcycle_queue);
	printf("the queue len is %d\n",len_sqcycle_queue(&sqcycle_queue));
	
	de_sqcycle_queue(&sqcycle_queue,&ret);
	print_sqcycle_queue(&sqcycle_queue);
	printf("the queue len is %d\n",len_sqcycle_queue(&sqcycle_queue));
	return 0;
}
