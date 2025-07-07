class Solution {
    int f(int day, int last, vector<vector<int>> &dp, vector<vector<int>> &arr)
    {  
        if (day == 0) {
            int maxi = 0;
            for (int i = 0; i < 3; i++) {
                if (i != last)
                    maxi = max(maxi, arr[0][i]);
            }
            return maxi;
        }

        if (dp[day][last] != -1)
            return dp[day][last];

        int maxx = 0;
        for (int i = 0; i < 3; i++) {
            if (i != last) {
                int points = arr[day][i] + f(day - 1, i, dp, arr);
                maxx = max(maxx, points);
            }
        }
        return dp[day][last] = maxx;
    }

public:
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();  
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return f(n - 1, 3, dp, arr);  
    }
};

