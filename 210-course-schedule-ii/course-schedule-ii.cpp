class Solution {
public:
    bool iscycle(int src,vector<vector<int>>& adj,vector<bool>& vis, vector<bool>& recpath,stack<int>& s){
        vis[src] = true;
        recpath[src] = true;

        for(int v : adj[src]){

            if(!vis[v]){
                if(iscycle(v,adj,vis,recpath,s)){
                    return true;
                }
            }
            else if(recpath[v]){
                return true;
            }
            
        }
        recpath[src] = false;
        s.push(src);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        // Build graph
        for(auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<bool> vis(numCourses, false);
        vector<bool> recpath(numCourses, false);
        stack<int> s;
        vector<int> ans;
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(iscycle(i,adj,vis,recpath,s)){
                    return {};
                }
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};