COMPLIE := gcc
HEAD = sequence_cycle_queue.h
OBJ := sequence_cycle_queue_main.o sequence_cycle_queue.o
SOURCE := sequence_cycle_queue_main.c

sq_cycle_queue: $(OBJ)
	$(COMPLIE) -o sq_cycle_queue $(OBJ)
	
sqstack_main.o: $(SOURCE) $(HEAD)
	$(COMPLIE) -c $(SOURCE) $(HEAD)

sequence_cycle_queue.o: sequence_cycle_queue.c sequence_cycle_queue.h
	gcc -c sequence_cycle_queue.c sequence_cycle_queue.h
	
.PHONY: clean	
clean:
	rm -rf *.o
	rm -rf sq_cycle_queue