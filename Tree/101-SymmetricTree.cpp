/**101 Symmetric Tree
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 * For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
 *     1
 *    / \
 *   2   2
 *  / \ / \
 * 3  4 4  3
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
    bool isSymmetric(TreeNode* root) {
        if(root == 0) return true;
        return symmetric(root, root);
    }
    
    bool symmetric(TreeNode *p, TreeNode *q){
        if(p == 0 && q == 0) return true;
        if(p == 0 || q == 0) return false;
        if(p->val != q->val) return false;
        else{
            return symmetric(p->left, q->right) && symmetric(p->right, q->left);
        }
    }
};