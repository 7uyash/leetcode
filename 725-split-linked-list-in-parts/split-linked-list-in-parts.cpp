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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length = 0;
        ListNode* current = head;
        while(current){
            length++;
            current = current->next;

        }
        int partSize = length/k;
        int extraParts = length%k;
        vector<ListNode*>parts(k, nullptr);
        current = head;
        for(int i = 0; i<k; ++i){
            ListNode* partHead = current;
            int currentPartSize = partSize +(i<extraParts?1: 0);

            for(int j =0; j<currentPartSize-1; ++j){
                if(current){
                    current = current->next;

                }
            }
            if(current){
                ListNode* nextPartHead = current->next;
                current-> next = nullptr;
                current = nextPartHead;
            }
            parts[i]=partHead;
        }
        return parts;
    }
};