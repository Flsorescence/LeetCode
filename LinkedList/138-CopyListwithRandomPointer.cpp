/**138 Copy List with Random Pointer
 * A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 * Return a deep copy of the list.
 */

 
//在每个节点后面复制一个当前节点，复制节点的random指向当前节点random->next，将复制节点取出来
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == 0) return 0;
        for(Node *now = head; now; ){
            Node *tmp = new Node(now->val);
            tmp->next = now->next;
            now->next = tmp;
            now = tmp->next;
        }
        for(Node *now = head; now; now = now->next->next){
            now->next->random = now->random? now->random->next: 0;
        }
        
        Node *h = head->next, *t = h, *tail = head;
        for(;;){
            tail->next = t->next;
            tail = tail->next;
            if(tail == 0) break;
            t->next = tail->next;
            t = t->next;
        }
        return h;
    }
};