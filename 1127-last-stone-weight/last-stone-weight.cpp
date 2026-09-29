class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto i:stones){
            pq.push(i);

        }
        
        while(pq.size()>=2){
            int ele1=pq.top();
            pq.pop();
            int ele2=pq.top();
            pq.pop();
            if(ele1==ele2 && pq.empty())pq.push(ele1-ele2); 
            if(ele1!=ele2) pq.push(ele1-ele2);
        }
        return pq.top();
    }
};