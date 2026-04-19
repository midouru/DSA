class Solution {
public:
    int getcoincombination(vector<int>& coins, int amount, int i, vector<vector<int>>& dp){
        if(amount == 0){
            return 0;
        }

        if(i>=coins.size() || amount<0){
            return 1e9;
        }

        if(dp[i][amount]!= -1){
            return dp[i][amount];
        }
        
        int take = 1+getcoincombination(coins,amount-coins[i],i,dp);
        
        int nottake = getcoincombination(coins,amount,i+1,dp);

        return dp[i][amount] = min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1,-1));
        int ans = getcoincombination(coins,amount,0,dp);
        return (ans >= 1e9) ?  -1 : ans;
    }
};