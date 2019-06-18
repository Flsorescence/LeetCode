/**108 Convert Sorted Array to Binary Search Tree
 * Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 * For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 * Example:
 * Given the sorted array: [-10,-3,0,5,9],
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
 *       0
 *      / \
 *    -3   9
 *    /   /
 *  -10  5
 */

//BST左右子树高度差不超过1，左节点的值小于根节点，右节点的值大于根节点，输入是一个有序的数组，所以可以采用二分查找的思想，不断对半分，将mid作为当前的根节点，左半部分都比它小，右半部分都比它大
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return GenerateTree(nums, 0, nums.size()-1);
    }
    
    TreeNode* GenerateTree(vector<int>& nums, int start, int end) {
        if(start > end)
            return NULL;
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = GenerateTree(nums, start, mid-1);
        root->right = GenerateTree(nums, mid+1, end);
        return root;
    }
};