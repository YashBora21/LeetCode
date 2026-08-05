class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long count =0;
        long long countc=0;
        for(char i:s){
            if(i==c) {
                count+=1+countc;
                countc++;
                }
            
        }
        return count;
    }
};