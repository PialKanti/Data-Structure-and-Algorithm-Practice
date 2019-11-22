#include <iostream>
using namespace std;

const int ARR_LEN = 10;
int arr[ARR_LEN];
int temp_arr[ARR_LEN / 2 + 1];

void merge(int A[], int start, int mid, int end)
{
    int p = start;
    int q = mid + 1;
    int k = 0;
    for (int i = start; i <= end; i++)
    {
        if (p > mid)
        {
            // Done taking first half elements
            temp_arr[k++] = A[q++];
        }
        else if (q > end)
        {
            // Done taking second half elements
            temp_arr[k++] = A[p++];
        }
        else if (A[p] < A[q])
        {
            temp_arr[k++] = A[p++];
        }
        else
        {
            temp_arr[k++] = A[q++];
        }
    }

    for (int i = 0; i < k; i++)
    {
        arr[start++] = temp_arr[i];
    }
}

void merge_sort(int A[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        merge_sort(A, start, mid);
        merge_sort(A, mid + 1, end);
        merge(A, start, mid, end);
    }
}

int main()
{
    for (int i = 0; i < ARR_LEN; i++)
    {
        arr[i] = (rand() % 10) + 1;
        cout << arr[i] << " ";
    }
    cout << endl;
    merge_sort(arr, 0, ARR_LEN - 1);

    for (int i = 0; i < ARR_LEN; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}