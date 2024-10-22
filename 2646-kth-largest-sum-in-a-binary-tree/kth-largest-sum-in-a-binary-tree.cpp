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
    long long kthLargestLevelSum(TreeNode* root, int k) {
       if(!root) return -1;
       vector<long long>levelSum;
       queue<TreeNode*>q;
       q.push(root);

       while(!q.empty()){
        int levelSize = q.size();
        long long currentLevelSum = 0;
        for(int i =0; i<levelSize; i++){
            TreeNode* node = q.front();
            q.pop();
            currentLevelSum += node->val;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);

        }
        levelSum.push_back(currentLevelSum);
       } 
       sort(levelSum.rbegin(), levelSum.rend());
       if(k>levelSum.size()) return -1;

       return levelSum[k-1];
    }
};