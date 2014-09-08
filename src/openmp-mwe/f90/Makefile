OBJS = hello_world_openmp.o
ARCH := $(firstword $(shell uname -s))
FC = gfortran
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -fopenmp -std=f95
LFLAGS = -Wall -lm $(DEBUG) -fopenmp

hello_world_openmp : $(OBJS)
	$(FC) $(LFLAGS) $(OBJS) -o hello_world_openmp

hello_world_openmp.o : hello_world_openmp.f
	$(FC) $(CFLAGS) hello_world_openmp.f

clean:
	\rm *.o hello_world_openmp

tar:
	tar cfv hello_world_openmp.tar hello_world_openmp.f

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

