/**61 Rotate List
 * Given a linked list, rotate the list to the right by k places, where k is non-negative.
 * example:
 * Input: 1->2->3->4->5->NULL, k = 2
 * Output: 4->5->1->2->3->NULL
 * Explanation:
 * rotate 1 steps to the right: 5->1->2->3->4->NULL
 * rotate 2 steps to the right: 4->5->1->2->3->NULL
 */
 
 
// 简单模拟
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == 0 || k == 0)
            return head;
        ListNode* p = new ListNode(-1);
        p->next = head;
        ListNode* tmp = head;
        int len = 0;
        while(tmp != 0) {
            len++;
            tmp = tmp->next;
        }
        // cout << len << endl;
        int l = len - k % len;
        if(len == 1 || l == len)
            return head;
        tmp = head;
        for(int i = 1; i < l; i++) tmp = tmp->next;
        ListNode* q = tmp->next;
        tmp->next = NULL;
        p->next = q;
        while(q->next != 0) q = q->next;
        q->next = head;
        return p->next;
    }
};