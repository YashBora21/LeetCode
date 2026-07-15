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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* newhead=NULL;
        ListNode* prevtail=NULL;
        while(head!=NULL){
           ListNode* temp=head;
           int cnt=0;
           while(temp!=NULL && cnt<k){
            temp=temp->next;
            cnt++;
           } 
           if(cnt<k){
            break;
           }
           ListNode* curr=head;
           ListNode* prev=temp;
           while(cnt--){
                ListNode* temp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
           }
           if(prevtail!=NULL){
                prevtail->next=prev;
           }
           else{
                newhead=prev;
           }
           prevtail=head;
           head=curr;
        }
        return newhead;
    }
    
};