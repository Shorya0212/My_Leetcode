class Solution {
public:
    int solve(int l,int r,vector<int> &curr,vector<vector<int>> &dp){
        if(l>=r) return 0;
        int score =0;
        if(dp[l][r]!=-1) return dp[l][r];
        for(int mid=l;mid<=r-1;mid++){
            int leftsum = curr[mid] -(l-1>=0?curr[l-1]:0);
            int rightsum =curr[r] -curr[mid];
            if(leftsum<rightsum){
                score =max(score,leftsum +solve(l,mid,curr,dp));
            }
            else if(leftsum>rightsum){
                score =max(score,rightsum +solve(mid+1,r,curr,dp));
            }
            else{
                score =max({score,leftsum +solve(l,mid,curr,dp),rightsum+solve(mid+1,r,curr,dp)});
            }
        }
        return dp[l][r] = score;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        vector<int> pref(n);
        pref[0] = stoneValue[0];

        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] + stoneValue[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int l = n - 1; l >= 0; l--) {

            for (int r = l + 1; r < n; r++) {

                for (int mid = l; mid < r; mid++) {

                    int leftSum = pref[mid] - (l > 0 ? pref[l - 1] : 0);
                    int rightSum = pref[r] - pref[mid];

                    if (leftSum < rightSum) {
                        dp[l][r] = max(
                            dp[l][r],
                            leftSum + dp[l][mid]
                        );
                    }
                    else if (leftSum > rightSum) {
                        dp[l][r] = max(
                            dp[l][r],
                            rightSum + dp[mid + 1][r]
                        );
                    }
                    else {
                        dp[l][r] = max({
                            dp[l][r],
                            leftSum + dp[l][mid],
                            rightSum + dp[mid + 1][r]
                        });
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};