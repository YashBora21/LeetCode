class Solution {
public:
    bool dfs(unordered_map<int,list<int>>&adj, unordered_map<int,bool>&visited,unordered_map<int,bool>&pathvisited,int node,vector<int>&ans){
        visited[node]=true;
        pathvisited[node]=true;
        
        for(auto i:adj[node]){
            if(!visited[i]){
               if( dfs(adj,visited,pathvisited,i,ans))return true;
            }
            else if(pathvisited[i]){
                return true;
            }
        }
        ans.push_back(node);
        pathvisited[node]=false;
        return false;
    }
    void build(vector<vector<int>>& prerequisites,unordered_map<int,list<int>>&adj){
        for(auto i:prerequisites){
            int u=i[0];
            int v=i[1];
            adj[v].push_back(u);
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> adj;
        build(prerequisites,adj);
        vector<int>ans;
        unordered_map<int,bool>visited;
        unordered_map<int,bool>pathvisited;
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs(adj,visited,pathvisited,i,ans)) return {};
            }

        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};