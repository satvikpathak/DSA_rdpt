#include<bits/stdc++.h>
using namespace std;

void getNumberPattern(int n) {
    for(int i=0; i<2*n-1; i++){
        for(int j=0; j<2*n-1; j++){
            int top=i;
            int left=j;
            int right=(2*n-2)-j;
            int bottom=(2*n-2)-i;
            cout<<n-min(min(top,left),min(right,bottom));
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter the size of the square pattern: ";
    cin>>n;
    getNumberPattern(n);
    return 0;
}