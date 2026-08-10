class Solution {
public:
    unordered_set<string> st;
    bool solve(int idx,string &s,vector<int> &dp){
        if(idx>=s.length()){
            return true;
        }
        if(dp[idx]!=-1) return dp[idx];
        if(st.find(s)!=st.end()) return true;
        for(int l=1;idx+l<=s.length();l++){
            string temp =s.substr(idx,l);
            if(st.find(temp)!=st.end() && solve(idx+l,s,dp)){
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
     bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, 0);
        dp[0] = true;
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        for(int i=1; i<=s.size(); i++){
            for(int j=0; j<i; j++){
                if(dp[j] && set.count(s.substr(j, i-j))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};    