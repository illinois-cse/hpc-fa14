OBJS = hello_world_mpi.o
ARCH := $(firstword $(shell uname -s))
FC = mpif90
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -std=f95
LFLAGS = -Wall -lm $(DEBUG)

hello_world_mpi : $(OBJS)
	$(FC) $(LFLAGS) $(OBJS) -o hello_world_mpi

hello_world_mpi.o : hello_world_mpi.f
	$(FC) $(CFLAGS) hello_world_mpi.f

clean:
	\rm *.o hello_world_mpi

tar:
	tar cfv hello_world_mpi.tar hello_world_mpi.f

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

