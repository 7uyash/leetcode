class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        
        int mxLeft = values[0] + 0;
        int res = INT_MIN;
        for(int j = 1; j < n; j++){
            res = max(res, mxLeft + values[j] - j);
            mxLeft = max(mxLeft, values[j] + j);
        }
        
        return res;
    }
};