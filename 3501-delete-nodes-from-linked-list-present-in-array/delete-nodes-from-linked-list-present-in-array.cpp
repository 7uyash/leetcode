#include <vector>
#include <unordered_set>

class Solution {  
    public:  
        ListNode* modifiedList(std::vector<int>& nums, ListNode* head) {  
            unordered_set<int>numSet(nums.begin(), nums.end());

            ListNode* dummy = new ListNode(0);
            ListNode* current = dummy;

            while(head){
                if(numSet.find(head->val)==numSet.end()){
                    current->next = head;
                    current = current->next;

                }
                head = head->next;
            }  
            current->next = nullptr;
            return dummy->next;
        }  
    };