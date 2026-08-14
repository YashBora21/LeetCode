class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> freq;
        int left=0;
        int ans=0;
        for(int i=0;i<s.length();i++){
            freq[s[i]]++;
            while(freq['a']>0 && freq['b']>0 && freq['c']>0 ){
               
                ans+=s.length()-i;
                freq[s[left]]--;
                left++;
            }
            
            
        }
        return ans;
    }
};