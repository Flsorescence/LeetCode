/**92 Reverse Linked List II
 * Reverse a linked list from position m to n. Do it in one-pass.
 * Note: 1 ≤ m ≤ n ≤ length of list.
 * Example:
 * Input: 1->2->3->4->5->NULL, m = 2, n = 4
 * Output: 1->4->3->2->5->NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        stack<ListNode*> s;
        ListNode *res = head, *t1 = 0, *t2;
        for(int i = 1; i <= n; i++){
            if(i == m-1) t1 = head;
            if(i >= m) s.push(head);
            head = head->next;
        }
        t2 = head;
        if(t1 == 0){
            t1 = s.top();
            s.pop();
            res = t1;
        }
        while(!s.empty()){
            t1->next = s.top();
            s.pop();
            t1 = t1->next;
        }
        t1->next = t2;
        return res;
    }
};