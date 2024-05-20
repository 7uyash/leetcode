class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
    int total_sum = 0;
    int n = nums.size();
    for (int i = 0; i < (1 << n); ++i) {  // 1 << n is 2^n, represents all subsets
        int subset_xor = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {  // Check if j-th element is included in the subset
                subset_xor ^= nums[j];
            }
        }
        total_sum += subset_xor;
    }
    return total_sum;
}
};