#include<bits/stdc++.h>
using namespace std;
void nStarDiamond(int n) {
    for(int i=1;i<=n;i++){
    {
        for(int j=1;j<=n-i;j++){
            cout<<" ";
        }

        for (int j = 1; j <= 2 * i - 1; j++) {
            cout << "*";
        }
    }
    cout<<endl;
    }
    
    for(int i=n;i>0;i--){
        {
            for(int j=0;j<n-i;j++){
                cout<<" ";
            }

            
           for(int j=0;j<2*i - 1;j++){
                cout<<"*";
           }
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cout<<"Enter the number of rows for the diamond: ";
    cin>>n;
    nStarDiamond(n);
    return 0;
}