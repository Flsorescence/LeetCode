/**206 Reverse Linked List
 * Reverse a singly linked list.
 * Example:
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 */
 
//1.迭代 
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
    ListNode* reverseList(ListNode* head) {
        ListNode *res = 0;
        while(head){
            ListNode *tmp = head->next;
            head->next = res;
            res = head;
            head = tmp;
        }
        return res;
    }
};

//2.递归
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
    ListNode* reverseList(ListNode* head) {
        if(head == 0|| head->next == 0) return head;
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = 0;
        return p;
    }
};