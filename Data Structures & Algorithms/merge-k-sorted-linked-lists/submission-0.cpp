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
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<
            ListNode*,
            vector<ListNode*>,
            Compare
        > pq;

        // Đưa node đầu tiên của mỗi list vào heap
        for (ListNode* head : lists) {
            if (head != nullptr) {
                pq.push(head);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            // Lấy node nhỏ nhất
            ListNode* cur = pq.top();
            pq.pop();

            // Nối vào kết quả
            tail->next = cur;
            tail = tail->next;

            // Đưa node tiếp theo của list đó vào heap
            if (cur->next != nullptr) {
                pq.push(cur->next);
            }
        }

        return dummy.next;
    }
};