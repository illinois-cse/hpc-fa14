#include <stdio.h>
#include <stdlib.h>
#define N 10000

void init_array(int** array, unsigned int n) {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            array[j][i] = 0;
}

int main(int argc, char** argv) {
    int** array;
    unsigned long n;
    
    /* Read the desired size off of the command line. */
    n = (argc > 1 ? strtoul(argv[1], NULL, 0) : N);
    printf("Matrix size:  %dx%d\n", n, n);
    
    /* Create the array. */
    array = (int**) malloc(n*sizeof(int*));
    for (int i = 0; i < n; i++)
        array[i] = (int*) malloc(n*sizeof(int));
    
    /* Initialize the array to zero. */
    init_array(array, n);
    
    /* Free the array. */
    for (int i = 0; i < n; i++)
        free(array[i]);
    free(array);
    
    return 0;
}

