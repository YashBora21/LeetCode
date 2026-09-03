class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        if(nums1.size()<2) return true ;
        bool haseven=0;
        bool hasodd=0;
        for(auto i:nums1){
            if(i&1) hasodd=1;
            else haseven=1;
        }
        if(!haseven||!hasodd) return true;
        int smallest=*min_element(nums1.begin(),nums1.end());
        if(smallest&1) return true;
        return false;
    }
};