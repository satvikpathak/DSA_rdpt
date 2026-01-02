#include<bits/stdc++.h>
using namespace std;

vector<int> explainVector(){
    vector<int> s(5,100);
    s.push_back(1000);
    s.emplace_back(2000);
    for(auto it:s){
        cout<<it<<" ";
    }
    cout<<endl;

    for(auto it=s.begin(); it != s.end(); it++){
        cout<<*it<<" ";
    }
cout<<endl;
    for(vector<int>::iterator it = s.begin(); it != s.end(); it++){
        cout<<*it<<" ";
    }
    return s;
}

int main(){
    explainVector();
    return 0;
}