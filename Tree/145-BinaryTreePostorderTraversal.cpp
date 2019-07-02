/**145 Binary Tree Postorder Traversal
 * Given a binary tree, return the postorder traversal of its nodes' values.
 * Example:
 * Input: [1,null,2,3]
 *    1
 *     \
 *      2
 *     /
 *    3
 * Output: [3,2,1]
 */
 
// 递归解法
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
    
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return res;
        postorder(root);
        return res;
    }
    
    void postorder(TreeNode* root){
        if(root->left != NULL) postorder(root->left);
        if(root->right != NULL) postorder(root->right);
        res.push_back(root->val);
    }
};