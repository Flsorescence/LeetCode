/**82 Remove Duplicates from Sorted List II
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 * Example 1:
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
 */
 
 
// 遍历两次，第一次记录那些值是重复的，第二次把非重复的值添加到新建的链表中，缺点是内存开销大
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;
        map<int, int> flag;
        while(p != NULL){
            flag[p->val]++;
            p = p->next;
        }
        
        p = head;
        ListNode* q = new ListNode(-1);
        ListNode* res = q;
        while(p != NULL){
            if(flag[p->val] == 1){
                ListNode* tmp = new ListNode(p->val);
                q->next = tmp;
                q = q->next;
            }
            p = p->next;
        }
        return res->next;
    }
};