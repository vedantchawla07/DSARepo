/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // ListNode* temp2 = NULL;
    // ListNode* rev(ListNode* curr){
    //     if(curr -> next == NULL){
    //         temp2 = curr;
    //         return curr;
    //     }
    //     rev(curr-> next)->next = curr;
    //     return curr;
    // }
    // ListNode* reverseList(ListNode* head) {
    //     if(head == NULL)
    //         return NULL;
    //     ListNode* temp = rev(head);
    //     temp->next = NULL;
    //     return temp2;
    // }
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* temp = curr -> next;
            curr-> next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};