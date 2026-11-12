class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int sm=1;
            int sd=1;
            for(int j=i+1;j<nums.size();j++){
                   if (nums[j - 1] < nums[j]) {
                    // Only continue if we weren't already decreasing
                    if (sd > 1) break; 
                    sm++;
                } 
                else if (nums[j - 1] > nums[j]) {
                    // Only continue if we weren't already increasing
                    if (sm > 1) break;
                    sd++;
                } 
                else {
                    // Equal elements break both strictly increasing & decreasing
                    break;
                }
                
            }
            maxi=max({maxi,sm,sd});
        }
        return maxi;
    }
};