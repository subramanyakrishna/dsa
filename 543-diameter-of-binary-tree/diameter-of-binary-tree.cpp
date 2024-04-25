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
    int helper(TreeNode* root, int &max){
        if(root==NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        int left = helper(root->left,max) ;
        int right = helper(root->right,max) ;
        max = max > left+right ? max : left+right;
        return left > right ? left+1 : right+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int max = 0;
        helper(root,max);
        return max;
    }
};