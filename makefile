CC = g++
DEBUG = -g
CFLAGS = -Wall -c -std=c++11 -O0 -pedantic-errors $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: encode decode

encode: encode.o	
	$(CC) $(LFLAGS) -o encode encode.o

decode: decode.o	
	$(CC) $(LFLAGS) -o decode decode.o

encode.o: encode.cpp	
	$(CC) $(CFLAGS)	encode.cpp

decode.o: decode.cpp	
	$(CC) $(CFLAGS)	decode.cpp

clean:
	rm -rf encode
	rm -rf decode
	rm -rf *.o	
  	
run:
	./encode input.txt
  
