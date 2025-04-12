#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n){
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

void bubble_sort(int arr[], int n){
    for(int i=n-1; i>=1; i--){
        for(int j=0; j<=i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insertion_sort(int arr[], int n){
    for(int i=0; i<=n-1; i++){
        int j=i;
        while(j>0 && arr[j] < arr[j-1]){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
}

bool isPalindrome(int x) {
    int palindrome = 0;
    int y=x;

    if(x < 0) return false;

    while(x != 0) {
        int last_digit = x % 10;
        palindrome = palindrome * 10 + last_digit;
        x /= 10;
    }
    return (palindrome == y);
}

int fib(int n) {
    if(n==0 || n==1) return n;
    return fib(n-1) + fib(n-2);
}

bool isPalindrome(int x) {
    int palindrome = 0;
    int y=x;

    if(x < 0) return false;

    while(x != 0) {
        int last_digit = x % 10;
        palindrome = palindrome * 10 + last_digit;
        x /= 10;
    }
    return (palindrome == y);
}

int fib(int n) {
    if(n==0 || n==1) return n;
    return fib(n-1) + fib(n-2);
}

int fib(int n) {
    if(n==0 || n==1) return n;
    return fib(n-1) + fib(n-2);
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    insertion_sort(arr, n);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}
