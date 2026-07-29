class Solution {
public:
    static constexpr long long MAX = 1000001;

    long long nCk(int n, int k) {
        if (k > n) return 0;
        k = min(k, n - k);

        long long res = 1;

        for (int i = 1; i <= k; i++) {
            res = res * (n - i + 1) / i;
            if (res >= MAX)
                return MAX;
        }

        return res;
    }

    long long countArrangements(vector<int>& cnt) {
        int total = 0;
        for (int x : cnt)
            total += x;

        long long ways = 1;

        for (int x : cnt) {
            if (x == 0) continue;

            ways *= nCk(total, x);

            if (ways >= MAX)
                return MAX;

            total -= x;
        }

        return ways;
    }

    string smallestPalindrome(string s, int k) {

        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        vector<int> half(26, 0);

        string mid = "";

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;

            if (freq[i] & 1)
                mid += char(i + 'a');
        }

        if (countArrangements(half) < k)
            return "";

        int len = 0;
        for (int x : half)
            len += x;

        string left = "";

        for (int pos = 0; pos < len; pos++) {

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0)
                    continue;

                half[c]--;

                long long cnt = countArrangements(half);

                if (cnt >= k) {
                    left += char(c + 'a');
                    break;
                }

                k -= cnt;
                half[c]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return left + mid + right;
    }
};