class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<int,int> mp;
        int res =0;
        int i=0,j=0,n=s.size();
        while(j<n){
            mp[s[j]]++;
            while(mp[s[j]]>2){
                mp[s[i]]--;
                i++;
            }
            res =max(res,j-i+1);
            j++;
        }
        return res;
    }
};