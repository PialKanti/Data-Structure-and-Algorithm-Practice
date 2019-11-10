#include <iostream>
using namespace std;

int lower_bound_arr(int arr[], int length, int key)
{
    int l = 0;
    int r = length - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] >= key)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return l;
}

int upper_bound_arr(int arr[], int length, int key)
{
    int l = 0;
    int r = length - 1;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (arr[m] <= key)
        {
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return l;
}

int main()
{
    int arr[] = {10, 20, 20, 20, 20, 30, 40, 50, 60};
    int length = sizeof(arr) / sizeof(arr[0]);
    cout << "Lower bound of 20 = " << lower_bound_arr(arr, length, 20) << endl;
    cout << "Lower bound of 25 = " << lower_bound_arr(arr, length, 25) << endl;
    cout << "Lower bound of 50 = " << lower_bound_arr(arr, length, 50) << endl;
    cout << "Lower bound of 10 = " << lower_bound_arr(arr, length, 10) << endl;
    cout << "Lower bound of 70 = " << lower_bound_arr(arr, length, 70) << endl;

    cout << "Upper bound of 20 = " << upper_bound_arr(arr, length, 20) << endl;
    cout << "Upper bound of 25 = " << upper_bound_arr(arr, length, 25) << endl;
    cout << "Upper bound of 50 = " << upper_bound_arr(arr, length, 50) << endl;
    cout << "Upper bound of 10 = " << upper_bound_arr(arr, length, 10) << endl;
    cout << "Upper bound of 70 = " << upper_bound_arr(arr, length, 70) << endl;
}