/* The following example illustrates a call from a C program to the
 * complex BLAS Level 1 function zdotc(). This function computes the
 * dot product of two double-precision complex vectors. 
 * Modified by Neal Davis from example on intel.com.
 *
 * In this example, the complex dot product is returned in the structure c. 
 */ 
#include <stdio.h>
#include "mkl.h" 

#define N 5

typedef struct{ double re; double im; } complex16;

int main(int argc, char** argv) { 
    MKL_INT n    = N,
        inca = 1,
        incb = 1; 
    MKL_Complex16 a[N], b[N], c;
    
    printf("A=\t\tB=\n");
    for(int i = 0; i < n; i++) {
        a[i].real = (double)i;
        a[i].imag = (double)i * 2.0; 
        b[i].real = (double)(n - i);
        b[i].imag = (double)i * 2.0;
        printf("%4.2f+%4.2fi\t%4.2f+%4.2fi\n",a[i].real,a[i].imag,b[i].real,b[i].imag); 
    }
    zdotc(&c, &n, a, &inca, b, &incb);
    printf("The complex dot product is:  %6.2f+%6.2fi.\n",c.real,c.imag); 
} 
