class Solution {
public:
    int fibonacci(int n,vector<int>&dp){

        if(n==1||n==0)return n;
        if(dp[n]!=-1) return dp[n];
        dp[n]= fibonacci(n-2,dp)+fibonacci(n-1,dp);
        return dp[n];
    }
    int fib(int n) {
        //your code goes here
        vector<int>dp(n+1,-1);
        return fibonacci(n,dp);

    }
};