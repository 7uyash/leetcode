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
    
    TreeNode* runTree(vector<int>& preorder, vector<int>& postorder, int preStart, int preEnd, int postStart, int postEnd) {
        
        TreeNode* node = new TreeNode(preorder[preStart]);
        if (preStart == preEnd) {
            return node;
        }
        int postRight = postStart;
        while (postorder[postRight] != preorder[preStart + 1]) {
            postRight++;
        }
        int preRight = preStart + 1 + postRight - postStart;
        node->left = runTree(preorder, postorder, preStart + 1, preRight, postStart, postRight);
        preRight++;
        postRight++;
        if (postRight == postEnd) {
            return node;
        }
        node->right = runTree(preorder, postorder, preRight, preEnd, postRight, postEnd - 1);
        return node;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* root = runTree(preorder, postorder, 0, preorder.size() - 1, 0, postorder.size() - 1);
        return root;
    }
};