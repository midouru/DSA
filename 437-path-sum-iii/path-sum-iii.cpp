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
    long long helper(TreeNode* root, long long currSum,int targetSum,unordered_map<long long, long long>& mp){
        if(!root) return 0;
        currSum += root->val;
        long long count = 0;
        if(mp.find(currSum - targetSum)!=mp.end()){
            count += mp[currSum - targetSum];
        }
        mp[currSum]++;
        count += helper(root->left,currSum,targetSum,mp);
        count += helper(root->right,currSum,targetSum,mp);
        mp[currSum]--;
        return count;
    }
    int pathSum(TreeNode* root, int targetSum) {
       if(!root) return 0;
       unordered_map<long long,long long> mp;
       mp[0] = 1;
       return helper(root,0,targetSum,mp);
     
    }
};