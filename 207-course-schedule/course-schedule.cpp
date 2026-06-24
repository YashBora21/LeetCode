class Solution {
public:
    bool dfs(unordered_map<int,list<int>> &adj,unordered_map<int,bool>&visited,unordered_map<int,bool>&pathvisited,int node){
        visited[node]=true;
        
        pathvisited[node]=true;

        

        
        for(auto i:adj[node]){
            if(!visited[i]){
                if(dfs(adj,visited,pathvisited,i))return true;
            }
            else if(pathvisited[i]){
                return true;
            }
            
        }
        //after visiting all path mark visited false
        pathvisited[node]=false;
        return false;
    }
    void build(vector<vector<int>>& prerequisites,unordered_map<int,list<int>> &adj){
        for(auto i:prerequisites){
            int u=i[0];
            int v=i[1];
            adj[v].push_back(u);
        }
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size()==1 ||prerequisites.size()==0) return true;
        unordered_map<int,list<int>> adj;
        build(prerequisites,adj);
        unordered_map<int,bool>visited;
        unordered_map<int,bool>pathvisited;
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs(adj,visited,pathvisited,i))return false;
                
            }
            
        }
        return true;
    }
};