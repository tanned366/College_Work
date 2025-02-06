#include <stdio.h>

int lin_rec_upper(int arr[], int n, int item) {
    if(arr[n-1] == item) return n-1;
    if(n == 0) return -1;
    else return lin_rec_upper(arr, n-1, item);
}

int lin_rec_lower(int arr[],int index, int n, int item) {
    if(index == n) return -1;
    if(arr[index] == item) return index;
    else return lin_rec_lower(arr, index+1, n, item);
}

int bin_rec(int arr[], int start, int end, int item) {
    int mid;
    if(start <= end) {
        mid = start + (end-start)/2;
        if(item == arr[mid]) return mid;
        else if(item < arr[mid]) return bin_rec(arr, start, mid-1, item);
        else return bin_rec(arr, mid+1, end, item);
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(arr)/sizeof(int);
    int item = 70;

    // printf("%d", lin_rec_lower(arr, 0, n, item));
    printf("%d", bin_rec(arr, 0, n-1, item));
    
    return 0;
}