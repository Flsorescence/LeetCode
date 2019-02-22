/**105 Construct Binary Tree from Preorder and Inorder Traversal 
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return NULL;
        
        return build(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie) {
        if(ps >= pe || is >= ie) return NULL;
        TreeNode* node = new TreeNode(preorder[ps]);
        auto f = find(inorder.begin()+is, inorder.begin()+ie, preorder[ps]);
        int dis = f - inorder.begin() - is;
        node->left = build(preorder, inorder, ps+1, ps+1+dis, is, is+dis);
        node->right = build(preorder, inorder, ps+1+dis, pe, is+dis+1, ie);
        return node;
    }
};