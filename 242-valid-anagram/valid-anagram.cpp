class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;

        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for(auto i:s){
            mp1[i]++;
        }
        for(auto i:t){
            mp2[i]++;
        }
        if(mp1==mp2) return true;
        return false;
    }
};