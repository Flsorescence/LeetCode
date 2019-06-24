/**141 Linked List Cycle
 * Given a linked list, determine if it has a cycle in it.
 * To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.
 * Example 1:
 * Input: head = [3,2,0,-4], pos = 1
 * Output: true
 * Explanation: There is a cycle in the linked list, where tail connects to the second node.
 */
 
// 设置快慢指针，如果两个指针最终相遇则必存在环
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
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        ListNode *quick = head, *slow = head;
        while(quick != NULL){
            quick = quick->next;
            if(quick != NULL) quick = quick->next;
            slow = slow->next;
            
            if(quick == slow && quick != NULL){
                return true;
            }
        }
        return false;
    }
};

// 简洁版
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        ListNode *quick = head, *slow = head;
        while(quick != NULL && slow != NULL && quick->next != NULL){
            quick = quick->next->next;
            slow = slow->next;
            if(quick == slow) return true;
        }
        return false;
    }
};