/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
            return nullptr;

        unordered_map<Node*, Node*> mp;

        // Bước 1: Tạo node mới tương ứng với từng node cũ
        Node* cur = head;

        while (cur != nullptr) {
            mp[cur] = new Node(cur->val);
            cur = cur->next;
        }

        // Bước 2: Nối next và random
        cur = head;

        while (cur != nullptr) {
            mp[cur]->next = mp[cur->next];

            if (cur->random != nullptr)
                mp[cur]->random = mp[cur->random];
            else
                mp[cur]->random = nullptr;

            cur = cur->next;
        }

        return mp[head];
    }
};