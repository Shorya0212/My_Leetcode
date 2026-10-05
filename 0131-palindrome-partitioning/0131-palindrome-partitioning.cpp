class Solution {
public:
    bool ispalin(string s){
        string s2 = s;
        reverse(s2.begin(),s2.end());
        return s==s2;
    }
    void getAllParts(vector<vector<string>> &ans,vector<string> &partitions,string s){
        if(s.size()==0){
            ans.push_back(partitions);
            return;
        }
        for(int i=0 ;i<s.size();i++){
            string part = s.substr(0,i+1);
            if(ispalin(part)){
                partitions.push_back(part);
                getAllParts(ans,partitions,s.substr(i+1));
                partitions.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;
        getAllParts(ans,partitions,s);
        return ans;
    }
};