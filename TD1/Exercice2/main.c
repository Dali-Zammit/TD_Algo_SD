#include <stdio.h>
#include <time.h>
#include "prime.h"

int main() {
    int n;

    printf("Entrez une valeur de n : ");
    scanf("%d", &n);

    clock_t start, end;
    double time_naive, time;

    // ---- Version naïve ----
    start = clock();
    int count_naive = countPrimesNaive(n);
    end = clock();
    time_naive = (double)(end - start) / CLOCKS_PER_SEC;

    // ---- Version optimale ----
    start = clock();
    int count = countPrimes(n);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nRésultats :\n");
    printf("%d nombres premiers trouvés en %.6f secondes\n", count_naive, time_naive);
    printf("%d nombres premiers trouvés en %.6f secondes\n", count, time);

    return 0;
}
