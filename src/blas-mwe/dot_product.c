/* C BLAS example
 * modified by Neal Davis from an example by 3Miro
 * http://ubuntuforums.org/showthread.php?t=1740797&s=833a6945567490bb4608dface98546d0&p=11476604#post11476604
 */

#include <stdio.h>

/* All variables for FORTRAN routines are called by reference. */
double ddot_(const int* N, const double* a, const int* inca, const double* b, const int* incb);

int main(int argc, char** argv) {
    /* You can define arrays on the heap */
    double *a = (double*) malloc( 3 * sizeof(double) );
    a[0] = 1.0;
    a[1] = 2.0;
    a[2] = 3.0;
    
    /* or on the stack */
    double b[3] = { 4.0, 5.0, 6.0 };
    
    printf("A=\tB=\n");
    for (int i = 0; i < 3; i++) {
        printf("%2.1f\t%2.1f\n", a[i], b[i]);
    }
    
    int N = 3, one = 1;
    double dot_product = ddot_(&N, a, &one, b, &one);
    printf("\nA dot B = %2.1f\n", dot_product);
    
    return 0;
};
