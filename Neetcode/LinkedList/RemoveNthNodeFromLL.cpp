//https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/


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
	ListNode* removeNthFromEnd(ListNode* head, int n) {

		ListNode* slow = head;
		ListNode* fast = head;
		if (!head || !head -> next )
			return NULL;
		for (int i = 0; i < n; i++)
			fast = fast -> next;
		if (fast == NULL) {
			cout << "here" << endl;
			ListNode* temp = head;
			head = head -> next;
			temp -> next = NULL;
			//delete temp;
			return head;
		}
		//cout << fast << endl;
		while (fast -> next) {
			slow = slow -> next;
			fast = fast -> next;
		}
		ListNode* temp = slow -> next;
		slow -> next = slow -> next -> next;
		temp -> next = NULL;
		delete temp;
		return head;
	}
};