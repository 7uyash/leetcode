class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int a = 0;
        int sum = 0;
        a=n*(n+1)/2;
        for(int i = 0; i<n; i++){
            sum+=arr[i];
        }
        int res = a-sum;
        return res;
        
    }
};