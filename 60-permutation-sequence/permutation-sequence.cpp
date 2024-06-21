class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for (int i = 1; i <= n; ++i) {
            nums.push_back(i);
        }
      
        vector<int> factorial(n + 1, 1);
        for (int i = 2; i <= n; ++i) {
            factorial[i] = factorial[i - 1] * i;
        }
        

        k--;
       
        string result;
        for (int i = 1; i <= n; ++i) {
            int index = k / factorial[n - i];
            result += to_string(nums[index]);
            nums.erase(nums.begin() + index);
             k -= index * factorial[n - i];
        }
        
        return result;
    }
};