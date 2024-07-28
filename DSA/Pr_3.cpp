// C++ program to solve chocolate distribution
#include <bits/stdc++.h>
using namespace std;

int findMin(int arr[], int n, int m)
{
    if(m==0 || n==0)
    {
        return 0;
    }
    int minDiff = INT_MAX; // Used to store Minimum difference between packets having maximum chocolates and packets having minimum chocolate
    if(n < m)
    {
        return -1;
    }

    sort(arr, arr+n); // Sort the array so that finding a subarray having min and max value becomes easy
    for(int i=0;i+m-1<n;i++)
    {
        int diff = arr[i+m-1]-arr[i];
        if(diff < minDiff)
        {
            minDiff = diff;
        }
    }
    return minDiff;
}

int main()
{
    int arr[] = {3, 4, 1, 9, 56, 7, 9, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    int m;
    cout<<"Enter the number of students: ";
    cin>>m;
    cout<<findMin(arr, n , m);
    return 0; 
}