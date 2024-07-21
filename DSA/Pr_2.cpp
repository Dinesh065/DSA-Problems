//	Reverse the Array
#include<iostream>
using namespace std;

void reverseArr(int arr[] , int n)
{
    int revArr[n];
    for(int i=n-1;i>0;i--)
    {
        revArr[i] = arr[i];
    }
    cout<<"Reverse Array : ";
    for(int i=0;i<n;i++)
    {
        cout<<revArr[i];
    }

}

int main(){

    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    reverseArr(arr, n);

    return 0;
}