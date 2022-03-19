CC=g++
CFLAGS=-I.

makefile: latency.cc
	$(CC) -o latency latency.cc

clean:
	rm $(objects) latency
