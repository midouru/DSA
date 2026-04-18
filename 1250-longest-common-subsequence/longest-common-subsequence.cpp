class Solution {
public:
    int solve(int i, int j, string &text1, string &text2, vector<vector<int>> &lcs){

        if(i<0 || j<0){
            return 0;
        }
        
        if(lcs[i][j] != -1){
            return lcs[i][j];
        }

        if(text1[i] == text2[j]){
            return lcs[i][j] = 1 + solve(i-1,j-1,text1,text2,lcs);
        }
        else{
            return lcs[i][j] = max(solve(i-1,j,text1,text2,lcs),solve(i,j-1,text1,text2,lcs));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> lcs(m, vector<int>(n,-1));

        return solve(m - 1, n - 1, text1, text2, lcs);
    }
};