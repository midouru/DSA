class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       int n = nums.size();
       int ans = 0;
       for(int &x:nums){
        if(x == 0){
            x = -1;
        }
       }
       vector<int> ps(n);
       ps[0] = nums[0];
       unordered_map<int,int> mp;
       for(int i = 1;i<n;i++){
            ps[i] = ps[i-1] + nums[i];
       }
       for(int j=0;j<n;j++){
        if(ps[j] == 0) {
            ans = max(ans,j+1);
        }
        int val = ps[j];
        if(mp.find(val) != mp.end()){
            ans = max(ans, j - mp[val]);
        }
        else{
            mp[val] = j;
        }
       }
       return ans;
    }
};