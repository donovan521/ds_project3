CC = g++
DEBUG = -g
CFLAGS = -Wall -c -std=c++11 -O0 -pedantic-errors $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: encode decode

encode: encode.o node.o binaryTree.o	
	$(CC) $(LFLAGS) -o encode encode.o node.o binaryTree.o

decode: decode.o node.o binaryTree.o	
	$(CC) $(LFLAGS) -o decode decode.o node.o binaryTree.o
	
binaryTree.o: binaryTree.cpp	
	$(CC) $(CFLAGS)	binaryTree.cpp

node.o: node.cpp	
	$(CC) $(CFLAGS)	node.cpp	

encode.o: encode.cpp	
	$(CC) $(CFLAGS)	encode.cpp

decode.o: decode.cpp	
	$(CC) $(CFLAGS)	decode.cpp

clean:
	rm -rf encode
	rm -rf decode
	rm -rf *.o	
  	
run:
	./encode
  
