#include<iostream>
using namespace std;

void pattern1(int n){
    for(int i=0;i<n;i++){
        for(int j=n-i;j>0;j--){
            cout<<"*";
        }
        cout<<endl;
    }
}

void pattern2(int n){
    for(int i=0;i<n;i++){
        for(int j=n-i;j>0;j--){
            cout<<"b";
        }
        cout<<endl;
    }
}

void pattern3(int n){
    for(int i=0;i<n;i++){
        for(int j=n-i-1;j>0;j--){
            cout<<" ";
        }
        for(int k=0;k<2*i + 1;k++){
            cout<<"*";
        }
        for(int l=n-i-1;l>0;l--){
            cout<<" ";
        }
        cout<<endl;
    }
}

void pattern4(int n) {
    for(int i = 0; i < n; i++) {
        for(int j=n-i;j>0;j--) {
            cout<<"*";
        }
        for(int k=0;k<2*i;k++) {
            cout<<" ";
        }
        for(int l=n-i;l>0;l--) {
            cout<<"*";
        }
        cout<<endl;
    }
}
void pattern4_rev(int n) {
    for(int i = 0; i < n; i++) {
        for(int j=1;j<=i+1;j++) {
            cout<<"*";
        }
        for(int k=2*(n-i-1);k>0;k--) {
            cout<<" ";
        }
        for(int l=1;l<=i+1;l++) {
            cout<<"*";
        }
        cout<<endl;
    }
}

int pattern5(int n){
    for(int i=0;i<2*n-1;i++){
        for(int j=0;j<2*n-1;j++){
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
    cin>>n;
    pattern2(n);
}