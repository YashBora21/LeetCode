class Solution {
public:
    int maximumNonAdjacentSum(int start,int end,vector<int> &nums){
    // Write your code here.
    
    int prev1=nums[start];
    int prev2=0;
    for(int i=start+1;i<end;i++){
        int incl=nums[i]+prev2;
        int excl=prev1;
        prev2=prev1;
        prev1=max(incl,excl);
    }
    return prev1;

}
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        return (maximumNonAdjacentSum(0,nums.size(),nums));
    }
};