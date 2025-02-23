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
TreeNode* fun(int r, string &s, int &i) {
        int j = i;
        int l = 0;
        while(i<s.length()){
            if(s[i] == '-') {
                l++;
            }
            else break;
            i++;
        }
        if(l != r) {
            i = j;
            return NULL;
        }
        string k;
        while(i<s.length()){
            if(s[i] != '-') k+=s[i];
            else break;
            i++;
        }
        int n = stoi(k);
        TreeNode* temp = new TreeNode(n);
        temp->left = fun(r+1, s, i);
        if(temp->left != NULL){
            temp->right = fun(r+1, s, i);
        }
        return temp;
    }

    TreeNode* recoverFromPreorder(string traversal) {
        int i =0;
        TreeNode* root = fun(0, traversal, i);
        return root;
    }
};