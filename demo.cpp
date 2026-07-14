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

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        for(int i=0; i<n - 1; i++){
            if(nums[i]<=nums[i+1]){
            }

            else return false;
        }
        return true;
    }
};

int main(){
    Solution s;
    vector<int> nums = {1,2,3,6,5};
    cout<<s.check(nums)<<endl;
    return 0;
}

// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         int left = 0;
//         int right = nums.size() - 1;
//         vector<int> ans(nums.size());
//         int index = nums.size() - 1;

//         while(left <= right){
//             if(abs(nums[left]) > abs(nums[right])){
//                 ans[index] = nums[left] * nums[left];
//                 left ++;
//             }
//             else{
//                 ans[index] = nums[right] * nums[right];
//                 right --;
//             }

//             index --;
//         }

//         return ans;
//     }
// };

// class Solution {
// public:
//     double findMaxAverage(vector<int>& nums, int k) {
//         long long sum = 0;
//         for(int i=0; i<k; i++){
//             sum += nums[i];
//         }

//         long long maxSum = sum;

//         int left = 0;
//         int right = k;

//         while(right < nums.size()){
//             sum -= nums[left];
//             left ++;

//             sum += nums[right];
//             right ++;

//             maxSum = max(maxSum, sum);
//         }

//         return (double)maxSum/k;
//     }
// };

//LC209 revision
// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int left = 0;
//         int right = 0;
//         int sum = 0;
//         int length = INT_MAX;

//         while(right < nums.size()){
//             sum += nums[right];

//             while(sum >= target){
//                 length = min(length, right - left + 1);
//                 sum -= nums[left];
//                 left ++;
//             }
//             right++;
//         }

//         if(length == INT_MAX) return 0;
//         return length;
//     }
// };

//LC_3
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int left = 0;
//         int right = 0;
//         int length = 0;
//         unordered_set<char> seen;
//         while(right < s.size()){
//             while(seen.find(s[right]) != seen.end()){
//                 seen.erase(s[left]);
//                 left++;
//             }

//             seen.insert(s[right]);
//             length = max(length, right - left + 1);
//             right ++;
//         }

//         return length;
//     }
// };

//lc_88
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//      int right1 = m-1;
//      int right2 = n-1;
//      int tPtr = m + n - 1;

//      while(right1 >= 0 && right2 >= 0){
//         if(nums1[right1] > nums2[right2]){
//             nums1[tPtr] = nums1[right1];
//             right1--;
//             tPtr--;
//         }

//         else {
//             nums1[tPtr] = nums2[right2];
//             right2 --;
//             tPtr--;
//         }
//     }   

//     while(right2 >= 0){
//         nums1[tPtr] = nums2[right2];
//         right2--;
//         tPtr--;
//     }
//     }
// };

//lc283
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int left = 0;
//         int right = 0;

//         for(int right =0; right< nums.size(); right ++){
//             if(nums[right] != 0){
//                 nums[left] = nums[right];
//                 left++;
//             }
//         }

//         while(left < nums.size()){
//             nums[left] = 0;
//             left ++;
//         }
//     }
// };

//lc283
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int read = 0;
//         int write = 0;

//         for(int write=0; write<nums.size(); write++){
//             if(nums[write] != 0){
//                 nums[read] = nums[write];
//                 read++;
//             }
//         }

//         while(read < nums.size()){
//             nums[read] = 0;
//             read++;
//         }
        
//     }
// };

//lc_11
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int left = 0;
//         int right = height.size() - 1;;
//         int maxArea = 0;

//         while(left <= right){
//             int area = min(height[left], height[right]) * (right - left);
//             maxArea = max(maxArea, area);

//             if(height[left] < height[right]) left++;
//             else right--;
//         }

//         return maxArea;
//     }
// };

//lc_242
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if(s.size() != t.size()) return false;

//         unordered_map<char, int> mpp;
//         for(int i=0; i<s.size(); i++){
//             mpp[s[i]]++;
//             mpp[t[i]]--;
//         }

//         for(auto [key, val] : mpp){
//             if(val != 0) return false;
//         }

//         return true;
//     }
// };


//lc_206
// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode* temp = head;
//         ListNode* prev = nullptr;

//         while(temp != nullptr){
//             ListNode* front = temp->next;
//             temp->next = prev;
//             prev = temp;
//             temp = front;
//         }

//         return prev;
//     }
// };


//lc146
// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         ListNode* slow = head;
//         ListNode* fast = head;

//         while(fast!=nullptr && fast->next!=nullptr){
//             slow = slow->next;
//             fast = fast->next->next;
//             if(slow == fast) return true;
//         }
//         return false;
//     }
// };


//lc_876
// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         ListNode* slow = head;
//         ListNode* fast = head;

//         while(fast!=nullptr && fast->next!=nullptr){
//             slow = slow->next;
//             fast = fast->next->next;
//         }

//         return slow;
//     }
// };

//209
// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int left = 0;
//         int right = 0;
//         int sum = 0;
//         int length = INT_MAX;

//         while(right < nums.size()){
//             sum += nums[right];
//             while(sum >= target){
//                 length = min(length, right - left + 1);
//                 sum -= nums[left];
//                 left++;
//             }
//             right ++;
//         }

//         if(length == INT_MAX) return 0;
//         else return length;
//     }
// };


//lc_88
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int right1 = m-1;
//         int right2 = n-1;
//         int index = m + n - 1;

//         while(right1 >= 0 && right2 >= 0){
//             if(nums1[right1] > nums2[right2]){
//                 nums1[index] = nums1[right1];
//                 index--;
//                 right1--;
//             }
//             else{
//                 nums1[index] = nums2[right2];
//                 index--;
//                 right2--;
//             }
//         }

//         while(right2 >= 0){
//             nums1[index] = nums2[right2];
//             right2--;
//             index--;
// }
//     }
// };

//lc_3
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int left = 0;
//         int right = 0;
//         int length = 0;

//         unordered_set<char> mpp;
//         while(right < s.size()){
//             while(mpp.find(s[right]) != mpp.end()){
//                 mpp.erase(s[left]);
//                 left++;
//             }

//             mpp.insert(s[right]);
//             length = max(length, right - left + 1);
//             right ++;
//         }

//         return length;
//     }
// };

//lc_724
// class Solution {
// public:
//     int pivotIndex(vector<int>& nums) {
//         int sum = 0;
//         int leftSum = 0;

//         for(int i=0; i<nums.size(); i++){
//             sum += nums[i];
//         }

//         for(int i = 0; i<nums.size(); i++){
//             if(leftSum == sum - leftSum - nums[i]){
//                 return i;
//             }

//             leftSum += nums[i];
//         }

//         return -1;
//     }
// };

//lc242
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if(s.size() != t.size()) return false;

//         unordered_map<char, int> mpp;
//         for(int i=0; i<s.size(); i++){
//             mpp[s[i]]++;
//             mpp[t[i]]--;
//         }

//         for(auto [key, value]: mpp){
//             if(value != 0) return false;
//         }

//         return true;
//     }
// };

// lc_34
// class Solution {
// public:
//     int left(vector<int>& nums, int target){
//         int left = 0;
//         int right = nums.size() - 1;
//         int ans = -1;

//         while(left <= right){
//             int mid = left + (right - left)/2;

//             if(nums[mid] == target){
//                 ans = mid;
//                 right = mid - 1;
//             }

//             else if(nums[mid] > target){
//                 right = mid - 1;
//             }

//             else{
//                 left = mid + 1;
//             }
//         }

//         return ans;
//     }

//     int right(vector<int>& nums, int target){
//         int left = 0;
//         int right = nums.size() - 1;
//         int ans = -1;

//         while(left <= right){
//             int mid = left + (right - left)/2;

//             if(nums[mid] == target){
//                 ans = mid;
//                 left = mid + 1;
//             }

//             else if(nums[mid] < target){
//                 left = mid + 1;
//             }

//             else{
//                 right = mid - 1;
//             }
//         }

//         return ans;
//     }

//     vector<int> searchRange(vector<int>& nums, int target) {
//         return {left(nums, target), right(nums, target)};
//     }
// };

//lc21
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         if(list1 == nullptr) return list2;
//         if(list2 == nullptr) return list1;
//         if(list1->val > list2->val) swap(list1,list2);

//         ListNode* res = list1;
//         while(list1 != nullptr && list2 != nullptr){
//             ListNode* temp = list1;
//             while(list1 != nullptr && list1->val <= list2->val){
//                 temp = list1;
//                 list1 = list1->next;
//             }
//             temp->next = list2;
//             swap(list1, list2);
//         }
//         return res;
//     }
// };

// class Solution {
// public:
//     int left(vector<int>& nums, int target){
//         int left = 0;
//         int right = nums.size() - 1;
//         int ans = -1;

//         while(left <= right){
//             int mid = left + (right - left)/2;

//             if(nums[mid] == target){
//                 ans = mid;
//                 right = mid - 1;
//             }

//             else if(nums[mid] > target){
//                 right = mid - 1;
//             }

//             else{
//                 left = mid + 1;
//             }
//         }

//         return ans;
//     }

//     int right(vector<int>& nums, int target){
//         int left = 0;
//         int right = nums.size() - 1;
//         int ans = -1;

//         while(left <= right){
//             int mid = left + (right - left)/2;

//             if(nums[mid] == target){
//                 ans = mid;
//                 left = mid + 1;
//             }

//             else if(nums[mid] < target){
//                 left = mid + 1;
//             }

//             else{
//                 right = mid - 1;
//             }
//         }

//         return ans;
//     }

//     vector<int> searchRange(vector<int>& nums, int target) {
//         return {left(nums, target), right(nums, target)};
//     }
// };