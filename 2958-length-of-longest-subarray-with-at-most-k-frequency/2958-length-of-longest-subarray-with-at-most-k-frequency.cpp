class Solution {
public:
    int maxSubarrayLength(std::vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int bad = 0;
        std::unordered_map<int, int> freq;
        for (int right = 0; right < n; right++) {
            int c = nums[right];
            int cnt = ++freq[c];
            if (cnt == k + 1) bad++;
            if (bad == 0) continue;
            int d = nums[left];
            int dc = --freq[d];
            if (dc == k) bad--;
            left++;
        }
        return n - left;
    }
};