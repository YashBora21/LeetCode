class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str = "";
        sort(strs.begin(), strs.end());

        int maxi = max(strs[0].size(), strs[strs.size()-1].size());

        for (int i=0; i<maxi; i++) {
            if (strs[0][i] != strs[strs.size()-1][i]) {
                break;
            } else {
                str += strs[0][i];
            }
        }

        return str;
    }
};