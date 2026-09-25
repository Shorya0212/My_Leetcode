class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        if(s[0]=='0') return 0;

        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;

        for(int i=2;i<=n;i++){
            int onedigit=s[i-1]-'0';
            int twodigit=(s[i-2]-'0')*10+onedigit;

            if(onedigit>=1 && onedigit<=9)
                dp[i]+=dp[i-1];
            if(twodigit>=10 && twodigit<=26)
                dp[i]+=dp[i-2];
        }
        return dp[n];
    }
};