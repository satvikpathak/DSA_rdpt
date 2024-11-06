#include<bits/stdc++.h>
using namespace std;
void seeding(int n) {
   for(int i=0;i<n;i++){
	   for(int j=i;j<n;j++){
		   cout<<"* ";
	   }
	   cout<<endl;
   }
}

int main(){
    int n;
    cout<<"Enter the size of the square: ";
    cin>>n;
    seeding(n);
    return 0;
}