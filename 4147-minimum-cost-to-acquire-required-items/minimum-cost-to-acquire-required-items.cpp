class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long  ans=0;
        if((long long)cost1+cost2 > costBoth){
            if(need1>need2){
                ans+=(long long)need2*costBoth;
                need1-=need2;
                need2-=need2;
                if(costBoth<cost1){
                ans+=(long long)costBoth*need1;
                   
                }
                else{
                 ans+=(long long)need1*cost1;
                  
                }

                
            }
            else{
               ans+=(long long)need1*costBoth;
               need2-=need1;
                need1-=need1;
                
                if(costBoth<cost2){
                ans+=(long long)costBoth*need2;
                   
                }
                else{
                 ans+=(long long)need2*cost2;
                  
                } 
            }

        }
        else{
            ans += (long long)cost1 * need1 +
                (long long)cost2 * need2;       
             }
        return ans;
    }
};