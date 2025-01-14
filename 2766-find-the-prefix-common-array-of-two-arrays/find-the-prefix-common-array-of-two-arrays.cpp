class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> Num(A.size() + 1, 0);
        vector<int> ans;
        int count = 0;
        for (int i = 0; i < A.size(); i++) {
            if (++Num[A[i]] == 2)
                count++;
            if (++Num[B[i]] == 2)
                count++;
            ans.push_back(count);
        }
        return ans;
    }
};