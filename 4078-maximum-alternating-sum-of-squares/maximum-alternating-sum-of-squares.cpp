class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans=0,part1=0,part2=0;
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]*nums[i];
        }
        sort(nums.begin(),nums.end());
        long long mid=(nums.size())/2;
        for(int i=0;i<mid;i++){
            part1+=nums[i];
        }
        for(int i=mid;i<nums.size();i++){
            part2+=nums[i];
        }
        ans=part2-part1;
        return abs(ans);

    }
};