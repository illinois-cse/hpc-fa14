#~/usr/bin/bash
rm ./dot_product
module load gcc
gcc dot_product.c -lblas -std=c99 -o dot_product
