class Solution {
public:
    void dijibfs(priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>&pq,unordered_map<int,vector<pair<int,int>>>&adj,int src,int dst,int k,vector<vector<int>>&dist,int n){
        pq.push({0,src,0});
        dist[src][0]=0;
        while(!pq.empty()){
            auto front=pq.top();
            pq.pop();
            int stops=front[2];
            if(front[0]>dist[front[1]][stops])continue;
            for(auto i:adj[front[1]]){
                int distance=front[0]+i.first;
                int newstops=stops+1;
                if(newstops<=k+1){
                    if(distance<dist[i.second][newstops]){
                    dist[i.second][newstops]=distance;
                    pq.push({distance,i.second,stops+1});
                    }
                }
            }
        }
    }
    void build(vector<vector<int>>& flights,unordered_map<int,vector<pair<int,int>>>&adj){
        for(auto i:flights){
            int u=i[0];
            int v=i[1];
            int dis=i[2];
            adj[u].push_back({dis,v});
        }
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        unordered_map<int,vector<pair<int,int>>>adj;
        build(flights,adj);
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dijibfs(pq,adj,src,dst,k,dist,n);
        int min_dis=INT_MAX;
        int ans=INT_MAX;
         for(int f = 0; f <= k + 1; f++){
            ans = min(ans, dist[dst][f]);
        }

        return ans == INT_MAX ? -1 : ans;
        

    }
};