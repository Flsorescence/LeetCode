/**116 Populating Next Right Pointers in Each Node
 * You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:
 * struct Node {
 *   int val;
 *   Node *left;
 *   Node *right;
 *   Node *next;
 * }
 * Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
 * Initially, all next pointers are set to NULL.
 */
 

// 层次遍历记录每一层节点之间的左右关系，然后标记next节点 
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        queue<Node*> p, q;
        root->next == NULL;
        p.push(root);
        while(p.size() != 0 || q.size() != 0){
            if(p.size() != 0){
                while(p.size() != 0){
                    Node* node = p.front();
                    p.pop();
                    if(p.size() != 0) node->next = p.front();
                    
                    if(node->left != NULL) q.push(node->left);
                    if(node->right != NULL) q.push(node->right);
                }
            }else{
                while(q.size() != 0){
                    Node* node = q.front();
                    q.pop();
                    if(q.size() != 0) node->next = q.front();
                    
                    if(node->left != NULL) p.push(node->left);
                    if(node->right != NULL) p.push(node->right);
                }
            }
        }
        return root;
    }
};