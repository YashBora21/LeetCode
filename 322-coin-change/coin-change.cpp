class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            int mini=INT_MAX;
            for(int j=0;j<coins.size();j++){
                int ans=i-coins[j];
                if(ans>=0 && dp[ans]!=INT_MAX){
                    mini=min(mini,dp[ans]+1);
                }
            }
            dp[i]=mini;
        }
        if(dp[amount]==INT_MAX) return -1;
        return dp[amount];
    }
};