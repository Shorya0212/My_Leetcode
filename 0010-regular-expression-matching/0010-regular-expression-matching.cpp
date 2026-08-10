class Solution {
public:
    bool solve(int i, int j, string &s, string &p, vector<vector<int>> &dp) {

        // Pattern khatam
        if (j == p.length()) {
            return i == s.length();
        }

        // Already calculated
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Current character match?
        bool first_char_matched = false;

        if (i < s.length() && (p[j] == s[i] || p[j] == '.')) {
            first_char_matched = true;
        }

        // Next character '*'
        if (j + 1 < p.length() && p[j + 1] == '*') {

            // '*' ko zero times use karo
            bool not_take = solve(i, j + 2, s, p, dp);

            // '*' ko current character ke liye use karo
            bool take = first_char_matched &&
                        solve(i + 1, j, s, p, dp);

            return dp[i][j] = not_take || take;
        }

        // Normal character / '.'
        return dp[i][j] =
            first_char_matched &&
            solve(i + 1, j + 1, s, p, dp);
    }

    bool isMatch(string s, string p) {

        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return solve(0, 0, s, p, dp);
    }
};