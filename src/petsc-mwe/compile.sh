module load petsc
rm pbratu pbratu.o
mpicc -c pbratu.c -I $PETSC_DIR/include 
mpicc pbratu.o -o pbratu -L $PETSC_DIR/lib -lpetsc -lX11

