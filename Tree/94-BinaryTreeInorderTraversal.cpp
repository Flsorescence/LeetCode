/**94 Binary Tree Inorder Traversal
 * Given a binary tree, return the inorder traversal of its nodes' values.
 */
 
// 二叉树中序遍历
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
    vector<int> inorder(TreeNode* node, vector<int> res){
        if(node->left != NULL)
            res = inorder(node->left, res);
        res.push_back(node->val);
        if(node ->right != NULL)
            res = inorder(node->right, res);
        return res;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        res = inorder(root, res);
        return res;
    }
};