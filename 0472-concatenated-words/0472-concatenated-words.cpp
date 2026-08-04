class Solution {
public:
    bool isConcat(string word,
                  unordered_set<string>& st,
                  unordered_map<string, bool>& dp) {

        if(dp.find(word) != dp.end()) {
            return dp[word];
        }

        int l = word.length();

        for(int i = 0; i < l - 1; i++) {

            string prefix = word.substr(0, i + 1);
            string suffix = word.substr(i + 1);

            if(st.find(prefix) != st.end() &&
               (st.find(suffix) != st.end() ||
                isConcat(suffix, st, dp))) {

                return dp[word] = true;
            }
        }

        return dp[word] = false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {

        unordered_set<string> st(words.begin(), words.end());
        unordered_map<string, bool> dp;

        vector<string> result;

        for(string& word : words) {
            if(isConcat(word, st, dp)) {
                result.push_back(word);
            }
        }

        return result;
    }
};