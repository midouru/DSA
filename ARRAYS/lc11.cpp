#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxcontainer(vector<int>& height){
    int n = height.size();
    int lp = 0, rp = n-1;
    int maxarea = 0;
    while(lp < rp){
        int ht = min(height[lp], height[rp]);
        int wd = lp-rp;
        int currarea = ht * wd;
        maxarea = max(maxarea, currarea);
        if(height[lp] < height[rp]){
            lp++;
        }
        else{
            rp--;
        }
    }
    return maxarea;
}
