class Solution {
    public:
        int findNumbers(vector<int>& nums) {
            int count = 0;
            for(int i : nums) {
                if ((i >= 10 && i < 100) || (i >= 1000 && i < 10000) || i == 100000)
                    ++count;
            }
            return count;
        }
    };    