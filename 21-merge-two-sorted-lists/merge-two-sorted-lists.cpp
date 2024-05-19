// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) {
            return list2;
        } else if (!list2) {
            return list1;
        } else {
            if (list1->val < list2->val) {
                list1->next = mergeTwoLists(list1->next, list2);
                return list1;
            } else {
                list2->next = mergeTwoLists(list1, list2->next);
                return list2;
            }
        }
    }

    std::vector<int> toSortedArray(ListNode* head) {
        std::vector<int> result;
        ListNode* current = head;
        while (current != nullptr) {
            result.push_back(current->val);
            current = current->next;
        }
        std::sort(result.begin(), result.end());
        return result;
    }
};