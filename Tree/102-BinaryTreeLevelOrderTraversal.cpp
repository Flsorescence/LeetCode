/**102 Binary Tree Level Order Traversal
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its level order traversal as:
 * [
 *   [3],
 *   [9,20],
 *   [15,7]
 * ]
 */

// 交替使用队列，每个队列存储当前层的所有节点
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        queue<TreeNode*> p, q;
        q.push(root);
        while(q.size() != 0 || p.size() != 0){
            vector<int> level;
            if(q.size() == 0){
                while(p.size() != 0){
                    TreeNode* node = p.front();
                    p.pop();
                    level.push_back(node->val);
                    if(node->left != NULL)q.push(node->left);
                    if(node->right != NULL) q.push(node->right);
                }
            }else{
                while(q.size() != 0){
                    TreeNode* node = q.front();
                    q.pop();
                    level.push_back(node->val);
                    if(node->left != NULL) p.push(node->left);
                    if(node->right != NULL) p.push(node->right);
                }
            }
            res.push_back(level);
        }
        return res;
    }
};