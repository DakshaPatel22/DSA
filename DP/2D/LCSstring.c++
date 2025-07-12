class Solution {
public:
    string longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        int len = dp[n1][n2];
        string ans(len, '$');
        int i = n1, j = n2, ind = len - 1;

        while (i > 0 && j > 0) {
            if (text1[i - 1] == text2[j - 1]) {
                ans[ind] = text1[i - 1];
                ind--;
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }

        return ans;
    }
};
