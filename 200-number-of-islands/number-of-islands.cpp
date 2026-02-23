class Solution {
public:
    void dfshelper(int i, int j, vector<vector<bool>>& visited, vector<vector<char>>& grid, int m, int n){
        if(i<0 || j<0 || i>=m || j>=n || visited[i][j] == true || grid[i][j]=='0'){
            return;
        }
        visited[i][j] = true;
        dfshelper(i-1,j,visited,grid,m,n);
        dfshelper(i,j-1,visited,grid,m,n);
        dfshelper(i+1,j,visited,grid,m,n);
        dfshelper(i,j+1,visited,grid,m,n);
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n,false));

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j] == '1'&&!visited[i][j]){
                    dfshelper(i,j,visited,grid,m,n);
                    islands++;
                }
            }
        }
        return islands;
    }
};
