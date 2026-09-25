class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> rank(n,1);
        vector<int> par(n);
        for(int i = 0;i<n;i++){
            par[i] = i;
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(isConnected[i][j] == 1) unite(i,j,par,rank);
            }
        }

        set<int> s = {};
        for(int p : par){
            s.insert(find(p,par));
        }

        return s.size();
    }
    int find(int i, vector<int>& par){
        if(par[i] == i) return i;

        return par[i] = find(par[i], par);
    }

    void unite(int i, int j, vector<int>& par, vector<int>& rank){
        int par_i = find(i,par);
        int par_j = find(j,par);
        
        if(par_i == par_j) return;
        if(rank[par_j] > rank[par_i]){
            par[par_i] = par_j;
        }
        else{
            par[par_j] = par_i;
            rank[par_i]++;
        }
    }
};