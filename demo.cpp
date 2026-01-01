#include<bits/stdc++.h>
using namespace std;

int explainVector(){
    vector<int> s;
    s.push_back(1);
    s.emplace_back(2);
    return s;
}

int main(){
    int x = explainVector();
    cout<<x;
    return 0;
}