class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int subsets=pow(2,nums.size());
        vector<vector<int>>ans;
        for(int num=0;num<subsets;num++){
            vector<int>list;
            for(int i=0;i<nums.size();i++){
                if(num & (1<<i))list.push_back(nums[i]);

            }
            ans.push_back(list);
        }
        return ans;
    }
};