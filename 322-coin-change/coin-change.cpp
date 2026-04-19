class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,1e9);
        dp[0] = 0;
        for(int j = 1;j<=amount;j++){
            for(int coin : coins){
                if(j-coin >= 0){
                    dp[j] = min(dp[j],1+dp[j-coin]);
                }
            }
        }
        return dp[amount] == 1e9 ? -1 : dp[amount];
    }
};