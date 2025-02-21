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
class FindElements {
public:
    unordered_map<int,int> mpp;

    void solve(TreeNode* node, int exp){
        if(!node){return;}
        if(node->val==-1){node->val=exp;}
        mpp[node->val]++;
        if(node->left){
            solve(node->left,2*exp+1);
        }
        if(node->right){
            solve(node->right,2*exp+2);
        }
    }

public:
    FindElements(TreeNode* root) {
        mpp.clear();
        solve(root,0);
    }
    
    bool find(int target) {
        return mpp.find(target)!=mpp.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */