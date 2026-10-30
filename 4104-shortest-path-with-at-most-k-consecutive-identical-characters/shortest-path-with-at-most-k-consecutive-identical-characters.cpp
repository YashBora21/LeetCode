class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
       unordered_map<int,vector<pair<int,int>>> adj;

       for(auto i:edges){
        adj[i[0]].push_back({i[1],i[2]});
       }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        pq.push({0,0,1});
        dist[0][1]=0;
        while(!pq.empty()){
            auto front=pq.top();
            int d=front[0];
            int v=front[1];
            int consec=front[2];
            pq.pop();
            
            if(d>dist[v][consec])continue;
            if(v==n-1) return d;
            
            for(auto i:adj[v]){
                int newconsec;
                if(labels[v]==labels[i.first]) newconsec=consec+1;
                else newconsec=1;
                if(newconsec>k) continue;
                if(d+i.second<dist[i.first][newconsec]){
                    dist[i.first][newconsec]=d+i.second;
                    pq.push({d+i.second,i.first,newconsec});
                }
            }
            
        }
        return -1;

    }
};