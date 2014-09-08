#include <stdio.h>
#include <mpi.h>

int main(int argc, char *argv[]) {
    int     rank_id, ierr, num_ranks;
    double  start_time, wall_time;
    
    printf("C MPI minimal working example\n");
    
    ierr = MPI_Init(&argc, &argv);
    start_time = MPI_Wtime();
    ierr = MPI_Comm_size(MPI_COMM_WORLD, &num_ranks);
    ierr = MPI_Comm_rank(MPI_COMM_WORLD, &rank_id);
    
    if (rank_id == 0) {
        printf("Number of available processors = %d.\n", num_ranks);
    }
    printf("\tProcess number %d branching off.\n", rank_id);
    
    wall_time = MPI_Wtime() - start_time;
    
    if (rank_id == 0) {
        printf("Elapsed wallclock time = %8.6fs.\n", wall_time);
    }
    
    MPI_Finalize();
    return 0;
}

