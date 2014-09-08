OBJS = hello_world_mpi.o
ARCH := $(firstword $(shell uname -s))
CC = mpicxx
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -std=c++11
LFLAGS = -Wall -lm $(DEBUG)

hello_world_mpi : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o hello_world_mpi

hello_world_mpi.o : hello_world_mpi.cpp
	$(CC) $(CFLAGS) hello_world_mpi.cpp

clean:
	\rm *.o hello_world_mpi

tar:
	tar cfv hello_world_mpi.tar hello_world_mpi.cpp

test:
	echo "Executing with 1 thread:"
	OMP_NUM_THREADS=1
	./hello_world_mpi
	
	echo "Executing with 2 threads:"
	OMP_NUM_THREADS=2
	./hello_world_mpi
	
	echo "Executing with 4 threads:"
	OMP_NUM_THREADS=4
	./hello_world_mpi
	
	echo "Executing with 8 threads:"
	OMP_NUM_THREADS=8
	./hello_world_mpi

