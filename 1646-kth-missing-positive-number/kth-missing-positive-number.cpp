class Solution {
public:
    bool ispossible(vector<int>& arr, int k,int mid){
        int count=0;
        for(auto i:arr){
            if(i<=mid){
                count++;

            }

        }
        int mising_ele=mid-count;
        return mising_ele>=k;
    }
    int findKthPositive(vector<int>& arr, int k) {
        int low=1;
        int high= *max_element(arr.begin(),arr.end())+k;
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(ispossible(arr,k,mid)){
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