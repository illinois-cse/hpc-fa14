#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[]) {
    int     rank_id;
    double  start_time, wall_time;
    
    printf("C OpenMP minimal working example\n");
    int num_ranks = omp_get_num_procs();
    printf("Number of available processors = %d.\n", num_ranks);
    int num_threads = omp_get_max_threads();
    printf("Number of available threads = %d.\n", num_threads);
    
    start_time = omp_get_wtime();
#pragma omp parallel private (rank_id)
    {
        rank_id = omp_get_thread_num();
        printf("\tProcess number %d branching off.\n", rank_id);
    }
    
    wall_time = omp_get_wtime() - start_time;
    
    printf("Elapsed wallclock time = %8.6fs.\n", wall_time);
    return 0;
}

