class Solution {
public:
    string minWindow(string s, string t) {

        if (s.length() < t.length())
            return "";

        vector<int> need(128, 0);
        vector<int> window(128, 0);

        // Frequency required from t
        for (char c : t) {
            need[c]++;
        }

        int required = 0;

        // Number of distinct characters required
        for (int i = 0; i < 128; i++) {
            if (need[i] > 0)
                required++;
        }

        int have = 0;

        int left = 0;

        int minLen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.length(); right++) {

            char c = s[right];

            window[c]++;

            // This character has now satisfied its required frequency
            if (need[c] > 0 &&
                window[c] == need[c]) {

                have++;
            }

            // Window is valid
            while (have == required) {

                // Update minimum window
                if (right - left + 1 < minLen) {

                    minLen = right - left + 1;
                    start = left;
                }

                // Remove left character
                char leftChar = s[left];

                window[leftChar]--;

                if (need[leftChar] > 0 &&
                    window[leftChar] < need[leftChar]) {

                    have--;
                }

                left++;
            }
        }

        if (minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};