#include<bits/stdc++.h>
using namespace std;

//pairs
void explainPair(){
    pair<int, int> p = {1,3};
    cout << p.first << " " << p.second << endl;

    pair<int, pair<int, int>> p2 = {1, {3,4}};
    cout << p2.first << " " << p2.second.second << " " << p2.second.first << endl;

    pair <int,int> arr[]={{1,2},{3,4},{5,6}};
    cout<<arr[1].second;
}


//vector start
void explainVector() {

    vector<int> v;

    v. push_back (1);
    v. emplace_back(2);

    vector<pair<int, int>>vec;

    vec.push_back({1, 2});
    vec.emplace_back(1, 2);

    vector<int> v(5, 100);

    vector<int> v (5);

    vector<int> v1(5, 20) ; 
    vector<int> v2(v1);


    vector<int>:: iterator it = v. begin();

    it++;
    cout << *(it) << " ";

    it = it + 2;
    cout << *(it)<< " ";

    vector<int>:: iterator it = v.end();
    // vector<int>:: iterator it = v.rend();
    // vector<int>:: iterator it = v.rbegin();

    // cout << v[0] << " " << v.at[0];
    cout << v.back() << " ";

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *(it) << " ";
    }

    for (auto it = v.begin(); it != v.end(); it++) {
        cout << *(it) << " ";
    }
}


int main() {
    explainPair();
    return 0;
}