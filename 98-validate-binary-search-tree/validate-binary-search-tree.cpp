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
    bool check(TreeNode* root, TreeNode* minVal, TreeNode* maxVal){
        if(root == NULL){
            return true;
        }
        if(minVal!= NULL && root->val <= minVal->val){
            return false;
        }
        if(maxVal!= NULL && root->val >= maxVal->val){
            return false;
        }
        return check(root->left,minVal,root) && check(root->right,root,maxVal);
    }
    bool isValidBST(TreeNode* root) {
        return check(root, NULL, NULL);
    }
};