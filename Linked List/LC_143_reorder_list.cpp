#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* head2 = slow->next;
        slow->next = nullptr;
        ListNode* temp = head2;
        ListNode* prev = nullptr;

        while(temp != nullptr){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
            head2 = prev;
        }

        ListNode* temp1 = head;
        ListNode* temp2= head2;

        while(temp1 != nullptr && temp2 != nullptr){
            ListNode* front1 = temp1->next;
            ListNode* front2 = temp2->next;
            temp1->next = temp2;
            temp2->next = front1;
            temp1 = front1;
            temp2 = front2;
            
        }
    }
};

int main(){
    
    return 0;
}