class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       auto newEnd = remove(nums.begin(), nums.end(), 0);
       size_t countZeros = distance(newEnd, nums.end());
       nums.erase(newEnd, nums.end());
       nums.resize(nums.size()+ countZeros, 0);
       
        
    }
};