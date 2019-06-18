/**107 Binary Tree Level Order Traversal II
 * Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its bottom-up level order traversal as:
 * [
 *   [15,7],
 *   [9,20],
 *   [3]
 * ]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        queue<TreeNode*> p, q;
        q.push(root);
        while(p.size() != 0 || q.size() != 0){
            vector<int> level;
            if(q.size() != 0){
                while(q.size() != 0){
                    TreeNode* node = q.front();
                    q.pop();
                    level.push_back(node->val);
                    if(node->left != NULL) p.push(node->left);
                    if(node->right != NULL) p.push(node->right);
                }
            }else{
                while(p.size() != 0){
                    TreeNode* node = p.front();
                    p.pop();
                    level.push_back(node->val);
                    if(node->left != NULL) q.push(node->left);
                    if(node->right != NULL) q.push(node->right);
                }
            }
            res.push_back(level);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};