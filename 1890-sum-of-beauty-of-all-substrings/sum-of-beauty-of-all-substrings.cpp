class Solution {
public:
    int beautySum(string s) {
        int sum=0;
       for(int i=0;i<s.length();i++){
        vector<int>freq(26,0);
        for(int j=i;j<s.length();j++){
            freq[s[j]-'a']++;
            int mx=0;
            int mi=INT_MAX;
            for(auto f:freq){
                if(f==0)continue;
                mx=max(mx,f);
                mi=min(mi,f);
            }
            sum+=mx-mi;
        }

       }
       return sum; 
    }
};