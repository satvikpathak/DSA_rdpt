#include<bits/stdc++.h>
using namespace std;
void nTriangle(int n) {
	 for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;
    nTriangle(n);
    return 0;
}