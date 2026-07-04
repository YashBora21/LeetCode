class Solution {
public:
    int costmin(vector<int> cost,int i,vector<int>&dp){
        if(i==0) return 0;
        if(i==1) return 0;
        
        if(dp[i]!=-1){
            return dp[i];
        }
        dp[i]=min(costmin(cost,i-1,dp)+cost[i-1],costmin(cost,i-2,dp)+cost[i-2]);
        return dp[i];

    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        return costmin(cost,cost.size(),dp);
    }
};