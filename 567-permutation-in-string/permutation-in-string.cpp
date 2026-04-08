class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};
        for(char c : s1){
            freq[c - 'a']++;
        }

        int window[26] = {0};
        int k = s1.length();
        for(int i = 0;i<s2.length();i++){
            window[s2[i] - 'a']++;
            if(i>=k){
                window[s2[i-k] - 'a']--;
            }
            if(memcmp(freq,window,sizeof(freq)) == 0){
                return true;
            }
        }
        return false;
    }
};