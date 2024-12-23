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
private:
int binarysearch(const vector<int>& temparr,int num){
    int low=0;
    int high=temparr.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(temparr[mid]==num){
            return mid;
        }
        else if(temparr[mid]>num){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
        
    }
    return -1;
}
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            vector<int> arr;
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left){
                    arr.push_back(curr->left->val);
                    q.push(curr->left);
                }
                if(curr->right){
                    arr.push_back(curr->right->val);
                    q.push(curr->right);
                }
            }
            vector<int> temparr=arr;
            sort(temparr.begin(),temparr.end());
            // for(int i : arr){
            //     cout<<i<<" ";
            // }
            //cout<<"\n";
            for(int i=0;i<arr.size();i++){
            while(arr[i]!=temparr[i]){
                int idx=binarysearch(temparr,arr[i]);
                if(idx>=0 && idx<temparr.size())
                swap(arr[i],arr[idx]);
                ans++;
            }
            }
        }
return ans;
    }
};