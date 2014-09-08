OBJS = hello_world_mpi.o
ARCH := $(firstword $(shell uname -s))
CC = mpicc
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -std=c99
LFLAGS = -Wall -lm $(DEBUG)

hello_world_mpi : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o hello_world_mpi

hello_world_mpi.o : hello_world_mpi.c
	$(CC) $(CFLAGS) hello_world_mpi.c

clean:
	\rm *.o hello_world_mpi

tar:
	tar cfv hello_world_mpi.tar hello_world_mpi.c

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

