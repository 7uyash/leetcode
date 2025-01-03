class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long end = 0, start = 0;
        for(int i=0; i<nums.size(); i++)
            end += nums[i];
        int res = 0;
        for(int i=0; i<nums.size()-1; i++) {
            start += nums[i];
            end -= nums[i];
            if (start >= end) res++;
        }    
        return res;
    }
};