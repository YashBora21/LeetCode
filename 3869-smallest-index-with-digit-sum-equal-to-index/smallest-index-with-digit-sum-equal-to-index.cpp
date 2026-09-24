class Solution {
public:
    int sumdigi(int n){
        int sum=0;
        if(n<=9) return n;
        while(n!=0){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int minidx=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if (sumdigi(nums[i])==i){
                minidx=min(minidx,i);
            }
        }
        if(minidx==INT_MAX) return -1;
        return minidx;

    }
};