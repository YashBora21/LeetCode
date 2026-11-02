class Solution {
public:
    int minMoves2(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      int median=0;
      int n=nums.size()-1;
      if(!(nums.size()&1))  median=(nums[n/2]+nums[(n/2)+1])/2;
      else median=nums[n/2];
      int ans=0;
      for(auto i:nums){
        ans+=abs(i-median);
      }
      return ans;
    }
};