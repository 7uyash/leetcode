class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long tP = n*(n-1)/2;
        long long count =0;
        unordered_map<int, int>map;
        for(int i =0; i<n; i++){
            int x = nums[i] - i;
            if(map.find(x) != map.end()){
                count+=map[x];
            }
            map[x]++;
        }
        long long res = tP - count;
        return res;
    }
};