#include <math.h>
#include <stdio.h>
#include "search.h"
#include "utils.h"

int linear_search(int *arr, int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int jump_search(int *arr, int n, int target)
{
    int step = sqrt(n);
    int prev = 0;
    while (arr[min_int(step, n) - 1] < target)
    {
        prev = step;
        step += sqrt(n);
        if (prev >= n)
     {
            return -1;
        }
    }
}

int binary_search(int *arr, int n, int target)
{
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}