class Solution {
public:
    vector<int> dijibfs(unordered_map<int,vector<pair<int,int>>>&adj,int node,int n,int distanceThreshold){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>distance(n,INT_MAX);
        pq.push({0,node});
        distance[node]=0;
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            for(auto i:adj[top.second]){
                int dis=i.second+top.first;
                if(distance[i.first]>dis && dis<=distanceThreshold){
                    distance[i.first]=dis;
                    pq.push({distance[i.first],i.first});
                }
            }
        }
        return distance;
    }
    void build(vector<vector<int>>& edges,unordered_map<int,vector<pair<int,int>>>&adj){
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int dist=edges[i][2];
            adj[u].push_back({v,dist});
            adj[v].push_back({u,dist});
        }
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int,vector<pair<int,int>>>adj;
        build(edges,adj);
        int min_count=INT_MAX;
        int ans_city;
        for(int i=0;i<n;i++){
            vector<int>distance=(dijibfs(adj,i,n,distanceThreshold));
            int count=0;
            for(int j=0;j<distance.size();j++){
                if(distance[j]==INT_MAX ||i==j){
                    continue;
                }
                count++;
            }
            if(min_count>=count){
                min_count=count;
                ans_city=i;
            }
        }
        return ans_city;
        

    }
};