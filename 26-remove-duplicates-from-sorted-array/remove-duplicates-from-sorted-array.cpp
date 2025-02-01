class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int i = 0;

        // Iterate through the vector starting from index 1
        for (int j = 1; j < nums.size(); j++) {
            // If the current element at j is different from the element at i
            if (nums[j] != nums[i]) {
                // Move pointer i forward
                i++;
                // Store the new unique element at the next position
                nums[i] = nums[j];
            }
        }
        // The number of unique elements is (i + 1)
        return i + 1;
        
    }
};