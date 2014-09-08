C     MPI Fortran minimal working example  
      
      PROGRAM HELLO
      
      INCLUDE 'mpif.h'
      
      INTEGER TID, RANKS, IERR, STATUS(MPI_STATUS_SIZE)
      
      CALL MPI_INIT(IERR)
      
      CALL MPI_COMM_SIZE(MPI_COMM_WORLD, RANKS, IERR)
      CALL MPI_COMM_RANK(MPI_COMM_WORLD, TID, IERR)
      
      IF (TID .EQ. 0) THEN
            PRINT *, 'Fortran90 MPI minimal working example'
            PRINT *, 'Number of available processors =', RANKS
      END IF
      
      PRINT *, 'Process number ', TID, ' branching off.'
      
      CALL MPI_FINALIZE(IERR)
      
      END
