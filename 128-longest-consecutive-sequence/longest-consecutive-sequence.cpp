class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        int max_len=INT_MIN;
        if(nums.size()==0) return 0;
        unordered_set<int> num_set(nums.begin(), nums.end());
        for(int i:num_set){
            if(num_set.find(i-1)==num_set.end()){
                int curr=i;
                int streak=1;
                while(num_set.find(curr+1)!=num_set.end()){
                    streak++;
                    curr++;
                }
                max_len=max(max_len,streak);
            }
        }
        return max_len;

    }
};