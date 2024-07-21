//Maximum and Minimum Element in an Array
#include<iostream>
#include<limits.h>
using namespace std;

int findmin(int arr[], int n){
    int min = INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<min)
        {
            min = arr[i];
        }
    }
    return min;
}

int findmax(int arr[], int n){
    int max = INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>max)
        {
            max = arr[i];
        }
    }
    return max;
}

int main(){

    int arr[] = {1,23,4,5,56,};

    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<"Max : "<< findmin(arr, n) <<endl;
    cout<<"Min : "<< findmax(arr, n) <<endl;
    return 0;
}