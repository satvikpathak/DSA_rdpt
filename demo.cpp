// #include<bits/stdc++.h>
// using namespace std;

// vector<int> explainVector(){
//     vector<int> s(5,100);
//     s.push_back(1000);
//     s.emplace_back(2000);
//     for(auto it:s){
//         cout<<it<<" ";
//     }
//     cout<<endl;

//     for(auto it=s.begin(); it != s.end(); it++){
//         cout<<*it<<" ";
//     }
// cout<<endl;
//     for(vector<int>::iterator it = s.begin(); it != s.end(); it++){
//         cout<<*it<<" ";
//     }
//     return s;
// }

// int main(){
//     explainVector();
//     return 0;
// }


//Count Digits in a number
// #include<bits/stdc++.h>
// using namespace std;

// int count(int n){
//     int count = 0;
//     while(n>0){
//         int ld = n%10;
//         count++;
//         cout<<ld<<endl;
//         n = n/10;
//     }
//     cout<<endl;
//     cout<<count<<endl;
// }

// int main(){
//     count (54321);
//     return 0;
// }

//print name n times
// #include<bits/stdc++.h>
// using namespace std;

// void recursion(int i, int n){
//     if(i>n){
//         return;
//     }
//     cout<<"name"<<endl;
//     recursion(i+1, n);
// }

// int main(){
//     int n;
//     cin>>n;
//     recursion(1, n);
//     return 0;
// } 

//print 1 to n using recursion
// #include<bits/stdc++.h>
// using namespace std;

// void recursion(int i, int n){
//     if(i>n) return;
//     cout<<i<<endl;
//     i++;
//     recursion(i,n);
// }

// int main(){
//     int n;
//     cin>>n;
//     recursion(1,n);
//     return 0;
// }

//factorial of a number
// #include<bits/stdc++.h>
// using namespace std;

// int factorial(int n){
//     if(n==0 || n==1){
//         return 1;
//     }
//     else{
//         return n*factorial(n-1);
//     }
// }

// int main(){
//     int n;
//     cin>>n;
//     cout<<factorial(n)<<endl;   
//     return 0;
// }

