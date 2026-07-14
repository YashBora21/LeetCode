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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(0);
        ListNode* tail=dummy;
        int carry=0;
        
        while(l1!=NULL || l2!=NULL ||carry!=0){
            int ans=carry;
            if(l1!=NULL){
                ans+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                ans+=l2->val;
                l2=l2->next;
            }
            if(ans>9){
                ans=ans%10;
                carry=1;
            }
            else{
                carry=0;
            }
            ListNode* temp=new ListNode(ans);
            tail->next=temp;
            tail=tail->next;
            
            
        }
        return dummy->next;

    }
};