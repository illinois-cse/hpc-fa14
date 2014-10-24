# A Practical Introduction to High-Performance Computing Using CampusCluster
### Computational Science and Engineering Training • Fall 2014

https://slid.es/uiuc-cse/hpc-fa14/

## Agenda
### Campus Cluster
-   What is Campus Cluster?
    -   Campus Cluster background
    -   Logging in and first look
        -   `ssh`, `pwd`, `ls`, `ls /`, `exit`
    -   Shells & architecture (graphic)
    -   Navigating the environment (`ssh`, module, file system)
        -   Accessing Campus Cluster (`ssh`; PuTTY for Windows)
            -   `ssh`
            -   `scp` to/from `$USER@taub:~/hpc-sp14/data/aeotab_9.xlsx`
            -   `wget https://github.com/uiuc-cse/hpc-fa14/raw/gh-pages/data/hpc-src.tar.gz`
        -   `who`/`whoami`
        -   `nano`/`vi`/`emacs`
        -   `module` (`ldd bin/nwchem ; module load intel mvapich2 ; ldd bin/nwchem`)
            -   What are the advantages of `module`?  (tab completion,
                namespace clutter, versions)
    -   `/`, `/home` (2GB), `/projects` (more), `/scratch` (running),
        `/gpfs/gpfs_data01/.snapshots/*/{home, projects}`
        -   `ln -s /scratch/users/$USER ./scratch`
        -   `ln -s /projects/cse/shared/$USER`
        -   Exercise:  `ln -s /gpfs/gpfs_data01/.snapshots ./backup`

-   What is High-Performance Computing (HPC)?
    -   Strategies:  vectorization, distributed computing, local threading
        ([Davis et al. 2012](http://link.springer.com/article/10.1007%2Fs11227-012-0789-3))
        (jigsaw analogy)
    -   Architecture:  multicore, GPGPU, cluster (nodes and head node)
    -   Performance:  strong & weak scaling
        -   Speedup:
            $$S(N, P) = t_{N,P=1} / t_{N,P}$$
        -   Strong scaling:  how the solution time varies with the number
            of processors P for a fixed total problem size N.
            $$E(N) = t_1 / (N t_N)$$
        -   Weak scaling:  how the solution time varies with the number of
            processors P for a fixed problem size per processor N/P.
            $$E(N) = (t_1 / t_N)$$
    -   Communications:  MPI, OpenMP

-   Running code on a modern cluster
    -   Queueing
        -   Campus Cluster operations model:  all buy nodes, have guaranteed
            access, but available otherwise
        -   Moab/Torque
            -   `qsub`, `qstat`, `qdel`, `qhold`, `qrls`, `qpeek`, `showq`,
                `showstart`
            -   Fairshare queuing divides requested resources among system users
                or groups (rather than just between processes).  It incorporates
                the historic behavior of a user and group into job priority
                decisionmaking.  In principle, this allows groups and users to
                fairly access the resource.  However, this can be frustrating for
                a new user to understand, particularly when one has a number of
                jobs in the queue and it takes a long time for them to run.
    -   `mpiexec`

-   Programming, building, and debugging scientific code
    -   Compiling & building (`gcc`, `make`)
        -   Examples:  OpenMP, MPI, GNU SSL, Intel MKL
            -   `wget https://github.com/uiuc-cse/hpc-fa14/raw/gh-pages/data/hpc-src.tar.gz`
            -   `tar -xvzf hpc-src.tar.gz`
            -   MPI:  why would you want to request fewer cores per node?
        -   `./configure ; make ; make install` as a common workflow
            -   `mpicc` compiler wrapper including MPI headers and linked libraries
            -   `-show`, `-std=c99`, `-o`
            -   OpenMP:  `$OMP_NUM_THREADS` environment variable
            -   local installations (`ln` and `~/bin`)
            -   troubleshooting with libraries:  try `ldd mpiexec` to see what is
                expected
    -   Code organization (`git`) & data management
        -   `git clone https://github.com/losalamos/CLAMR`
    -   Language support and libraries for HPC
        -   Fortran; C/C++; Python; R
        -   MKL (BLAS/LAPACK/ScaLAPACK,BLACS), OpenBLAS; CUDA; MVAPICH2, OpenMPI;
            GSL; Boost; PETSc
        -   MVAPICH2 v. OpenMPI:  broadly speaking, MVAPICH2 exhibits better
            scaling than OpenMPI for many problems at higher numbers of nodes
            and bandwidth [source](http://hpc.inspur.com/images/News/2012/11/23/11EB9AD954D64F86AF46AADB2ECF289E.pdf)
        -   Compiler versions and features (Intel, GCC (esp. 4.8+))
        -   [Language microbenchmarks across languages](http://julialang.org/benchmarks/)
    -   Debugging (`gdb`, `valgrind`, numerical error)
        -   Examples:  cache misses, 
            -   `module load valgrind`
            -   `valgrind --tool=memcheck --leak-check=yes --show-reachable=yes -v ./cache_test 10000`

-   Setting up Campus Cluster to be friendlier
    -   `.bash_profile` (`ls color`), `alias` (but not to `cc`), `ssh-keygen`
    -   Running jobs in `~/scratch`:
        `cd ~/scratch ; mkdir $PBS_JOBID ; cd $PBS_JOBID`
    -   Preventative maintenance (PM) is scheduled for the third Wednesday of
        each month—long jobs submitted just prior to this time cannot run until
        afterwards.
    -   Campus Cluster User Forum
