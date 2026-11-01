class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_ele=*min_element(nums.begin(),nums.end());

        int ans=0;
        for(int i:nums){
            ans+=i-min_ele;
        }
        if(ans<0) return 0;
        return ans;
    }
};