class Solution {
public:
    int f(int n){
        int sum=0;
        while(n!=0){
            int d = n%10;
            sum+= d*d;
            n = n/10;

        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> s;
        while(n!=1){
            if(s.count(n)){
                return false;
            }
            else{
                s.insert(n);
                n = f(n);
            }
        }
        return true;
        
    }
};