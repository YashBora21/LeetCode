class Solution {
public:
    bool ispossible(vector<int>& weights, int days,int mid){
        int day_cap=0;
        int tot_days=1;
        for(auto i:weights){
            if(day_cap+i <= mid){
                day_cap+=i;
            }
            else{
                tot_days++;
                day_cap=i;
            }
            
        }
        return tot_days<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
         int low= *max_element(weights.begin(),weights.end());
        int high= accumulate(weights.begin(),weights.end(),0);
        int ans=high;
        while(high>=low){
            int mid=low+(high-low)/2;
            if(ispossible(weights,days,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid +1;

            }
        }
        return ans;
    }
};