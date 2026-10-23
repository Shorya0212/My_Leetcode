class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set(nums.begin(), nums.end()); 
        int longestConsecutiveSequence = 0;
        
   
        for(int num : num_set){
            if(num_set.find(num - 1) == num_set.end()){
                int currentNumber = num;
                int currentConsecutiveSequence = 1;
                
                while(num_set.find(currentNumber + 1) != num_set.end()){
                    currentNumber++;
                    currentConsecutiveSequence++;
                }
                longestConsecutiveSequence = max(longestConsecutiveSequence, currentConsecutiveSequence);
            }
        }
        return longestConsecutiveSequence;
    }
};