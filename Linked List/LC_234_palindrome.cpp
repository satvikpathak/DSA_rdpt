// #include<bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         if (!head || !head->next) {
//             return true;
//         }

//         // Step 1: Find the middle of the linked list using fast and slow pointers
//         ListNode* slow = head;
//         ListNode* fast = head;
        
//         while (fast != nullptr && fast->next != nullptr) {
//             slow = slow->next;
//             fast = fast->next->next;
//         }

//         // Step 2: Reverse the second half of the list
//         ListNode* prev = nullptr;
//         ListNode* curr = slow;
        
//         while (curr != nullptr) {
//             ListNode* nextTemp = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = nextTemp;
//         }

//         // Step 3: Compare the first half and the reversed second half
//         ListNode* firstHalf = head;
//         ListNode* secondHalf = prev; // 'prev' now points to the head of the reversed second half
        
//         while (secondHalf != nullptr) {
//             if (firstHalf->val != secondHalf->val) {
//                 return false;
//             }
//             firstHalf = firstHalf->next;
//             secondHalf = secondHalf->next;
//         }

//         return true;
//     }
// };

// int main(){
    
//     return 0;
// }