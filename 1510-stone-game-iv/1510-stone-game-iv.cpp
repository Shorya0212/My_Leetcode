class Solution {
public:
    bool solve(int i,vector<int> &DP) {
        if (i == 0) {
            return DP[i] = false;
        }
        if (DP[i] != -1) {
            return DP[i];
        }
        for (int j = 1; j * j <= i; j++) {
            if (!solve(i - j * j,DP)) {
                return DP[i] = true;
            }
        }
        return DP[i] = false;
    }

    bool winnerSquareGame(int n) {
        vector<int> DP(n + 1, -1);
        return solve(n,DP);
    }
};