
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        int q = queries.size();

        vector<pair<int,int>> sortedQueries;

        for(int i = 0; i < q; i++) {
            sortedQueries.push_back({queries[i], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> ans(q);

        unordered_map<int,int> mp;

        int left = 0, right = 0;

        for(auto [time, index] : sortedQueries) {

            int start = time - x;

            // Add logs up to query time
            while(right < logs.size() &&
                  logs[right][1] <= time) {

                mp[logs[right][0]]++;
                right++;
            }

            // Remove expired logs
            while(left < right &&
                  logs[left][1] < start) {

                int server = logs[left][0];

                mp[server]--;

                if(mp[server] == 0) {
                    mp.erase(server);
                }

                left++;
            }

            ans[index] = n - mp.size();
        }

        return ans;
    }
};
