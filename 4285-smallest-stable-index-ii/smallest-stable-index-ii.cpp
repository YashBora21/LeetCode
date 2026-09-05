class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>suf(nums.size());
        vector<int>puf(nums.size());
        suf[nums.size()-1]=nums.back();
        for(int i=nums.size()-2;i>=0;i--){
            suf[i]=min(suf[i+1],nums[i]);
        }
        puf[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            puf[i]=max(puf[i-1],nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            if(puf[i]-suf[i] <= k) return i;
        }
        return -1;

    }
};