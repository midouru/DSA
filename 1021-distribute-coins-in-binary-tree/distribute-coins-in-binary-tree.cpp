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
    int moves;
    int helper(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int leftval = helper(root->left);
        int rightval = helper(root->right);
        
        moves+= abs(leftval) + abs(rightval);
        
        return leftval+(rightval)+root->val-1;
    }
    int distributeCoins(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        helper(root);
        return moves;

    }
};