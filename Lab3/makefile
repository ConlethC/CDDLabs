cc=g++
cflags= -std=c++11 -g -pthread -o sig.o
debugflags= -g -o0 -std=c++11 -pthread
cfiles= signal.cpp Semaphore.cpp
all: $(cfiles)
	$(cc) $(cflags) $(cfiles)
debug:sig.o
	$(cc) $(debugflags) $(cfiles)
	gdb sig.o

clean:rm *.o
