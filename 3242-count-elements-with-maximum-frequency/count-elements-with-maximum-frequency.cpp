class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int num : nums){
            freq[num]++;
        }

        int maxi = INT_MIN;

        for(auto &pair : freq){
            int frequency = pair.second;
            if(maxi < frequency){
                maxi = frequency;
            }
        }

        vector<int> ans;
        int count = 0;
        for(auto &pair : freq){
            int element = pair.first;
            int frequency = pair.second;
            if(maxi == frequency){
                maxi = frequency;
                ans.push_back(element);
            }
        }

        for (int i = 0; i < ans.size(); i++){
            for (int j = 0; j < nums.size(); j++){
                if(ans[i] == nums[j]){
                count++;
                }
            }
        }

        return count;
    }
};