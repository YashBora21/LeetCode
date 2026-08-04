class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        vector<int>ans;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]+1!=nums[i]) {
                for(int j=1;j<(nums[i]-nums[i-1]);j++){
                    ans.push_back(nums[i-1]+j);
                }
            }
        }
        return ans;
    }
};