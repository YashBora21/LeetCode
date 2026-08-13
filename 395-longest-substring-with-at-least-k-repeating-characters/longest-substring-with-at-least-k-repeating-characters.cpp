class Solution {
public:
    bool possible(vector<int>& freq, int k) {
        for(int i = 0; i < 26; i++) {
            if(freq[i] == 0) continue;

            if(freq[i] < k)
                return false;
        }

        return true;
    }

    int longestSubstring(string s, int k) {

        int length = 0;

        for(int i = 0; i < s.length(); i++) {

            vector<int> freq(26, 0);

            for(int j = i; j < s.length(); j++) {

                freq[s[j] - 'a']++;

                if(possible(freq, k)) {

                    length = max(
                        length,
                        j - i + 1
                    );
                }
            }
        }

        return length;
    }
};