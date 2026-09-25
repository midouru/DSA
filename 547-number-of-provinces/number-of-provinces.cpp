class Solution {
public:
    void dfs(int i, vector<vector<int>>& isConnected, vector<bool>& visited){
        visited[i] = true;
        int n = isConnected.size();
        for(int j = 0;j<n;j++){
            if(isConnected[i][j] == 1 && !visited[j]){
                dfs(j,isConnected,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        int n = isConnected.size();
        vector<bool> visited(n, false);
        for(int i = 0;i<n;i++){
            if(!visited[i])
            {
                dfs(i,isConnected,visited);
                ans++;
            }
        }

        return ans;
    }
};