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
    ListNode* oddEvenList(ListNode* head) {
        ListNode*  odd = new ListNode(-1);
        ListNode* even = new ListNode(-1);
        ListNode* o = odd , *e = even;
        int val = 1;
        ListNode* current = head;
        while(current) {
            ListNode* next_node = current->next;
            current->next = nullptr;
            if(val%2 == 0) {
                e->next = current;
                e = current;
            } else {
                o->next = current;
                o = current;
            }
            val++;
            current = next_node;
        }
        o->next = even->next;
        ListNode* ans = odd->next;
        delete odd ;
        delete even;
        return ans;
    }
};