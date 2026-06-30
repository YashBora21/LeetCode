class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positive;
        vector<int>neg;
        for(auto i:nums){
            if(i>=0) positive.push_back(i);
            else neg.push_back(i);
        }
        vector<int>ans;
        int pos=positive.size();
        int negative=neg.size();
        int i=0,j=0;
        while(pos && negative){
            ans.push_back(positive[i]);
            ans.push_back(neg[j]);
            pos--;negative--;
            i++;j++;

        }
        return ans;
    }
};