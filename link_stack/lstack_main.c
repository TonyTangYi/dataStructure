#include "link_stack.h"

int main()
{
	int ret;
	char *p;
	plink_stack lstack;
		
	printf("%d %d the node size : %d bytes\n",sizeof(lstack),sizeof(p),sizeof(lstack_node));
	ret = init_lstack(&lstack);
	
	if(ret < 1)
		printf("init link stack fail\n");
	else
		printf("init link list stack\n");	
	
	if(is_empty_lstack(lstack))
		printf("lstack is empty\n");
	
	for(ret = 1;ret < 20;ret++)
	{
		push_lstack(lstack,ret);
	}
	print_lstack(lstack);
	get_topElement_lstack(lstack,&ret);
	printf("the top data is %d\n",ret);
	
	printf("%p %p %p %p\n",lstack->top,lstack->top->next,&(lstack->top->dt),lstack->top->next->next);
	
	for(ret = 100;ret < 120;ret++)
	{
		push_lstack(lstack,ret);
	}
	
	print_lstack(lstack);
	printf("the stack deepth ：%d\n",deepth_lstack(lstack));
	get_topElement_lstack(lstack,&ret);
	printf("the top data is %d\n",ret);
	
	
	pop_lstack(lstack,&ret);
	printf("the stacak deepth ：%d\n",deepth_lstack(lstack));
	printf("the pop data is %d\n",ret);
	get_topElement_lstack(lstack,&ret);
	printf("the top data is %d\n",ret);
	
	print_lstack(lstack);
	destroy_lstack(&lstack);
	print_lstack(lstack);
	
	return 0;
}
