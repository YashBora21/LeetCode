class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max_num=*max_element(nums.begin(),nums.end());
        
        return (max_num*nums.size())-accumulate(nums.begin(),nums.end(),0LL);
    }
};