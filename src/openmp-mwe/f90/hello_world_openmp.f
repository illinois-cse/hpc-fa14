C******************************************************************************
C FILE: hello_world_openmp.f
C AUTHOR: Blaise Barney  5/99
C LAST REVISED: Neal Davis  2/14
C******************************************************************************

      PROGRAM HELLO
      
      INTEGER NTHREADS, TID, OMP_GET_NUM_THREADS,
     +        OMP_GET_THREAD_NUM
      
      PRINT *, 'Fortran90 OpenMP minimal working example'
      
C     Fork a team of threads giving them their own copies of variables
!$OMP PARALLEL PRIVATE(NTHREADS, TID)
C     Obtain thread number
      TID = OMP_GET_THREAD_NUM()
      
C     Output number of threads
      IF (TID .EQ. 0) THEN
            NTHREADS = OMP_GET_NUM_THREADS()
            PRINT *, 'Number of available processors =', NTHREADS
      END IF
      
      PRINT *, 'Process number ', TID, ' branching off.'
      
C     All threads join master thread and disband
!$OMP END PARALLEL
      
      END

