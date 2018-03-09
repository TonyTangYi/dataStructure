#include "sequence_stack.h"

int main()
{
	int ret;
	sequence_stack sstack;
	
	ret = init_sqstack(&sstack);
	
	if(ret < 1)
		printf("init sequence stack fail\n");
	else
		printf("init sequence list stack\n");	
	
	if(is_empty_sqstack(&sstack))
		printf("sqstack is empty\n");
	if(is_full_sqstack(&sstack))
		printf("sqstack is not full\n");
	
	
	for(ret = 1;ret < 20;ret++)
	{
		push_sqstack(&sstack,ret);
	}
	print_sqstack(&sstack);
	
	for(ret = 100;ret < 120;ret++)
	{
		push_sqstack(&sstack,ret);
	}
	
	print_sqstack(&sstack);


	return 0;
}
