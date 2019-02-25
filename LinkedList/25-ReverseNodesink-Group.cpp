/**25 Reverse Nodes in k-Group
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 * k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 * Example:
 * Given this linked list: 1->2->3->4->5
 * For k = 2, you should return: 2->1->4->3->5
 * For k = 3, you should return: 3->2->1->4->5
 * Note:
 * Only constant extra memory is allowed.
 * You may not alter the values in the list's nodes, only nodes itself may be changed.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k <= 1 || head == 0) return head;
        stack<ListNode*> s;
        int count = 0;
        ListNode *res = head, *t1 = 0, *t2 = 0;
        while(head){
            if(count == 0) t2 = head;
            s.push(head);
            count++;
            head = head->next;
            if(count == k){
                while(!s.empty()){
                    if(t1){
                        t1->next = s.top();
                        s.pop();
                        t1 = t1->next;
                    }else{
                        t1 = s.top();
                        s.pop();
                        res = t1;
                    }
                    
                }
                count = 0;
            }
        }
        if(count != 0){
            if(t1) t1->next = t2;
            else t1 = t2;
        }
        else t1->next = 0;
        return res;
    }
};