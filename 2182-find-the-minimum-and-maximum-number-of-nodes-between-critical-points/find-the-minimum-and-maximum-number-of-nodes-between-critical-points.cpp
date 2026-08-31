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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int local_minima=-1;
        int local_maxima=-1;
        vector<int> point;

        if(head ==NULL || head->next==NULL) return {local_minima,local_maxima};
        ListNode* temp=head;
         ListNode* prev=NULL;
         int index=0;
        
        while(temp!=NULL){

            if(prev!=NULL && temp->next!=NULL){
                if(temp->val>prev->val && temp->next->val<temp->val){
                    point.push_back(index);
                }
            }
            if(prev!=NULL && temp->next!=NULL){
                if(temp->val<prev->val && temp->next->val>temp->val){
                    
                    point.push_back(index);
                }
            }
             prev=temp;
             temp=temp->next;
             index++;
            

        }
        if(point.size()<2) return {-1,-1};
        local_minima=INT_MAX;
        for(int i=1;i<point.size();i++){
            local_minima=min(local_minima,(point[i]-point[i-1]));
        }
        local_maxima=point[point.size()-1]-point[0];
        return {local_minima,local_maxima};
    }
};