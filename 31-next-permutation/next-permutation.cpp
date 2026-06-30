class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1) return ;
        int breakpoint=-1;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                breakpoint=i-1;
                break;
            }
        }
        if(breakpoint==-1) {
             reverse(nums.begin(),nums.end());
             return ;

        }
        for(int i=nums.size()-1;i>breakpoint;i--){
            if(nums[i]>nums[breakpoint]){
                swap(nums[i],nums[breakpoint]);
                break;
            }
        }
        
        reverse(nums.begin()+breakpoint+1,nums.end());
        
    }
};