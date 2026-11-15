class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const long long MOD = 1e9 + 7;
        long long even = 0, odd = 0, total = 0;

        for (int num : arr) {
            if (num & 1) {
                long long prev_even = even;
                even = odd;
                odd = (prev_even + 1) % MOD;
            } else {
                even = (even + 1) % MOD;
                // 'odd' remains unchanged
            }
            total = (total + odd) % MOD;
        }

        return total;
    }
};
