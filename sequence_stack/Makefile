COMPLIE := gcc
HEAD = sequence_stack.h
OBJ := sqstack_main.o sequence_stack.o
SOURCE := sqstack_main.c

sqstack: $(BOJ)
	$(COMPLIE) -o sqstack $(OBJ)

sqstack_main.o: $(SOURCE) $(HEAD)
	$(COMPLIE) -c $(SOURCE) $(HEAD)

sequence_stack.o: sequence_stack.c sequence_stack.h
	gcc -c sequence_stack.c sequence_stack.h
	
clean:
	rm -rf *.o