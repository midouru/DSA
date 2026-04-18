class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<int> f(n+1);
        for(char c : text1){
            int pre = 0;
            for(int j = 0;j<n;j++){
                int temp = f[j+1];
                if(c == text2[j]){
                    f[j+1] = pre+1;
                }
                else{
                    f[j+1] = max(f[j],f[j+1]);
                }
                pre = temp;
            }
        }
        return f[n];
    }
};