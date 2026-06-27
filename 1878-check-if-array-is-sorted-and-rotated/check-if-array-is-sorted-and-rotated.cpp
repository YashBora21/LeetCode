class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int>temp=nums;
        int n=temp.size();
        sort(temp.begin(),temp.end());
        for(int i=0;i<n;i++){
            temp.push_back(temp[i]);
        }
    auto it=search(temp.begin(),temp.end(),nums.begin(),nums.end());
    return it!=temp.end();
    }
};