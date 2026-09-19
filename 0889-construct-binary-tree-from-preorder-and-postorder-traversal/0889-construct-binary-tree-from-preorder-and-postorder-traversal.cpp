/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution { 
public: 
    TreeNode * helper(vector<int> &preorder,vector<int> &postorder,unordered_map<int,int> &mp,int &preidx,int left,int right){ 
        if(left>right || preidx>=preorder.size()) return NULL; 
        TreeNode* root =new TreeNode(preorder[preidx++]); 
        if(left==right) return root;
        int idx =mp[preorder[preidx]]; 
        root->left = helper(preorder,postorder,mp,preidx,left,idx); 
        root->right = helper(preorder,postorder,mp,preidx,idx+1,right-1); 
        return root; 
    } 
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) { 
        unordered_map<int,int> mp; 
        for(int i=0;i<postorder.size();i++){ 
            mp[postorder[i]] =i; 
        } 
        int preidx =0; 
        return helper(preorder,postorder,mp,preidx,0,postorder.size()-1); 
    } 
};