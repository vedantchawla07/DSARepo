#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	/**
	 * Definition for singly-linked list.*/
	//https://leetcode.com/problems/reorder-list/description/

	struct ListNode {
		int val;
		ListNode *next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode *next) : val(x), next(next) {}
	};

	class Solution {
	public:
		void reorderList(ListNode* head) {

			stack<ListNode*> st;
			ListNode* curr = head;
			while (curr) {
				st.push(curr);
				curr = curr -> next;
			}
			curr = head;
			ListNode* curr_next = curr -> next;
			while (curr != st.top() && curr_next != st.top()) {
				curr -> next = st.top();
				st.top() -> next = curr_next;
				st.pop();
				curr = curr_next;
				curr_next = curr_next -> next;
			}
			if (curr == st.top())
				curr -> next = NULL;
			else if (curr_next == st.top())
				curr_next -> next = NULL;


		}
	};

	int main() {

		int n;
		cin >> n;
		vector<int> nums(n);
		for (int i = 0; i < n; i++) {
			cin >> nums[i];
		}
		Solution obj;
		int ans;
		ans = obj.calledFunction(nums);
		cout << ans << endl;
		return 0;


	}