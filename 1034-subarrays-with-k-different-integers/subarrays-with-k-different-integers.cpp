class Solution {
public:
    int atmost(vector<int>& nums, int k){
        unordered_map<int,int>freq;
        int left=0;
        int ans=0;
        int sumtill=0;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
                while(freq.size()>k){
                freq[nums[left]]--;
                if(freq[nums[left]]==0){
                    freq.erase(nums[left]);
                }
                left++;
            
           
            }
             ans+=i-left+1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};