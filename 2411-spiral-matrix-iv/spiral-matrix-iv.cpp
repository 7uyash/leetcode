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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>matrix(m, vector<int>(n,-1));
        if(m==0||n==0) return matrix;
        int top = 0, bottom = m-1;
        int left = 0, right = n-1;
        ListNode* current = head;
        while(top<=bottom && left <= right){
            for(int i = left; i<= right; i++){
                if(current){
                    matrix[top][i]=current->val;
                    current = current->next;

                }
            }
            top++;
            for(int i = top; i<=bottom; i++){
                if(current){
                    matrix[i][right] = current->val;
                    current = current->next;
                }
            }
            right--;
            if(top<=bottom){
                for(int i = right; i>=left; i--){
                    if(current){
                        matrix[bottom][i]= current->val;
                        current = current->next;
                    }
                }
                bottom--;
            }
            if(left<=right){
                for(int i = bottom; i>=top; i--){
                    if(current){
                        matrix[i][left]=current->val;
                        current = current->next;
                    }
                }
                left++;
            }
        }
        return matrix;

    }
};