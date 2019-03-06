/**114 Flatten Binary Tree to Linked List
 * Given a binary tree, flatten it to a linked list in-place.
 * For example, given the following tree:
 *     1
 *    / \
 *   2   5
 *  / \   \
 * 3   4   6
 * The flattened tree should look like:
 * 1
 *  \
 *   2
 *    \
 *     3
 *      \
 *       4
 *        \
 *         5
 *          \
 *           6
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
    void flatten(TreeNode* root) {
        while(root != 0){
            if(root->left != 0){
                TreeNode* tmp = root->left;
                while(tmp->right != 0)
                    tmp = tmp->right;
                tmp->right = root->right;
                root->right = root->left;
                root->left = 0;
            }
            root = root->right;
        }
    }
};