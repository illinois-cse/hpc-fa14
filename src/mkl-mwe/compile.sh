module load intel
module load mvapich2/1.6-intel
#rm *.o blas_zdot
mpicc -c -g -w -u -O0 -DMKL_ILP64 -i8 -m64 -l$MKLROOT/include blas_zdot.c -std=c99
mpicc -g -o blas_zdot blas_zdot.o -L$MKLROOT/lib/intel64 -lmkl_scalapack_ilp64 -lmkl_intel_ilp64 -lmkl_core -lmkl_sequential -lmkl_blacs_intelmpi_ilp64 -lpthread -lm

