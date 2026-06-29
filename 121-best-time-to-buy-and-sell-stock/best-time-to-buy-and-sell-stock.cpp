class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int profit=0;
       int minCost=prices[0];
       for(int i=1;i<prices.size();i++){
        if(profit<(prices[i]-minCost)){
            profit=prices[i]-minCost;
        }
        if(minCost>prices[i]){
            minCost=prices[i];
        }
       }
       return profit;
    }   
};