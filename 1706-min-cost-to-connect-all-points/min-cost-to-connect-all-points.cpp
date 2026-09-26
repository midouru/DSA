class Solution {
public:
    int manhat(int p1, int p2, vector<vector<int>>& points){
        return abs(points[p1][0] - points[p2][0]) + abs(points[p1][1] - points[p2][1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<bool> mstSet(n, false);
        int mstCost = 0;
        pq.push({0,0});
        while(!pq.empty()){
            int wt = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if(mstSet[u]) continue;

            mstSet[u] = true;
            mstCost += wt;

            for(int i = 0;i<n;i++){
                if(!mstSet[i]){
                    int ewt = manhat(u, i, points);
                    pq.push({ewt, i});
                }
            }
        }

        return mstCost;
    }
};