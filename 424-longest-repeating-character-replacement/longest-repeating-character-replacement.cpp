class Solution {
public:
    int characterReplacement(string s, int k) {
         int ans =0;
        int left =0;
        int maxFreq=0;
        unordered_map<char,int> freq;
        for(int i=0;i<s.length();i++){
            freq[s[i]]++;
             maxFreq = max(maxFreq, freq[s[i]]);
            if(((i-left+1)-maxFreq) > k){
                freq[s[left]]--;

                left++;


            }
            else{
                ans=max(ans,i-left+1);
            }

        }
        return ans;

    }
};