class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            total=max(total,sum);
            if(sum<=0){
                sum=0;
                
            }
           
            
        }
        return total;
    }
};