//#include <cstdio>
#include <iostream>
#include <mpi.h>

using namespace std;

int main(int argc, char *argv[]) {
    int     rank_id, ierr, num_ranks;
    double  start_time, wall_time;
    
    MPI::Init(argc, argv);
    start_time = MPI::Wtime();
    num_ranks = MPI::COMM_WORLD.Get_size();
    rank_id = MPI::COMM_WORLD.Get_rank();
    
    if (rank_id == 0) {
        cout << "C MPI minimal working example\n";
        cout << "Number of available processors = " << num_ranks << ".\n";
    }
    printf("\tProcess number %d branching off.\n", rank_id);
    
    wall_time = MPI::Wtime() - start_time;
    
    if (rank_id == 0) {
        printf("Elapsed wallclock time = %8.6fs.\n", wall_time);
    }
    
    MPI::Finalize();
    return 0;
}

