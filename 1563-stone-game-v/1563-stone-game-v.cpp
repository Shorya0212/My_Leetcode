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
        int n =stoneValue.size();
        vector<int> curr(n,0);
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        curr[0] =stoneValue[0];
        for(int i=1;i<n;i++){
            curr[i] =curr[i-1]+stoneValue[i];
        }
        return solve(0,n-1,curr,dp);
        
    }
};