/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next=head;
        ListNode* curr=head;
        ListNode* prev=&dummy;
        int counter=0;
        if(head==NULL || head->next==NULL) return head;
        while(curr!=NULL && curr->next!=NULL){
                ListNode *first=curr;
                ListNode *second=curr->next;
                prev->next=second;
                first->next=second->next;
                second->next=first;

                prev=first;
                
               curr=curr->next;
                
            
        }
        return dummy.next;
    }
};