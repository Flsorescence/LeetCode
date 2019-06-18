/**103 Binary Tree Zigzag Level Order Traversal
 * Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its zigzag level order traversal as:
 * [
 *   [3],
 *   [20,9],
 *   [15,7]
 * ]
 */
 
//在102的基础上，记录每一层的层数，如果层数是偶数，则把结果翻转 
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;
        queue<TreeNode*> p, q;
        
        q.push(root);
        int count = 1;
        while(q.size() != 0 || p.size() != 0){
            vector<int> level;
            if(q.size() != 0){
                while(q.size() != 0){
                    TreeNode* node = q.front();
                    q.pop();
                    level.push_back(node->val);
                    if(node->left != NULL) p.push(node->left);
                    if(node->right != NULL) p.push(node->right);
                }
            }
            else{
                while(p.size() != 0){
                    TreeNode* node = p.front();
                    p.pop();
                    level.push_back(node->val);
                    if(node->left != NULL) q.push(node->left);
                    if(node->right != NULL) q.push(node->right);
                }
            }
            
            if(count % 2 == 0){
                reverse(level.begin(), level.end());
            }
            count ++;
            res.push_back(level);
        }
        return res;
    }
};