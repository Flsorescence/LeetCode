/**24 Swap Nodes in Pairs
 * Given a linked list, swap every two adjacent nodes and return its head.
 * You may not modify the values in the list's nodes, only nodes itself may be changed.
 * example: Given 1->2->3->4, you should return the list as 2->1->4->3.
 */
 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == 0 || head->next == 0) return head;
        ListNode **tmp = &head, *p, *q, *res = head->next;
        while((p = *tmp)&&(q = p->next)){
            p->next = q->next;
            q->next = p;
            *tmp = q;
            tmp = &(p->next);
            // cout << p->val << " " << q->val << endl;
        }
        return res;
    }
};

//递归解法
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head && head->next) {
            auto first = head;
            head = first->next;
            first->next = swapPairs(first->next->next);
            head->next = first;
        }
		return head;
    }
};