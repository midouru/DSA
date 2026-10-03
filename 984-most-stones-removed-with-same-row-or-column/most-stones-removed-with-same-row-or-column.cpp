class Solution {
public:

    int findpar(int x, vector<int>& par){
        if(par[x] == x) return x;

        return par[x] = findpar(par[x], par);
    }
    void unite(int i, int j, vector<int>& par, vector<int>& rank){
        int pari = findpar(i, par);
        int parj = findpar(j, par);

        if(pari == parj) return;

        if(rank[parj] > rank[pari]){
            par[pari] = parj;
        }
        else{
            par[parj] = pari;
            rank[pari]++;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        vector<int> par(n);
        vector<int> rank(n, 1);

        for(int i = 0;i<n;i++){
            par[i] = i;
        }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    unite(i,j,par,rank);
                }
            }
        }

        int components = 0;

        for(int i = 0;i<n;i++){
            if(findpar(i, par) == i){
                components++;
            }
        }

        return n - components;

    }
};