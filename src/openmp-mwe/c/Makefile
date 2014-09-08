OBJS = hello_world_openmp.o
# On a Mac, g++ is an alias for clang which doesn't have great OpenMP support.
ARCH := $(firstword $(shell uname -s))
ifeq ($(ARCH),Darwin)
	CC = gcc-4.8
else
	CC = gcc
endif
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -fopenmp -std=c99
LFLAGS = -Wall -lm $(DEBUG) -fopenmp

hello_world_openmp : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o hello_world_openmp

hello_world_openmp.o : hello_world_openmp.c
	$(CC) $(CFLAGS) hello_world_openmp.c

clean:
	\rm *.o hello_world_openmp

tar:
	tar cfv hello_world_openmp.tar hello_world_openmp.c

test:
	echo "Executing with 1 thread:"
	OMP_NUM_THREADS=1
	./hello_world_openmp
	
	echo "Executing with 2 threads:"
	OMP_NUM_THREADS=2
	./hello_world_openmp
	
	echo "Executing with 4 threads:"
	OMP_NUM_THREADS=4
	./hello_world_openmp
	
	echo "Executing with 8 threads:"
	OMP_NUM_THREADS=8
	./hello_world_openmp

