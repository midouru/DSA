class Solution {
public:
    int helper(vector<int>& nums, int i, vector<int>& dp){
        int n = nums.size();
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int r = 0;
        int nr = 0;
        r = nums[i] + helper(nums,i+2,dp);
        nr = helper(nums,i+1,dp);
        return dp[i]=max(r,nr);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n,-1);
        return helper(nums, 0,dp);
    }
};