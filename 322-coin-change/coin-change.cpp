class Solution {
public:
    int dpcoin(vector<int>& coins,vector<int>& dp,int amount){
        if(amount==0) return 0;
        if(amount<0) return INT_MAX;
        
        if(dp[amount]!=-1) return dp[amount];
        int ans=INT_MAX;
        for(auto coin:coins){
            int temp=dpcoin(coins,dp,amount-coin);
            if(temp!=INT_MAX)
            ans=min(ans,1+temp);
        }
        
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int ans= dpcoin(coins,dp,amount);
                return ans == INT_MAX ? -1 : ans;

    }
};