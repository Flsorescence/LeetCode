/**98 Validate Binary Search Tree
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * Assume a BST is defined as follows:
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 */
 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return F(root, INT64_MIN, INT64_MAX);
    }
    
    bool F(TreeNode* root, long long lower, long long upper){
        if(root == 0) return true;
        if(root->val <= lower || root->val >= upper) return false;
        return F(root->left, lower, root->val) && F(root->right, root->val, upper);
    }
};