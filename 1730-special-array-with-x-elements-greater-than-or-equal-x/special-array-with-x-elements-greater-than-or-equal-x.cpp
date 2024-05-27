class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for (int x = 0; x <= n; ++x) {
       
            int count = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] >= x) {
                    count = n - i;
                    break;
                }
            }
            if (count == x) {
                return x;
            }
        }
        return -1;
    }
};