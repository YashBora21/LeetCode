class Solution {
public:
    void bfs(unordered_map<int,list<int>>&adj,vector<vector<bool>>&reachable, vector<int>&indegree,int &numCourses){
        queue<int>q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int front=q.front();
            q.pop();
           
            for(auto i:adj[front]){
                reachable[front][i]=true;
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
                for(int k = 0; k < numCourses; k++){

                if(reachable[k][front]){

                    reachable[k][i] = true;
                }
            }
                
            }
            
            
      }

    }
    void build(vector<vector<int>>& prerequisites,unordered_map<int,list<int>>&adj){
        for(auto i:prerequisites){
            int u=i[0];
            int v=i[1];
            adj[u].push_back(v);
        }
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>>reachable(numCourses,vector<bool>(numCourses,false));
        unordered_map<int,list<int>>adj;
        vector<int>indegree(numCourses);
        build(prerequisites,adj);
        for(auto i:adj){
            for(auto j:i.second){
                indegree[j]++;
            }
        }
        vector<bool>ans;
        bfs(adj,reachable,indegree,numCourses);
        for(auto i:queries){
            ans.push_back(reachable[i[0]][i[1]]);
        }
        return ans;
        
    }
};