class Solution {
public:
    bool iscycle(int src,vector<vector<int>>& adj, vector<vector<int>>& prerequisites, vector<bool>& vis, vector<bool>& recpath){
        vis[src] = true;
        recpath[src] = true;

        for(int v : adj[src]){

            if(!vis[v]){
                if(iscycle(v,adj,prerequisites,vis,recpath)){
                    return true;
                }
            }
            else if(recpath[v]){
                return true;
            }
            
        }
        recpath[src] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto& p:prerequisites){
            adj[p[0]].push_back(p[1]);
        }  
        vector<bool> vis(numCourses, false);
        vector<bool> recpath(numCourses, false);

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(iscycle(i,adj,prerequisites,vis,recpath)){
                    return false;
                }
            }
        }

        return true;
    }
};