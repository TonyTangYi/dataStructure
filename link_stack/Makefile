COMPLIE := gcc
HEAD = link_stack.h
OBJ := lstack_main.o link_stack.o
SOURCE := linktack_main.c

lstack: $(OBJ)
	$(COMPLIE) -o lstack $(OBJ)
	
link_main.o: $(SOURCE) $(HEAD)
	$(COMPLIE) -c $(SOURCE) $(HEAD)

link_stack.o: link_stack.c link_stack.h
	gcc -c link_stack.c link_stack.h
	
.PHONY: clean	
clean:
	rm -rf *.o
	rm -rf lstack