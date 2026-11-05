class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int ans=0;
        for(int i=0;i<arr1.size();i++){
            int near=lower_bound(arr2.begin(),arr2.end(),arr1[i]) - arr2.begin();
            bool valid=true;
            if(near<arr2.size() && abs(arr1[i]-arr2[near]) <=d) valid=false;
            if(near>0 && abs(arr1[i]-arr2[near-1]) <=d) valid=false;

            if(valid)ans++;
        }
        return ans;
    }
};