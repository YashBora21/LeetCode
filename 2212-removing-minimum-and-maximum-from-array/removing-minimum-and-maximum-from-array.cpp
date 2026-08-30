class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int min_ele=*min_element(nums.begin(),nums.end());
        int max_ele=*max_element(nums.begin(),nums.end());
        auto i1=find(nums.begin(),nums.end(),min_ele);
        auto i2=find(nums.begin(),nums.end(),max_ele);
        int idx1=i1-nums.begin();
        int idx2=i2-nums.begin();
        int n=nums.size();
        int left = max(idx1, idx2) + 1;
        int right = n - min(idx1, idx2);
        int both = min(idx1, idx2) + 1+ n - max(idx1, idx2);

        return min({left, right, both});
    }
};