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
    void helper(TreeNode* root, int targetSum, vector<vector<int>>& ans, vector<int>& result){
        bool haspath = false;
        if(!root) return;
        result.push_back(root->val);
        if(!root->left && !root->right){
            if(root->val == targetSum){
                ans.push_back(result);
            }
            result.pop_back();   // backtrack
            return;
        }

        helper(root->left, targetSum-root->val, ans, result);
        helper(root->right, targetSum-root->val, ans, result);
        result.pop_back(); 
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> result;
        helper(root,targetSum,ans,result);
        return ans;
    }
};