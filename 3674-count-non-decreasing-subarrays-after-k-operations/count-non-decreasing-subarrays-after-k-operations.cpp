class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        deque<int>dq;
        long long cost=0;
        long long  ans=0;
        int r=nums.size()-1;
        for(int l=nums.size()-1;l>=0;l--){
            while(!dq.empty() && nums[dq.front()]<= nums[l]){
                int idx=dq.front();
                dq.pop_front();
                int nextidx=0;
                if(dq.empty()) nextidx=r+1;
                else nextidx=dq.front();
                cost+=(long long)(nextidx-idx)*(nums[l]-nums[idx]);
            }
            dq.push_front(l);
            while(cost>k){
                cost-=nums[dq.back()]-nums[r];
                if(dq.back()==r)dq.pop_back();
                r--;
            }
            ans+=r-l+1;
        }
        return ans;
    }
};