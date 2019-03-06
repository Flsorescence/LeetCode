/**109 Convert Sorted List to Binary Search Tree
 * Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 * For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
 * Example:
 * Given the sorted linked list: [-10,-3,0,5,9],
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:
 *       0
 *      / \
 *    -3   9
 *    /   /
 *  -10  5
 */
 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* tmp = head;
        vector<int> num;
        while(tmp != NULL){
            num.push_back(tmp->val);
            tmp = tmp->next;
        }
        TreeNode* root = buildTree(num, 0, num.size() - 1);
        return root;
    }
    
    TreeNode* buildTree(vector<int> num, int start, int end){
        int mid = (start + end) % 2 == 0? (start + end) / 2: (start + end) / 2 + 1;
        TreeNode* root = new TreeNode(num[mid]);
        if(mid != start) root->left = buildTree(num, start, mid - 1);
        if(mid != end) root->right = buildTree(num, mid + 1, end);
        return root;
    }
};