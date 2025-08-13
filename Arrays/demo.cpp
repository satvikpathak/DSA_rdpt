#include<bits/stdc++.h>
using namespace std;

int largest(int arr[],int n){
    int largest = arr[0];
    for(int i=0; i<n; i++){
        if(arr[i] > largest){
            largest = arr[i];
        }
    }
    return largest;

}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    largest(arr, 5);
    cout<< "Largest element is: " << largest(arr, 5) << endl;
    return 0;
}