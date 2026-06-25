class Solution {
public:
    void bfs(unordered_map<int,list<int>>&adj,vector<int>&ans,vector<int>&indegree){
        queue<int>q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            
                int frontnode=q.front();q.pop();
                ans.push_back(frontnode);
                for(auto i:adj[frontnode]){
                    indegree[i]--;
                    if(indegree[i]==0){
                         q.push(i);
                       
                    }
                }
            
        }
        
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
        vector<int>indegree(numCourses);
        for(auto i:adj){
            for(auto j:i.second){
                indegree[j]++;
            }
        }
        

        bfs(adj,ans,indegree);
       
        
        if(ans.size()!=numCourses) return {};
        else return ans;
    }
};