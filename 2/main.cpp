struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		int exceed = 0;
		ListNode* head = new ListNode();
		ListNode* current = head;

		while (l1 != nullptr || l2 != nullptr) {

			int sum = exceed;

			if (l1 != nullptr) {
				sum += l1->val;
				l1 = l1->next;
			}

			if (l2 != nullptr) {
				sum += l2->val;
				l2 = l2->next;
			}

			exceed = sum / 10;
			sum %= 10;

			current->next = new ListNode(sum);
			current = current->next;

		}

		if (exceed > 0) {
			current->next = new ListNode(exceed);
		}

		return head->next;

	}

};