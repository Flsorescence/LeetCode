/**113 Path Sum II
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 * Note: A leaf is a node with no children.
 * Example:
 * Given the below binary tree and sum = 22,
 *       5
 *      / \
 *     4   8
 *    /   / \
 *   11  13  4
 *  /  \    / \
 * 7    2  5   1
 * Return:
 * [
 *    [5,4,11,2],
 *    [5,8,4,5]
 * ]
 */
 
//在112题的基础上维护一个保存路径的列表 
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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == NULL) return res;
        vector<int> p;
        path(p, root, sum);
        return res;
    }
    
    void path(vector<int>& p, TreeNode* root, int sum){
        p.push_back(root->val);
        sum = sum - root->val;
        if(root->left == NULL && root->right == NULL){
            if(sum == 0)
                res.push_back(p);
            return;
        }
        
        if(root->left != NULL) {
            path(p, root->left, sum);
            p.pop_back();
        }
        if(root->right != NULL) {
            path(p, root->right, sum);
            p.pop_back();
        }
    }
};