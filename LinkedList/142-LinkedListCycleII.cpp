/**142 Linked List Cycle II
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 * To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.
 * Note: Do not modify the linked list.
 * Example 1:
 * Input: head = [3,2,0,-4], pos = 1
 * Output: tail connects to node index 1
 * Explanation: There is a cycle in the linked list, where tail connects to the second node.
 */
 
// 快慢指针法，当第一次相遇后，使其中一个指针指向head，然后两个指针按相同步长开始移动直到第二次相遇，当前点即为环的入口
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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode *quick = head, *slow = head;
        while(true){
            if(quick == NULL || quick->next == NULL || slow == NULL) return NULL;
            slow = slow->next;
            quick = quick->next->next;
            if(quick == slow) break;
        }
        
        quick = head;
        while(quick != slow){
            quick = quick->next;
            slow = slow->next;
        }
        return quick;
    }
};