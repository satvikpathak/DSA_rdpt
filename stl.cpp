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

void explainList(){
    list<int> ls;

    ls.push_back(1);
    ls.emplace_back(2);

    ls.push_front(3);
    ls.emplace_front(4);

    //rest same as vector
    //begin, end, rbegin, rend, clear, insert, size, swap
}

void explainDeque(){
    deque<int> dq;

    dq.push_back(1);
    dq.emplace_back(2);

    dq.push_front(3);
    dq.emplace_front(4);

    dq.pop_back();
    dq.pop_front();

    dq.back();
    dq.front();

    //rest same as vector
    //begin, end, rbegin, rend, clear, insert, size, swap
}

void expalinStack(){
    stack<int> st;

    st.push(1);
    st.emplace(2);

    st.top();
    st.pop();

    stack<int> st1, st2;
    st1.swap(st2);
}

void explainQueue(){
    queue<int> q;

    q.push(1);
    q.emplace(2);

    q.front();
    q.back();
    q.pop();

    queue<int> q1, q2;
    q1.swap(q2);
}

void explainPriorityQueue(){
    priority_queue<int> pq;

    pq.push(1);
    pq.emplace(2);

    pq.top();
    pq.pop();

    priority_queue<int> pq1, pq2;
    pq1.swap(pq2);

    //minimu heap
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);

    cout<<pq.top();
}

int main() {
    explainPair();
    return 0;
}