class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n =nums.size();
        bool allzero =true;
        int resultxor =0;
        for(int &x:nums){
            resultxor =(resultxor^x);
            if(x!=0){
                allzero = false;
            }
        }
        if(allzero){
            return 0;
        }
        return (resultxor==0)?n-1:n;
    }
};