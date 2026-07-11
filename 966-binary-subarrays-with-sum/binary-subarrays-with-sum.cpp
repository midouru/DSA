class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> ps(n);
        unordered_map<int,int> mp;
        int ans = 0;
        ps[0] = nums[0];
        for(int i = 1;i<n;i++){
            ps[i] = ps[i-1] + nums[i];
        }
        for(int j = 0;j<n;j++){
            if(ps[j] == goal){
                ans++;
            }
            int val = ps[j] - goal;
            if(mp.find(val) != mp.end()){
                ans += mp[val];
            }
            mp[ps[j]]++;
        }
        return ans;
    }
};