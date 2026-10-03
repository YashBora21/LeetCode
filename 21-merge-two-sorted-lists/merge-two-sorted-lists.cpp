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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2==NULL){
            return NULL;
        }
        vector<int> nums;
        while(list1!=NULL){
            nums.push_back(list1->val);
            list1=list1->next;

        }
         while(list2!=NULL){
            nums.push_back(list2->val);
            list2=list2->next;
            
        }
        sort(nums.begin(),nums.end());
        ListNode ans(0);
        ListNode* dummy=&ans;
        for(auto i:nums){
            dummy->next=new ListNode(i);
            dummy=dummy->next;
        }
        return ans.next;


        
    }
};