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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> orgTree;
        queue<TreeNode*> newTree;
        queue<TreeNode*> evenLevelTracker;
        orgTree.push(root);
        orgTree.push(NULL);
        TreeNode* first = new TreeNode(root->val);
        TreeNode* ans = new TreeNode(0);
        ans->left = first;

        newTree.push(first);
        newTree.push(NULL);
        int row = 0;
        stack<int> stack;

        while (!orgTree.empty()) {
            TreeNode* node = orgTree.front();
            orgTree.pop();
            TreeNode* newNode = newTree.front();
            if (row % 2 == 0 && newNode != NULL) {
                evenLevelTracker.push(newNode);
            }
            newTree.pop();

            if (node == NULL) {
                if (row % 2 == 0 && !orgTree.empty()) {
                    while (!evenLevelTracker.empty()) {
                        TreeNode* cnode = evenLevelTracker.front();
                        evenLevelTracker.pop();

                        for (int z = 0; z < 2; z++) {
                            int val = stack.top();
                            TreeNode* tmp = new TreeNode(val);
                            stack.pop();

                            if (z == 0) {
                                cnode->left = tmp;
                                newTree.push(tmp);
                            } else {
                                cnode->right = tmp;
                                newTree.push(tmp);
                            }
                        }
                    }
                }

                if (!orgTree.empty()) {
                    orgTree.push(NULL);
                    newTree.push(NULL);
                }

                row++;
                continue;
            }

            if (node->left) {
                orgTree.push(node->left);
                if (row % 2 == 1) {
                    TreeNode* tmp = new TreeNode(node->left->val);
                    newNode->left = tmp;
                    newTree.push(tmp);
                } else {
                    stack.push(node->left->val);
                }
            }

            if (node->right) {
                orgTree.push(node->right);
                if (row % 2 == 1) {
                    TreeNode* tmp = new TreeNode(node->right->val);
                    newNode->right = tmp;
                    newTree.push(tmp);
                } else {
                    stack.push(node->right->val);
                }
            }
        }

        return ans->left;
    }
};