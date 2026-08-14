class Solution {
public:
    long long maxArea(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxK = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        int a = dp[i-1][j];
                        int b = dp[i][j-1];
                        int c = dp[i-1][j-1];
                        int mn = min(a, min(b, c));
                        dp[i][j] = mn + 1;
                    }
                    maxK = max(maxK, dp[i][j]);
                }
            }
        }
        for (int k = maxK; k >= 1; k--) {
            int minR = INT_MAX, maxR = INT_MIN;
            int minC = INT_MAX, maxC = INT_MIN;
            int count = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (dp[i][j] >= k) {
                        count++;
                        minR = min(minR, i);
                        maxR = max(maxR, i);
                        minC = min(minC, j);
                        maxC = max(maxC, j);
                    }
                }
            }

            if (count >= 2) {
                bool rowGapOk = (maxR - minR) >= k;
                bool colGapOk = (maxC - minC) >= k;
                if (rowGapOk || colGapOk) {
                    return (long long)k * k;
                }
            }
        }
        return 0;
    }
};