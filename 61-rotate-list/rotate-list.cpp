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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* copyhead=new ListNode(head->val);
        int n=1;
        ListNode* copytail=copyhead;
        ListNode* temp=head->next;
        while(temp!=NULL){
            copytail->next=new ListNode(temp->val);
            copytail=copytail->next;
            temp=temp->next;
            n++;
        }
        k%=n;
        int ans=n-k;
        copytail->next=head;
        while(ans--){
            copyhead=copyhead->next;
        }
        int till=n-1;
        ListNode* curr=copyhead;
        while(till--){
            curr=curr->next;
        }
        curr->next=NULL;
        return copyhead;

    }
};