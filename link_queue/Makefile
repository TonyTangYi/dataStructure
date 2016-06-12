COMPLIE := gcc
HEAD = link_queue.h
OBJ := link_queue_main.o link_queue.o
SOURCE := link_queue_main.c

lqueue: $(OBJ)
	$(COMPLIE) -o lqueue $(OBJ)
	
link_queue_main.o: $(SOURCE) $(HEAD)
	$(COMPLIE) -c $(SOURCE) $(HEAD)

link_queue.o: link_queue.c link_queue.h
	gcc -c link_queue.c link_queue.h
	
.PHONY: clean	
clean:
	rm -rf *.o
	rm -rf *.gch
	rm -rf lqueue