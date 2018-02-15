CFLAGS = -g -Wall
DFLAGS = -Wall -DDEBUG
objects = visual.o BinaryTree.o
debug:$(objects)
	gcc -o debug $(objects)
visual.o:visual.c
	gcc $(DFLAGS) -c visual.c -o visual.o
BinaryTree.o:BinaryTree.c
	gcc $(DFLAGS) -c BinaryTree.c -o BinaryTree.o
clean:
	-rm -rf $(objects) debug
