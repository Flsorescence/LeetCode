/**147 Insertion Sort List
 * Sort a linked list using insertion sort.
 * Algorithm of Insertion Sort:
 * Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
 * At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
 * It repeats until no input elements remain.
 * Example 1:
 * Input: 4->2->1->3
 * Output: 1->2->3->4
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* res = new ListNode(-1);
        while(head != NULL){
            ListNode* tmp = head->next;
            ListNode* cur = res;
            while(cur->next != NULL && cur->next->val < head->val){
                cur = cur->next;
            }
            head->next = cur->next;
            cur->next = head;
            head = tmp;
        }
        return res->next;
    }
};