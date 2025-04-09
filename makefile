binarySearchTree: main.cpp node.cpp node.h
	g++ main.cpp node.cpp -o binarySearchTree
clean: 
	rm binarySearchTree
run: binarySearchTree
	./binarySearchTree