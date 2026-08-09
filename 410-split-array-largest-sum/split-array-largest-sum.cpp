class Solution {
public:
     bool ispossible(vector<int>& arr, int k,int mid){
       int total_split=1;
       int sum=0;
       for(auto i:arr){
        if(sum+i <=mid){
            sum+=i;
        }
        else{
            total_split++;
            sum=i;
        }

       }
       return total_split<=k;


    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high= accumulate(nums.begin(),nums.end(),0);
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(ispossible(nums,k,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;

            }
        }
        return ans;
    }
};