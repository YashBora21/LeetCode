class Solution {
public:

    int maxSum(vector<int>& nums, int k) {
        const long long MOD=1000000007;        
        vector<int> bit(31,0);
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<31;j++){
                if(nums[i]>> j&1){
                    bit[j]+=1;
                }
            }
        }
        long long ans=0;
        for(int i=0;i<k;i++){
            long long curr=0;
            for(int j=0;j<31;j++){
                if(bit[j]>0){
                    curr|=1LL<<j;
                    bit[j]--;
                }

            }
            ans=(ans+curr*curr)%MOD;
        }
        return ans;

    }
};