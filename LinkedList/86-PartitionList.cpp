/**86 Partition List
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 * You should preserve the original relative order of the nodes in each of the two partitions.
 * Example:
 * Input: head = 1->4->3->2->5->2, x = 3
 * Output: 1->2->2->4->3->5
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
    ListNode* partition(ListNode* head, int x) {
        ListNode *h1 = 0, *h2 = 0, *t1 = 0, *t2 = 0;
        while(head){
            if(head->val < x){
                if(t1){
                    t1 = t1->next = head;
                }else{
                    h1 = t1 = head;
                }
            }else{
                if(t2){
                    t2 = t2->next = head;
                }else{
                    h2 = t2 = head;
                }
            }
            head = head->next;
        }
        if(h2){
            t2->next = 0;
        }
        if(h1){
            t1->next= h2;
        }
        return h1? h1: h2;
    }
};