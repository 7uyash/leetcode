class Solution {
public:
    int beautifulSubsets(std::vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int count = 0;


        backtrack(nums, k, 0, freq, count);

        return count;
    }

private:
    void backtrack(const vector<int>& nums, int k, int start, unordered_map<int, int>& freq, int& count) {
        if (start == nums.size()) {
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            int num = nums[i];


            if (freq[num + k] == 0 && freq[num - k] == 0) {
                freq[num]++;
                count++;

                backtrack(nums, k, i + 1, freq, count);


                freq[num]--;
            }
        }
    }
};