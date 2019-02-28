/**110 Balance Binary Tree
 * Given a binary tree, determine if it is height-balanced.
 * For this problem, a height-balanced binary tree is defined as:
 * a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 *Example 1:
 *Given the following tree [3,9,20,null,null,15,7]:
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * Return true.
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
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return balance(root, height);
    }
    
    bool balance(TreeNode* root, int &height){
        if(root == 0){
            height = 0;
            return true;
        }
        int h1 = height, h2 = height;
        if(!balance(root->left, h1)) return false;
        if(!balance(root->right, h2)) return false;
        
        int dis = h1 - h2;
        height = max(h1, h2) + 1;
        if(dis <= 1 && dis >= -1) return true;
        else return false;
    }
};