class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int>st;
        int total=0;
        int rep=0;
        for(auto i : nums){
            if(st.contains(i)){
                rep=i;
            }
            st.insert(i);
            
        }
        for(auto i:st){
            total+=i;
        }
        int n=nums.size();
        int mis=(n*(n+1))/2-total; 
        return {rep,mis};

    }
};