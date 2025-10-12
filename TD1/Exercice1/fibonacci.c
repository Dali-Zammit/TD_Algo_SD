#include <stdlib.h>
#include <stdio.h>
#include "fibonacci.h"

// -- Version naive --
long long int fibonacci(int n){
    if (n == 0 || n == 1){
        return n;
    }
    else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}

// -- Version DP --
long long int dp_fibonacci(int n, long long int DPFib[]) {
    if (n <= 1) {
        return n;
    }

    if (DPFib[n] != -1) {
        return DPFib[n];
    }

    DPFib[n] = dp_fibonacci(n - 1, DPFib) + dp_fibonacci(n - 2, DPFib);
    return DPFib[n];
}
