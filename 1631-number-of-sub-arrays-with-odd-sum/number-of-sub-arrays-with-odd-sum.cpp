class Solution {
public:
    const long long MOD=1e9+7;
    long long total=0;
    long long solve(int i,vector<int>& arr,bool isodd, vector<vector<int>>&dp){
        bool curr_odd=(arr[i]&1);
        if(i==0) return curr_odd==isodd;
        if(dp[i][isodd]!=-1) return dp[i][isodd];
        int count=0;
        if(curr_odd){
            count=solve(i-1,arr,!isodd,dp);
            if(isodd)count++;
        }
        else{
            count=solve(i-1,arr,isodd,dp);
            if(!isodd)count++;
        }
        dp[i][isodd]=count%MOD;
        return dp[i][isodd];
    }

    int numOfSubarrays(vector<int>& arr) {
        if(arr.size()==0) return 0;
        vector<vector<int>>dp(arr.size(),vector<int>(2,-1));
        for(int i=0;i<arr.size();i++){
            total=(total+solve(i,arr,true,dp))%MOD;
        }
        return total;
        
    }
};