class Solution {
public:
    bool iscycle(int src, vector<vector<int>>& prerequisites, vector<bool>& vis, vector<bool>& recpath){
        vis[src] = true;
        recpath[src] = true;

        for(int i = 0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            if(u == src){
                if(!vis[v]){
                    if(iscycle(v,prerequisites,vis,recpath)){
                        return true;
                    }
                }
                else if(recpath[v]){
                    return true;
                }
            }
        }
        recpath[src] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> vis(numCourses, false);
        vector<bool> recpath(numCourses, false);

        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(iscycle(i,prerequisites,vis,recpath)){
                    return false;
                }
            }
        }

        return true;
    }
};