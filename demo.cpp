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

//character hashing
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     string s;
//     cin>>s;

//     //precompute
//     int hash[26] = {0};
//     for(int i=0; i<s.size(); i++){
//         hash[s[i] - 'a'] ++;
//     }

//     int q;
//     cin>>q;
//     while(q--){
//         char c;
//         cin>>c;
//         //fetch
//         cout<<hash[c -'a']<<endl;
//     }

//     return 0;
// }

//hashing using map
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0; i<n; i++){
//         cin>>arr[i];
//     }

//     //precompute
//     unordered_map<int, int> mpp;
//     for(int i=0; i<n;i++){
//         mpp[arr[i]] ++;
//     }

//     //iterate over map
//     for(auto it:mpp){
//         cout<<it.first<<"->"<<it.second<<endl;
//     }

//     int q;
//     cin>>q;
//     while(q--){
//         int c;
//         cin>>c;
//         //fetch
//         cout<<mpp[c]<<endl;
//     }
//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int arr[3] = {3,4,2};
//     int nums[3];

//     for(int i=0; i<3; i++){
//         nums[i] = arr[i]*arr[i];
//     }

//     for(int i=0; i<3; i++){
//         cout<<nums[i]<<" ";
//     }

//     sort(nums, nums+3);
//     cout<<endl;

//     for(int i=0; i<3; i++){
//         cout<<nums[i]<<" ";
//     }

//     return 0;
// }


//practice LC 977: Squares of a Sorted Array
// optimized 2 pointer approach
// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> numsq(n);

//         int left = 0;
//         int right = n-1;

//         for(int i=n-1; i>=0; i--){
//             if(abs(nums[left]) > abs(nums[right])){
//                 numsq[i] = nums[left] * nums[left];
//                 left++;
//             }

//             else{
//                 numsq[i] = nums[right] * nums[right];
//                 right--;
//             }
//         }

//         return numsq;
//     }
// };