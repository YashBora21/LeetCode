class Solution {
public:
    int summ(int num) {
        int sum = 0;
        while (num != 0) {
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        
        // 1. Pair up each element with its original index: {value, original_index}
        vector<pair<int, int>> vec(n);
        for (int i = 0; i < n; ++i) {
            vec[i] = {nums[i], i};
        }

        // 2. Sort the array using the problem's rules
        // Sort by digit sum first, then by original number value
        sort(vec.begin(), vec.end(), [this](const pair<int, int>& a, const pair<int, int>& b) {
            int sumA = summ(a.first);
            int sumB = summ(b.first);
            if (sumA != sumB) {
                return sumA < sumB;
            }
            return a.first < b.first;
        });

        // 3. Track swaps using a simple positioning loop
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            // vec[i].second tells us the original index of the item now at 'i'
            // If it is not in its correct place (i), we swap it back
            while (vec[i].second != i) {
                // Swap the current element with the element sitting at its true destination index
                swap(vec[i], vec[vec[i].second]);
                ans++; // Count the swap
            }
        }

        return ans;
    }
};
