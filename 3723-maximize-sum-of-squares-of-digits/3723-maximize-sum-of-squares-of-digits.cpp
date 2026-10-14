class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
      if(sum>9*num)return "";
        int sumcurr=sum;
        string ans="";
        for(int i=0;i<num;i++){
            int value=min(9,sumcurr);
            ans+=char('0'+value);
            sumcurr-=value;
        }
        return ans;
    }
};