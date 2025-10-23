#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"
#include "utils.h"

int main(void)
{
    int n = 1000000;
    int* arr = malloc(n * sizeof(int));
    if (!arr) {
        printf("Erreur d'allocation mémoire\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = i * 2;
    }

    int target = 420000; //élément à chercher

    if (is_sorted_nondecreasing(arr, n))
    {
        // --- Jump Search ---
        clock_t start_j = clock();
        int jump_s = jump_search(arr, n, target);
        clock_t end_j = clock();
        double time_jump = ((double)(end_j - start_j)) / CLOCKS_PER_SEC * 1000;

        // --- Binary Search ---
        clock_t start_b = clock();
        int bin_s = binary_search(arr, n, target);
        clock_t end_b = clock();
        double time_bin = ((double)(end_b - start_b)) / CLOCKS_PER_SEC * 1000;

        printf("\nRésultats de recherche dans un tableau trié (%d éléments) :\n", n);
        printf("Jump Search  : index = %d, temps = %.3f ms\n", jump_s, time_jump);
        printf("Binary Search: index = %d, temps = %.3f ms\n", bin_s, time_bin);
        printf("Différence de temps : %.3f ms\n", time_jump - time_bin);
    }
    else
    {
        // --- Linear Search ---
        clock_t start_l = clock();
        int lin_s = linear_search(arr, n, target);
        clock_t end_l = clock();
        double time_lin = ((double)(end_l - start_l)) / CLOCKS_PER_SEC * 1000;

        printf("\nRésultats de recherche dans un tableau non trié (%d éléments) :\n", n);
        printf("Linear Search : index = %d, temps = %.3f ms\n", lin_s, time_lin);
    }

    free(arr);
    return 0;
}
