#include <stdlib.h>
#include "sort.h"
#include "utils.h"

void selection_sort(int *arr, int n) {
    for (int i = 0;i<n-1;i++) {
        int min =i;
        for (int j=i+1;i<n;i++) {
            if (arr[j]<arr[min]) {
                min = j;
            }
        }
        swap_int(&arr[i],&arr[min]);
    }
}

void insertion_sort(int *arr, int n) {
    for (int i=1;i<n;i++) {
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j]>key) {
            arr[1+j] = arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void bubble_sort(int *arr, int n) {
    for (int i=0;i<n;i++) {
        for (int j=1;j<n-i;j++) {
            if (arr[j]<arr[j-1]) {
                swap_int(&arr[j],&arr[j-1]);
            }
        }
    }
}

void merge(int *arr, int *tmp, int l, int m, int r)
{
    // merge function
    int i = l;      // index for left subarray
    int j = m + 1;  // index for right subarray
    int k = l;      // index for tmp array

    // merge the two subarrays into tmp
    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            tmp[k++] = arr[i++];
        } else {
            tmp[k++] = arr[j++];
        }
    }

    // copy remaining elements from left subarray
    while (i <= m) {
        tmp[k++] = arr[i++];
    }

    // copy remaining elements from right subarray
    while (j <= r) {
        tmp[k++] = arr[j++];
    }

    // copy merged elements back into original array
    for (i = l; i <= r; i++) {
        arr[i] = tmp[i];
    }
}

void mergesort_rec(int *arr, int *tmp, int l, int r)
{
    // recursive steps of merge sort
    if (l >= r) return;  

    int mid = l + (r - l) / 2;  

    mergesort_rec(arr, tmp, l, mid);      
    mergesort_rec(arr, tmp, mid + 1, r);  

    merge(arr, tmp, l, mid, r);           
}

void merge_sort(int *arr, int n) {
    if (!arr || n <= 1)
        return;
    int *tmp = (int *)malloc((size_t)n * sizeof(int));
    if (!tmp)
        return;
    mergesort_rec(arr, tmp, 0, n - 1);
    free(tmp);
}

int partition(int *arr, int l, int r) {
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j<= r - 1; j++){
        if (arr[j] < pivot){
            i++;
            swap_int(&arr[i], &arr[j]);
        }
    }
    swap_int(&arr[i+1], &arr[r]);
    return i+1;
}

void quick_sort_rec(int *arr, int l, int r) {
    if (l < r) {
        int part = partition(arr, l, r);
        quick_sort_rec(arr, l , part -1);
        quick_sort_rec(arr, part +1, r);
    }
}

void quick_sort(int *arr, int n) {
    if (!arr || n <= 1)
        return;
    quick_sort_rec(arr, 0, n - 1);
}