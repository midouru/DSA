class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(mat[i][j] == 0 && !vis[i][j]){
                    q.push({{i,j},0});
                    vis[i][j] = true;
                }
            }
        }

        while(!q.empty()){
            int i = q.front().first.first;
            int j = q.front().first.second;
            int d = q.front().second;
            q.pop();

            if(i+1<m && !vis[i+1][j] && mat[i+1][j] == 1){
                
                q.push({{i+1,j},d+1});
                mat[i+1][j] = d+1;
                vis[i+1][j] = true;
            }

            if(j+1<n && !vis[i][j+1] && mat[i][j+1] == 1){
                
                q.push({{i,j+1},d+1});
                mat[i][j+1] = d+1;
                vis[i][j+1] = true;
            }

            if(j-1>=0 && !vis[i][j-1] && mat[i][j-1] == 1){
            
                q.push({{i,j-1},d+1});
                mat[i][j-1] = d+1;
                vis[i][j-1] = true;
            }

            if(i-1>=0 && !vis[i-1][j] && mat[i-1][j] == 1){
                
                q.push({{i-1,j},d+1});
                mat[i-1][j] = d+1;
                vis[i-1][j] = true;
            }

        }
        return mat;
    }
};