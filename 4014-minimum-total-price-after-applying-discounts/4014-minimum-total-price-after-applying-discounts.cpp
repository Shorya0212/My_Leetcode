class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int n = prices.size();
        int m = discounts.size();
        sort(prices.begin(),prices.end());
        sort(discounts.begin(),discounts.end());
        double sum =0;
        for(int i=0;i<n;i++){
            sum +=prices[i];
        }
        int s =min(prices.size(),discounts.size());
        for(int i=0;i<s;i++){
            sum-= (double)prices[n-i-1] *(discounts[m-i-1])/100;
        }
        return sum;
    }
};