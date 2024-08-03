#include <iostream>
using namespace std;

int mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left;    // Starting index for left subarray
    int j = mid + 1; // Starting index for right subarray
    int k = left;    // Starting index to be sorted
    int invCount = 0;

    // Merge the two subarrays
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            // There are mid - i inversions, because all elements left to j in the left subarray are greater than arr[j]
            invCount += (mid - i + 1);
        }
    }

    // Copy the remaining elements of the left subarray, if any
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy the remaining elements of the right subarray, if any
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy the sorted subarray into the original array
    for (int i = left; i <= right; i++) {
        arr[i] = temp[i];
    }

    return invCount;
}

int mergeSortAndCount(int arr[], int temp[], int left, int right) {
    int mid, invCount = 0;
    if (left < right) {
        mid = (left + right) / 2;

        invCount += mergeSortAndCount(arr, temp, left, mid);
        invCount += mergeSortAndCount(arr, temp, mid + 1, right);
        invCount += mergeAndCount(arr, temp, left, mid, right);
    }
    return invCount;
}

int findInversionCount(int arr[], int n) {
    int temp[n];
    return mergeSortAndCount(arr, temp, 0, n - 1);
}

int main() {
    int arr[] = {3, 2, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Number of Inversions are: " << findInversionCount(arr, n);
    return 0;
}
