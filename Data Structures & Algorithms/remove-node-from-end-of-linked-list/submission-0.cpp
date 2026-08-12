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
        ListNode dummy(0, head);

        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        // Cho fast đi trước n bước
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Cùng tiến đến khi fast ở node cuối
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // slow đang đứng trước node cần xóa
        slow->next = slow->next->next;

        return dummy.next;
    }
};