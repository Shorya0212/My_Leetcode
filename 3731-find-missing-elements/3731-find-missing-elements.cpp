class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> st;
        int maxi =INT_MIN;
        int mini = INT_MAX;
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            maxi = max(maxi,nums[i]);
            mini =min(mini,nums[i]);
        }
        for(auto x:nums){
            st.insert(x);
        }
        for(int v=mini;v<maxi;v++){
            if(!st.count(v)){
                ans.push_back(v);
            }

        }
        return ans;
    }
};