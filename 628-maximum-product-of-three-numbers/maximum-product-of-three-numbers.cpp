class Solution {
public:
int maximumProduct(vector<int>& nums) {
    // Min-heap to keep the 3 largest numbers
    priority_queue<int, vector<int>, greater<int>> maxElements;
    // Max-heap to keep the 2 smallest numbers
    priority_queue<int> minElements;

    for (int n : nums) {
        // Track 3 largest numbers
        maxElements.push(n);
        if (maxElements.size() > 3) {
            maxElements.pop();
        }

        // Track 2 smallest numbers
        minElements.push(n);
        if (minElements.size() > 2) {
            minElements.pop();
        }
    }

    // Extract values from the heaps
    int max3 = maxElements.top(); maxElements.pop();
    int max2 = maxElements.top(); maxElements.pop();
    int max1 = maxElements.top(); maxElements.pop(); // This is the largest absolute max

    int min2 = minElements.top(); minElements.pop();
    int min1 = minElements.top(); minElements.pop();

    // Compare product of (3 largest) vs (2 smallest * largest)
    return max(max1 * max2 * max3, min1 * min2 * max1);
}

};