#~/usr/bin/bash
rm ./dot_product
module load gcc
g++ quad.cpp -lquadmath -std=c99 -o dot_product
