class Solution {
public:
    long long func(vector<int>& piles, int k){
        long long totaltime = 0;
        int n = piles.size();
        for(int i = 0;i<n;i++){
            totaltime += (long long) ceil((double)piles[i]/k);
        }
        return totaltime;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int st = 1;
        int ed = *max_element(piles.begin(),piles.end());
        //int ans = INT_MAX;
        while(st<=ed){
            int mid = st + (ed-st)/2;
            if(func(piles,mid) <= h){
                ed = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        return st;
    }
};