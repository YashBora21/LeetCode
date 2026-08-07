class Solution {
public:
    bool ispossible(vector<int>& bloomDay,int m,int k,int mid){
        int cosecutive=0;
        int bonquets=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                cosecutive++;
                if(cosecutive==k) {
                   bonquets++;
                   cosecutive=0;
                }
            }
            else{
                cosecutive=0;

            }
        }
        if(bonquets>=m) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low= *min_element(bloomDay.begin(),bloomDay.end());
        int high= *max_element(bloomDay.begin(),bloomDay.end());
        long long  ans=0;
        if((long long)m*k > bloomDay.size()) return -1;
        while(high>=low){
           int  mid=low+(high-low)/2;
            if(ispossible(bloomDay,m,k,mid)) {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
        
            }
};