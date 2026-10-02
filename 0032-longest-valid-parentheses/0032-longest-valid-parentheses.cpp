class Solution {
public:
    int longestValidParentheses(string s) {
        int open = 1, close = 0, longest = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            (s[i] == '(') ? ++open : ++close;

            if (close > open)
                open = close = 0;

            if (open == close)
                longest = max(longest, 2 * close);
        }

        open = close = 0;
        for (int i = n - 1; i >= 0; i--) {
            (s[i] == '(') ? ++open : ++close;

            if (open > close)
                open = close = 0;
            if (open == close)
                longest = max(longest, 2 * open);
        }
        return longest;
    }
};