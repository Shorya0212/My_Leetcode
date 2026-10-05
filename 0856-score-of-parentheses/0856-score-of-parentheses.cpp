class Solution {
public:
    int scoreOfParentheses(string s) {
        int n =s.size();
        int count=0;
        int depth =0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                ++count;
            }
            else{
                --count;
                if(s[i-1]=='('){
                    depth+=1<<count;
                }
            }
        }
        return depth;
        
    }
};