#include <iostream>
using namespace std;

int binary_search(int arr[], int length, int key)
{
    int l = 0;
    int r = length - 1;

    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] == key)
        {
            return m;
        }
        else if (arr[m] < key)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {10, 20, 20, 20, 30, 40, 50, 60};
    int length = sizeof(arr) / sizeof(arr[0]);
    cout << (binary_search(arr, length, 20) >= 0 ? "Found" : "Not found") << endl;
    cout << (binary_search(arr, length, 25) >= 0 ? "Found" : "Not found") << endl;
    cout << (binary_search(arr, length, 60) >= 0 ? "Found" : "Not found") << endl;
    cout << (binary_search(arr, length, 0) >= 0 ? "Found" : "Not found") << endl;
}