class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int element = nums[0];
        int count = 1;
        for (int i = 0; i < n; i++) {
            if (count == 0) {
                count = 1;
                element = nums[i];
            } else if (element == nums[i])
                count+=1;
            else if (element != nums[i])
                count-=1;
        }

        count = 0;
        for (int num : nums) {
            if (num == element)
                count+=1;
        }

        int currentCount = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] == element)
                ++currentCount;
            if (currentCount > (j + 1) / 2) {
                if ((count - currentCount) > ((n - j - 1) / 2)) {
                    return j;
                }
            }
        }
        return -1;
    }
};