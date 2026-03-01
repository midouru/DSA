class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int orgcolor, int newcolor){
        if(i<0 || j<0 || i>=image.size() || j>=image[0].size() || image[i][j] != orgcolor || image[i][j] == newcolor){
            return;
        }

        image[i][j] = newcolor;
        dfs(image,i-1,j,orgcolor,newcolor);
        dfs(image,i,j+1,orgcolor,newcolor);
        dfs(image,i+1,j,orgcolor,newcolor);
        dfs(image,i,j-1,orgcolor,newcolor);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        dfs(image,sr,sc,image[sr][sc],color);
        return image;
    }
};