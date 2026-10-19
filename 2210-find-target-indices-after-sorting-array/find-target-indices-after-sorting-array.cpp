class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        auto range= equal_range(nums.begin(),nums.end(),target);
        if(range.first==range.second) return {};
        int first=distance(nums.begin(),range.first);
        int second=distance(nums.begin(),range.second)-1;
        vector<int>ans;
        for(int i=first;i<=second;i++){
            ans.push_back(i);
        }
        return ans;
    }
};