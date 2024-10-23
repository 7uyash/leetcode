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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (!root) return nullptr;
        queue<TreeNode*> q;
        q.push(root);
        
        root->val = 0;  

        while (!q.empty()) {
            int size = q.size();
            int sum_level = 0;
            vector<TreeNode*> curr_level;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                curr_level.push_back(node);

                if (node->left) {
                    q.push(node->left);
                    sum_level += node->left->val;
                }

                if (node->right) {
                    q.push(node->right);
                    sum_level += node->right->val;
                }
            }

            for (TreeNode* node : curr_level) {
                int sum_of_siblings = 0;
                if (node->left) sum_of_siblings += node->left->val;
                if (node->right) sum_of_siblings += node->right->val;
                if (node->left) node->left->val = sum_level - sum_of_siblings;
                if (node->right) node->right->val = sum_level - sum_of_siblings;
            }
        }

        return root;
    }
};

TreeNode* createBinaryTree(const vector<int>& nodes) {
    if (nodes.empty()) return nullptr;
    
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    
    for (size_t i = 1; i < nodes.size(); ) {
        TreeNode* current = q.front();
        q.pop();

        if (nodes[i] != -1) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;
        
        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}