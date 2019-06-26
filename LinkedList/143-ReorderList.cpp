/**143 Reorder List 
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 * You may not modify the values in the list's nodes, only nodes itself may be changed.
 * Example 1:
 * Given 1->2->3->4, reorder it to 1->4->2->3.
 */
 
// 一种超时的想法
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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return;
        ListNode *p = head, *q = head->next;
        while(p != NULL){
            while(q->next != NULL){
                q = q->next;
            }
            if(p->next != q){
                q->next = p->next;
                p->next = q;
                p = p->next->next;
            }
        }
    }
};

// 参考大佬的写法，先找到链表的中间节点，然后后半部分的节点依次插入前半部分中
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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return;
        ListNode *p = head, *q = head, *tmp = head;
        int count = 0;
        while(p->next){
            p = p->next;
            count++;
            if(count % 2 == 1)
                tmp = tmp->next;
        }
        
        count /= 2;
        for(int i = 0; i < count; i++){
            for(int j = 0; j < count - i - 1; j++)
                q = q->next;
            p = tmp->next;
            tmp->next = p->next;
            p->next = q->next;
            q->next = p;
            q = head;
        }
        tmp->next = NULL;
    }
};