#include <stdio.h>
#include <time.h>
#include "fibonacci.h"

int main() {
    int n = 30;

    clock_t start, end;
    double time_simple, time_dp;

    // -- Version naive --
    start = clock();
    long long int result_simple = fibonacci(n);
    end = clock();
    time_simple = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Version simple : Fibonacci(%d) = %lld\n", n, result_simple);
    printf("Temps d'execution (simple) : %.6f secondes\n\n", time_simple);



    // -- Version DP --
    long long int fib[n + 1];
    for (int i = 0; i <= n; i++)
        fib[i] = -1;

    start = clock();
    long long int result_dp = dp_fibonacci(n, fib);
    end = clock();
    time_dp = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Version DP : Fibonacci(%d) = %lld\n", n, result_dp);
    printf("Temps d'execution (DP) : %.6f secondes\n", time_dp);

    return 0;
}
