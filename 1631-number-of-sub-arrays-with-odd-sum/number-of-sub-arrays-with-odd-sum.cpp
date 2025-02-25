class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int res = 0;
        int sum = 0;
        int mod = 1e9 + 7;
        vector<int> fr(2, 0);
        fr[0]++;
        for(int i = 0; i< arr.size(); i++){
            sum +=arr[i];
            res +=fr[!(sum%2)];
            fr[sum%2]++;
            res %=mod;

        }
        return res;
    }
};