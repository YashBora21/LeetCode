class Solution {
public:
    bool ispossible(vector<int>& nums, int threshold,int mid){
        int total=0;
        for(auto i:nums){
            total+=(i+mid-1)/mid;
        }
        return total<=threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low= 1;
        int high= *max_element(nums.begin(),nums.end());
        int ans=high;
        while(high>=low){
            int mid=low+(high-low)/2;
            if(ispossible(nums,threshold,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid +1;

            }
        }
        return ans;
    }
};