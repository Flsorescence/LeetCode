/**106 Construct Binary Tree from Inorder and Postorder Traversal 
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * Note：You may assume that duplicates do not exist in the tree.
 * example：
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
 * Return the following binary tree:
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0) return NULL;
        return build(inorder, 0, inorder.size(), postorder, 0, postorder.size());
    }
    
    TreeNode* build(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe) {
        if(is >= ie || ps >= pe) return NULL;
        
        TreeNode* node = new TreeNode(postorder[pe-1]);
        auto f = find(inorder.begin()+is, inorder.begin()+ie, postorder[pe-1]);
        int dis = f - inorder.begin() - is;
        node->left = build(inorder, is, is+dis, postorder, ps, ps+dis);
        node->right = build(inorder, is+dis+1, ie, postorder, ps+dis, pe-1);
        
        return node;
    }
};