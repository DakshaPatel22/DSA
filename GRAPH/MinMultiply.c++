class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start == end) return 0;
        
        vector<int> dis(100000, 1e9);
        dis[start] = 0;
        queue<pair<int, int>> q;
        q.push({start, 0});
        int MOD = 100000;

        while(!q.empty()) {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();

            for(auto it : arr) {
                int num = (it * node) % MOD;
                if(steps + 1 < dis[num]) {
                    dis[num] = steps + 1;
                    if(num == end) return steps + 1;
                    q.push({num, steps + 1});
                }
            }
        }
        return -1;
    }
};
