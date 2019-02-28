/**124 Binary Tree Maximum Path Sum
 * Given a non-empty binary tree, find the maximum path sum.
 * For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.
 * Example 1:
 * Input: [1,2,3]
 *     1
 *    / \
 *   2   3
 * Output: 6
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
    int maxPathSum(TreeNode* root) {
        if(root == 0) return 0;
        int sum = root->val;
        help(root, sum);
        return sum;
    }
    
    int help(TreeNode* root, int &sum){
        if(root == 0) return 0;
        int left = help(root->left, sum);
        int right = help(root->right, sum);
        int m = max(max(left, right), 0) + root->val;
        sum = max(max(sum, m), left + right + root->val);
        return m;
    }
};