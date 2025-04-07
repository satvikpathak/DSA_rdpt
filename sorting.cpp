#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n) {
    for(int i=0; i<=n-2; i++){
        int min_idx = i;
        for(int j=i; j<=n-1; j++){
            if(arr[j] < arr[min_idx]) min_idx = j;
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void bubble_sort(int arr[], int n) {
    for(int i=n-1; i>=1; i--){
        int didswap = 0;//for optimization TC:o(n) else TC:o(n^2)
        for(int j=0; j<=i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                didswap = 1;
            }
        }
        if(didswap == 0) break;
    }
}

int main() {

    //SELECTION SORT
    // int n;
    // cin>>n;
    // int arr[n];
    // for(int i=0;i<n;i++) cin>>arr[i];
    // selection_sort(arr, n);
    // for(int i=0;i<n;i++) cout<<arr[i]<<" ";

    //BUBBLE SORT
    // int n;
    // cin>>n;
    // int arr[n];
    // for(int i=0;i<n;i++) cin>>arr[i];
    // bubble_sort(arr, n);
    // for(int i=0;i<n;i++) cout<<arr[i]<<" ";

    return 0;
}