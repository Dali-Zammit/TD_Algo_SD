#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "prime.h"


int countPrimesNaive(int n) {
    int count = 0;

    for (int i = 2; i < n; i++) {
        bool isPrime = true;

        for (int j = 2; j < i; j++) {
            if (i % j == 0) {
                isPrime = false;
            }
        }
        if (isPrime) {
            count++;
        }
    }

    return count;
}

int countPrimes(int n) {
    if (n <= 2) return 0; 

    bool isPrime[n];
    for (int i = 0; i < n; i++)
        isPrime[i] = true;

    isPrime[0] = false;
    isPrime[1] = false;

    for (int p = 2; p * p < n; p++) {
        if (isPrime[p]) {
            for (int multiple = p * p; multiple < n; multiple += p) {
                isPrime[multiple] = false;
            }
        }
    }

    int count = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) count++;
    }

    return count;
}


