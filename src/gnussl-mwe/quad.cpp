#include <cstdio>
extern "C" {
    #include <quadmath.h>
}

int main(int argc, char** argv) {
    __float128 foo = (1.2Q*powq(10, 4293));
    printf("cos(%Qe) = %Qf\n", foo, cosq(foo));
    return 0;
}
