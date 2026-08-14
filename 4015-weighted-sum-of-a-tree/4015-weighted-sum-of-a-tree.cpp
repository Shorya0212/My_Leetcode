class Solution {
public:
    vector<vector<int>> child;
    vector<int> depth;
    int height =0;
    void dfs(int node,int d){
        depth[node] =d;
        height =max(height,d);
        for(int childnode:child[node]){
            dfs(childnode,d+1);
        }
    }
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n =parent.size();
        child.resize(n);
        depth.resize(n);
        for(int i=1;i<n;i++){
            child[parent[i]].push_back(i);
        }
        dfs(0,1);
        long long ans=0;
        for(int i=0;i<n;i++){
            ans +=1LL *nums[i] *(height -depth[i]+1);
        }
        return ans;

    }
};