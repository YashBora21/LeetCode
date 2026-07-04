class Solution {
public:
    int fibonacci(int n,vector<int>&dp){

        if(n==1||n==0)return n;
        int past2=0;
        int past1=1;
        for(int i=2;i<=n;i++){
            int curr=past1+past2;
            past2=past1;
            past1=curr;

        }
        return past1;
    }
    int fib(int n) {
        //your code goes here
        vector<int>dp(n+1,-1);
        return fibonacci(n,dp);

    }
};