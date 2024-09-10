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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head){
            return nullptr;
        }
        ListNode* current = head;
        while(current && current->next){
            int gcdValue = gcd(current->val, current->next->val);
            ListNode* newNode = new ListNode(gcdValue);
            newNode->next= current->next;
            current->next = newNode;
            current = newNode->next;
        }
        return head;
    }
    int gcd(int a, int b){
        while(b!=0){
            int temp = b;
            b= a%b;
            a= temp;
        }
        return a;
    }
};