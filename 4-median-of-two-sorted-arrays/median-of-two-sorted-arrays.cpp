class Solution {
public:
    int possible(vector<int>& nums1, vector<int>& nums2,int mid){
        int c1 = upper_bound(nums1.begin(), nums1.end(), mid) - nums1.begin();
        int c2 = upper_bound(nums2.begin(), nums2.end(), mid) - nums2.begin();
        return c1+c2;


    }
    double findkthsmallest(vector<int>& nums1, vector<int>& nums2,int k){
        int low=INT_MAX;
        int high=INT_MIN;
        if(!nums1.empty()){
            low=min(nums1[0],low);
            high=max(nums1.back(),high);

        }
        if(!nums2.empty()){
            low=min(nums2[0],low);
            high=max(nums2.back(),high);
        }
        double ans=0;
        while(low<=high){
        int mid=low+(high-low)/2;
        if(possible(nums1,nums2,mid)>=k){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
        }
        return ans;
    
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int totalele=nums1.size()+nums2.size();

       if(totalele & 1){
         return findkthsmallest(nums1,nums2,(totalele/2)+1);
       }
       else{
        double mid1=findkthsmallest(nums1,nums2,(totalele/2)+1);
        double mid2=findkthsmallest(nums1,nums2,(totalele/2));
        return (mid1+mid2) / 2.0;
       }
       return 0.0;

    }
};