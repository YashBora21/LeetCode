class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        vector<int>ans;
        for (int i = 1; i < nums[0]; i++)
        ans.push_back(i);
        for(int i=1;i<nums.size();i++){
            if (nums[i] == nums[i-1]) continue;
            if(nums[i-1]+1!=nums[i]) {
                for(int j=1;j<(nums[i]-nums[i-1]);j++){
                    ans.push_back(nums[i-1]+j);
                }
            }
        }
        for (int i = nums.back()+1; i <= nums.size(); i++)
            ans.push_back(i);
        return ans;
    }
};