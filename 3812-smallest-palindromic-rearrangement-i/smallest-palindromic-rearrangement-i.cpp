class Solution {
public:
    string smallestPalindrome(string s) {
        if(s.length()<=1) return s;
        vector<int>freq(26,0);
        for(auto i:s){
            freq[i-'a']++;
        }
        string mid="";
        string ans="";
        for(int i=0;i<freq.size();i++){
            if(freq[i]==0) continue;
            if(freq[i]&1)  mid=i+'a';
            for(int j=0;j<freq[i]/2;j++){
                ans+=i+'a';
            }
        }
        string rev=ans;
        reverse(rev.begin(),rev.end());
         return ans + mid + rev;
    }
};