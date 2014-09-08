#include <iostream>
#include <omp.h>

using namespace std;

int main(int argc, char *argv[]) {
    int     rank_id;
    double  start_time, wall_time;
    
    cout << "C++ OpenMP minimal working example\n"
         << "Number of available processors =" << omp_get_num_procs() <<".\n"
         << "Number of available threads = " << omp_get_max_threads() <<".\n";
    
    start_time = omp_get_wtime();
#pragma omp parallel private (rank_id)
    {
        rank_id = omp_get_thread_num();
        cout << "\tProcess number " << rank_id << " branching off.\n";
    }
    
    wall_time = omp_get_wtime() - start_time;
    
    cout << "Elapsed wallclock time = " << wall_time << "s.\n";
    return 0;
}

