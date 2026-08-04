class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, end = 0;
        for (int i = 0; i < n; i++) {
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l > end - start) {
                    start = l;
                    end = r;
                }
                l--;
                r++;
            }
            l = i;
            r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l > end - start) {
                    start = l;
                    end = r;
                }
                l--;
                r++;
            }
        }
        return s.substr(start, end - start + 1);
    }
};