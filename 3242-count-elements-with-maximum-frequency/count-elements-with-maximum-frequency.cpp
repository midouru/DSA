class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int x:nums){
            freq[x]++;
        }

        int maxfreq = 0;
        for(auto& p:freq){
            maxfreq = max(maxfreq,p.second);
        }

        int countmax = 0;
        for(auto& p:freq){
            if(p.second == maxfreq){
                countmax++;
            }
        }

        return countmax*maxfreq;
    }
};