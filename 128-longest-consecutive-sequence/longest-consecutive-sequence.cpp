class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int count=0,max_count=0;
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1])continue;
            if(nums[i]==(nums[i+1]-1)){
                count++;
            }
            else{
                max_count=max(count,max_count);
                count=0;
            }
            

        }
        max_count=max(count,max_count);
        return max_count+1;
    }
};