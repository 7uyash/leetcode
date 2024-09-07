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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!head) return true; 
        if (!root) return false;
        return dfs(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }

private:
    bool dfs(TreeNode* node, ListNode* listNode) {
        if (!listNode) return true;
        if (!node) return false; 
        if (node->val != listNode->val) return false; 
        return dfs(node->left, listNode->next) || dfs(node->right, listNode->next);
    }
};
