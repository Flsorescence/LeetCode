/**83 Remove Duplicates from Sorted List
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 * Example 1:
 * Input: 1->1->2
 * Output: 1->2
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        ListNode* pre = head;
        ListNode* curr = head->next;

        while(curr != NULL){
            if(curr->val == pre->val){
                pre->next = curr->next;
                curr = pre->next;
            }else{
                pre = pre->next;
                curr = curr->next;
            }
        }
        return head;
    }
};