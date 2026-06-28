class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();

        vector<vector<pair<int, int>>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        // minFee[node] = minimum fee found so far
        vector<int> minFee(n, INT_MAX);

        // minTime[node] = minimum time found so far
        vector<int> minTime(n, INT_MAX);

        // {fee, time, node}
        priority_queue<
            tuple<int,int,int>,
            vector<tuple<int,int,int>>,
            greater<tuple<int,int,int>>
        > pq;

        pq.push({passingFees[0], 0, 0});

        minFee[0] = passingFees[0];
        minTime[0] = 0;

        while (!pq.empty()) {
            auto [fee, time, node] = pq.top();
            pq.pop();

            if (node == n - 1)
                return fee;

            for (auto &[next, edgeTime] : adj[node]) {

                int newTime = time + edgeTime;
                int newFee = fee + passingFees[next];

                if (newTime > maxTime)
                    continue;

                // Better fee
                if (newFee < minFee[next]) {
                    minFee[next] = newFee;
                    minTime[next] = newTime;
                    pq.push({newFee, newTime, next});
                }
                // Better time
                else if (newTime < minTime[next]) {
                    minTime[next] = newTime;
                    pq.push({newFee, newTime, next});
                }
            }
        }

        return -1;
    }
};