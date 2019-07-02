/**144 Binary Tree Preorder Traversal
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * Example:
 * Input: [1,null,2,3]
 *    1
 *     \
 *      2
 *     /
 *    3
 * Output: [1,2,3]
 */

// 递归解法：
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
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL) return res;
        preorder(root);
        return res;
    }
    
    void preorder(TreeNode* root){
        if(root != NULL) res.push_back(root->val);
        if(root->left != NULL) preorder(root->left);
        if(root->right != NULL) preorder(root->right);
    }
};

// 迭代解法：
